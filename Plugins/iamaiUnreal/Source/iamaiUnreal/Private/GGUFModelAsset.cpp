#include "GGUFModelAsset.h"

#include "Misc/Paths.h"

void UGGUFModelAsset::BeginDestroy() {

	Super::BeginDestroy();

	if (FilePath.IsEmpty()) return;
	FString FullPath = FPaths::ProjectDir() / FilePath;

	if (FPaths::FileExists(FullPath)) {

		IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
		PlatformFile.DeleteFile(*FullPath);

	}

}
