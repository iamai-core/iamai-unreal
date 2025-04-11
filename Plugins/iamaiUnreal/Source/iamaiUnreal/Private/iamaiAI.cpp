#include "iamaiAI.h"

iamaiAI::iamaiAI(const std::string& modelName) {

    // Get the Unreal Engine project directory
    FString ProjectDirFString = FPaths::ProjectDir();
    FString PluginDirFString = FPaths::Combine(ProjectDirFString, TEXT("Plugins"), TEXT("iamaiUnreal"));
    FString DllDirectoryFString = FPaths::Combine(PluginDirFString, TEXT("ThirdParty"));
    FString DllPathFString = FPaths::Combine(DllDirectoryFString, TEXT("iamai-core.dll"));
    FString ModelPathFString = FPaths::Combine(PluginDirFString, TEXT("Models"), *FString(modelName.c_str()));

    // Convert to standard strings
    std::string dllDirectory = TCHAR_TO_UTF8(*DllDirectoryFString);
    std::string dllPath = TCHAR_TO_UTF8(*DllPathFString);
    std::string modelPath = TCHAR_TO_UTF8(*ModelPathFString);

    if (!std::filesystem::exists(dllDirectory)) {
        throw std::runtime_error("DLL directory not found: " + dllDirectory);
    }

    std::cout << "Loading DLL from: " << dllPath << std::endl;
    SetDllDirectoryA(dllDirectory.c_str());

    // Load the iamai-core DLL
    DllHandle = LoadLibraryA(dllPath.c_str());
    if (!DllHandle) {
        int errorCode = GetLastError();
        throw std::runtime_error("Failed to load iamai-core DLL. Error code: " + std::to_string(errorCode));
    }

    // Get iamai-core function pointers
    _init = GetFunction<InitFunction>("Init");
    _generate = GetFunction<GenerateFunction>("Generate");
    _setMaxTokens = GetFunction<SetMaxTokensFunction>("SetMaxTokens");
    _setThreads = GetFunction<SetThreadsFunction>("SetThreads");
    _setBatchSize = GetFunction<SetBatchSizeFunction>("SetBatchSize");
    _free = GetFunction<FreeFunction>("Free");

    // Initialize the model
    ctx = _init(modelPath.c_str());
    if (!ctx) {
        throw std::runtime_error("Failed to initialize iamai model");
    }

}

std::string iamaiAI::Generate(const std::string& prompt, int maxLength) {

    std::unique_ptr<char[]> output(new char[maxLength]);
    bool success = _generate(ctx, prompt.c_str(), output.get(), maxLength);

    if (!success) {
        throw std::runtime_error("Generation failed");
    }

    return std::string(output.get());

}

iamaiAI::~iamaiAI() {

    if (!disposed) {

        if (ctx) {
            _free(ctx);
            ctx = nullptr;
        }

        if (DllHandle) {
            FreeLibrary(DllHandle);
            DllHandle = nullptr;
        }

        disposed = true;

    }

}

