// Copyright Kreavian

#include "OpenWorldFunctionLibrary.h"

#include "Engine/Engine.h"
#include "Sound/SoundClass.h"
#include "OpenWorldDeveloperSettings.h"

TArray<TSoftObjectPtr<USoundClass>> UOpenWorldFunctionLibrary::GetOpenWorldDefaultSoundClasses() {
	const UOpenWorldDeveloperSettings* Settings = GetMutableDefault<UOpenWorldDeveloperSettings>();
	TArray<TSoftObjectPtr<USoundClass>> OutSounds;
	const TArray<FSoftObjectPath> softPtrs = Settings->GetDefaultOpenWorldSoundClasses();

	for (FSoftObjectPath SoundClass : softPtrs) {
		OutSounds.Add(SoundClass.TryLoad());
	}
	return OutSounds;
}

void UOpenWorldFunctionLibrary::SetOpenWorldSoundClassVolume(USoundClass* TargetClass, float NewVolume) {
	if (!TargetClass) {
		return;
	}
	TargetClass->Properties.Volume = NewVolume;
}
