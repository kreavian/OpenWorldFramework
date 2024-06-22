// Copyright Kreavian

#include "OpenWorldGameUserSettings.h"

void UOpenWorldGameUserSettings::SetToDefaults() {
	Super::SetToDefaults();

	YSensitivity = 1.f;
	XSensitivity = 1.f;
	bInvertY = false;
	bToggleSprint = true;
	MotionBlurQuality = false;
	Gamma = 2.2f;
}

FVector2D UOpenWorldGameUserSettings::GetAxisSensitivity() const {
	return FVector2D(XSensitivity, YSensitivity);
}

void UOpenWorldGameUserSettings::SetAxisSensitivity(const FVector2D AxisSensitivity) {
	XSensitivity = AxisSensitivity.X;
	YSensitivity = AxisSensitivity.Y;
}

bool UOpenWorldGameUserSettings::GetIsYAxisInverted() const {
	return bInvertY;
}

void UOpenWorldGameUserSettings::SetYAxisInverted(const bool bInYinverted) {
	bInvertY = bInYinverted;
}

bool UOpenWorldGameUserSettings::GetToggleSprint() const {
	return bToggleSprint;
}

void UOpenWorldGameUserSettings::SetToggleSprint(const bool bInToggleSprint) {
	bToggleSprint = bInToggleSprint;
}

TArray<float> UOpenWorldGameUserSettings::GetAudioVolumeLevels() const {
	return AudioVolumeLevels;
}

void UOpenWorldGameUserSettings::SetAudioVolumeLevels(const TArray<float>& InAudioLevels) {
	AudioVolumeLevels = InAudioLevels;
}

bool UOpenWorldGameUserSettings::GetMotionBlurQuality() const {
	return MotionBlurQuality;
}

void UOpenWorldGameUserSettings::SetMotionBlurQuality(const bool bInMotionBlurQuality) {
	MotionBlurQuality = bInMotionBlurQuality;
}

float UOpenWorldGameUserSettings::GetGamma() const {
	return Gamma;
}

void UOpenWorldGameUserSettings::SetGamma(const float InGamma) {
	Gamma = InGamma;
}

UOpenWorldGameUserSettings* UOpenWorldGameUserSettings::GetOpenWorldGameUserSettings() {
	return Cast<UOpenWorldGameUserSettings>(GEngine->GetGameUserSettings());
}

void UOpenWorldGameUserSettings::ApplySettings(const bool bCheckForCommandLineOverrides) {
	Super::ApplySettings(bCheckForCommandLineOverrides);
	OnGameSettingsApplied.Broadcast();
	BPApplySettings();
}

void UOpenWorldGameUserSettings::BPApplySettings_Implementation() {
}

