#pragma once
#include "CoreMinimal.h"
#include "Configuration/ConfigManager.h"
#include "Engine/Engine.h"
#include "Shuffler_ConfigurationStruct.generated.h"

/* Struct generated from Mod Configuration Asset '/NodeLocationShuffler/Shuffler_Configuration' */
USTRUCT(BlueprintType)
struct FShuffler_ConfigurationStruct {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    int32 seed;

    /* Retrieves active configuration value and returns object of this struct containing it */
    static FShuffler_ConfigurationStruct GetActiveConfig() {
        FShuffler_ConfigurationStruct ConfigStruct{};
        FConfigId ConfigId{"OreLocationShufflerMod", ""};
        UConfigManager* ConfigManager = GEngine->GetEngineSubsystem<UConfigManager>();
        ConfigManager->FillConfigurationStruct(ConfigId, FDynamicStructInfo{FShuffler_ConfigurationStruct::StaticStruct(), &ConfigStruct});
        return ConfigStruct;
    }
};

