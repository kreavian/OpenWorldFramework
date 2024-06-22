// Copyright Kreavian

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "OpenWorldFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class OPENWORLDFRAMEWORK_API UOpenWorldFunctionLibrary : public UBlueprintFunctionLibrary {
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Open World Framework Function Library")
	static TArray<TSoftObjectPtr<USoundClass>> GetOpenWorldDefaultSoundClasses();

	UFUNCTION(BlueprintCallable, Category = "Open World Framework Function Library")
	static void SetOpenWorldSoundClassVolume(USoundClass* TargetClass, float NewVolume);
};
