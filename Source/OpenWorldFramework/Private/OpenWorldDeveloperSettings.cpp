// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenWorldDeveloperSettings.h"

TSoftObjectPtr<UWorld> UOpenWorldDeveloperSettings::GetDefaultOpenWorldMenuMapRef() const {
	TSoftObjectPtr<UWorld> NewWorld;
	NewWorld = DefaultMenuMap;
	return NewWorld;
}

TSoftObjectPtr<UWorld> UOpenWorldDeveloperSettings::GetDefaultOpenWorldStarterGameMapRef() const {
	TSoftObjectPtr<UWorld> NewWorld;
	NewWorld = DefaultStarterGameMap;
	return NewWorld;
}
