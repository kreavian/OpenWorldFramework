// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DeveloperSettings.h"
#include "OpenWorldDeveloperSettings.generated.h"

/**
 * 
 */
UCLASS(config = Plugins, Defaultconfig, meta = (DisplayName = "Open World Framework Settings"))
class OPENWORLDFRAMEWORK_API UOpenWorldDeveloperSettings : public UDeveloperSettings {
	GENERATED_BODY()

public:
	FName GetDefaultOpenWorldMenuMap() const { return DefaultMenuMapName; }
	FName GetDefaultOpenWorldStarterGameMap() const { return DefaultNewGameMapName; }
	TArray<FSoftObjectPath> GetDefaultOpenWorldSoundClasses() const { return DefaultSoundClasses; }
	TSoftObjectPtr<UWorld> GetDefaultOpenWorldMenuMapRef() const;
	TSoftObjectPtr<UWorld> GetDefaultOpenWorldStarterGameMapRef() const;

protected:
	UPROPERTY(config, EditAnywhere, Category = "Default Maps")
	FName DefaultMenuMapName;

	UPROPERTY(config, EditAnywhere, Category = "Default Maps")
	FName DefaultNewGameMapName;

	UPROPERTY(config, EditAnywhere, Category = "Default Maps", meta=(AllowedClasses="/Script/Engine.World"))
	FSoftObjectPath DefaultMenuMap;

	UPROPERTY(config, EditAnywhere, Category = "Default Maps", meta=(AllowedClasses="/Script/Engine.World"))
	FSoftObjectPath DefaultStarterGameMap;

	UPROPERTY(config, EditAnywhere, Category = "Default Maps", meta=(AllowedClasses="/Script/Engine.SoundClass"))
	TArray<FSoftObjectPath> DefaultSoundClasses;
};
