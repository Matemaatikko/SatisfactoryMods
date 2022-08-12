#pragma once
#include "CoreMinimal.h"
#include "Configuration/ConfigManager.h"
#include "Engine/Engine.h"
#include "ShufflerConfigurationStruct.generated.h"

/* Struct generated from Mod Configuration Asset '/OreDepositLocationRandomizer/ShufflerConfiguration' */
USTRUCT(BlueprintType)
struct FShufflerConfigurationStruct {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite)
    int32 seed;

    /* Retrieves active configuration value and returns object of this struct containing it */
    static FShufflerConfigurationStruct GetActiveConfig() {
        FShufflerConfigurationStruct ConfigStruct{};
        FConfigId ConfigId{"OreLocationShufflerMod", ""};
        UConfigManager* ConfigManager = GEngine->GetEngineSubsystem<UConfigManager>();
        ConfigManager->FillConfigurationStruct(ConfigId, FDynamicStructInfo{FShufflerConfigurationStruct::StaticStruct(), &ConfigStruct});
        return ConfigStruct;
    }
};

