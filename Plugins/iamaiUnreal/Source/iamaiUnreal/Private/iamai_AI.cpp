#include "iamai_AI.h"

iamai_AI::iamai_AI(const std::string& modelName) {

    // Get the Unreal Engine project directory
    FString ProjectDirFString = FPaths::ProjectDir();
    FString PluginDirFString = FPaths::Combine(ProjectDirFString, TEXT("Plugins"), TEXT("iamaiUnreal"));
    FString DllDirectoryFString = FPaths::Combine(PluginDirFString, TEXT("ThirdParty"));
    FString IamaiDllPathFString = FPaths::Combine(DllDirectoryFString, TEXT("iamai-core.dll"));
    FString ModelPathFString = FPaths::Combine(PluginDirFString, TEXT("Models"), *FString(modelName.c_str()));

    // Convert to standard strings
    std::string dllDirectory = TCHAR_TO_UTF8(*DllDirectoryFString);
    std::string iamaiDllPath = TCHAR_TO_UTF8(*IamaiDllPathFString);
    std::string modelPath = TCHAR_TO_UTF8(*ModelPathFString);

    if (!fs::exists(dllDirectory)) {
        throw std::runtime_error("DLL directory not found: " + dllDirectory);
    }

    std::cout << "Loading DLL from: " << iamaiDllPath << std::endl;
    SetDllDirectoryA(dllDirectory.c_str());

    // Load the iamai-core DLL
    iamaiDllHandle = LoadLibraryA(iamaiDllPath.c_str());
    if (!iamaiDllHandle) {
        int errorCode = GetLastError();
        throw std::runtime_error("Failed to load iamai-core DLL. Error code: " + std::to_string(errorCode));
    }

    // Get iamai-core function pointers
    _init = GetFunction<InitFunction>(iamaiDllHandle, "Init");
    _generate = GetFunction<GenerateFunction>(iamaiDllHandle, "Generate");
    _setMaxTokens = GetFunction<SetMaxTokensFunction>(iamaiDllHandle, "SetMaxTokens");
    _setThreads = GetFunction<SetThreadsFunction>(iamaiDllHandle, "SetThreads");
    _setBatchSize = GetFunction<SetBatchSizeFunction>(iamaiDllHandle, "SetBatchSize");
    _free = GetFunction<FreeFunction>(iamaiDllHandle, "Free");

    // Initialize the model
    ctx = _init(modelPath.c_str());
    if (!ctx) {
        throw std::runtime_error("Failed to initialize model");
    }

}

std::string iamai_AI::Generate(const std::string& prompt, int maxLength) {

    std::unique_ptr<char[]> output(new char[maxLength]);
    bool success = _generate(ctx, prompt.c_str(), output.get(), maxLength);

    if (!success) {
        throw std::runtime_error("Generation failed");
    }

    return std::string(output.get());

}

iamai_AI::~iamai_AI() {

    if (!disposed) {

        if (ctx) {
            _free(ctx);
            ctx = nullptr;
        }

        if (iamaiDllHandle) {
            FreeLibrary(iamaiDllHandle);
            iamaiDllHandle = nullptr;
        }

        disposed = true;

    }

}

