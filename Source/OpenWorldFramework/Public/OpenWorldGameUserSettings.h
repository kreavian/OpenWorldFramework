// Copyright Kreavian

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "OpenWorldGameUserSettings.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnOpenWorldFrameworkSettingsApplied);

UCLASS(BlueprintType, Blueprintable)
class OPENWORLDFRAMEWORK_API UOpenWorldGameUserSettings : public UGameUserSettings {
	GENERATED_BODY()

public:
	virtual void SetToDefaults() override;

	UPROPERTY(BlueprintAssignable, Category = "Open World Framework | GameUserSettings")
	FOnOpenWorldFrameworkSettingsApplied OnGameSettingsApplied;

	/*CONTROLS*/
	
	/*Gets Mouse and Gamepad Sensitivity*/
	UFUNCTION(BlueprintPure, Category = "Open World Framework | GameUserSettings")
	FVector2D GetAxisSensitivity() const;

	/*Sets Mouse and Gamepad Sensitivity*/
	UFUNCTION(BlueprintCallable, Category = "Open World Framework | GameUserSettings")
	void SetAxisSensitivity(const FVector2D AxisSensitivity);

	/*Gets if Y axis should be inverted*/
	UFUNCTION(BlueprintPure, Category = "Open World Framework | GameUserSettings")
	bool GetIsYAxisInverted() const;

	/*Sets if Y axis should be inverted*/
	UFUNCTION(BlueprintCallable, Category = "Open World Framework | GameUserSettings")
	void SetYAxisInverted(const bool bInYinverted);

	UFUNCTION(BlueprintPure, Category = Settings)
	bool GetToggleSprint() const;

	UFUNCTION(BlueprintCallable, Category = Settings)
	void SetToggleSprint(const bool bInToggleSprint);

	/*AUDIO*/
	
	/*Gets An Array of volumes for audio channels*/
	UFUNCTION(BlueprintPure, Category = "Open World Framework | GameUserSettings")
	TArray<float> GetAudioVolumeLevels() const;

	/*Sets An Array of volumes for audio channels*/
	UFUNCTION(BlueprintCallable, Category = "Open World Framework | GameUserSettings")
	void SetAudioVolumeLevels(const TArray<float>& InAudioLevels);

	/*VIDEO*/

	/*Get Motion Blur Quality*/
	UFUNCTION(BlueprintPure, Category = "Open World Framework | GameUserSettings")
	bool GetMotionBlurQuality() const;

	/*Set Motion Blur Quality*/
	UFUNCTION(BlueprintCallable, Category = "Open World Framework | GameUserSettings")
	void SetMotionBlurQuality(const bool bInMotionBlurQuality);

	/*Get Gamma*/
	UFUNCTION(BlueprintPure, Category = "Open World Framework | GameUserSettings")
	float GetGamma() const;

	/*Set Gamma*/
	UFUNCTION(BlueprintCallable, Category = "Open World Framework | GameUserSettings")
	void SetGamma(const float InGamma);

	/*BLUEPRINT FUNCTIONS*/

	/*Get Open World Framework GameUserSettings which is a child of GameUserSettings*/
	UFUNCTION(BlueprintCallable, Category = "Open World Framework | GameUserSettings")
	static UOpenWorldGameUserSettings* GetOpenWorldGameUserSettings();

protected:
	virtual void ApplySettings(const bool bCheckForCommandLineOverrides) override;

	/*CONTROLS*/

	UPROPERTY(config)
	float XSensitivity;

	UPROPERTY(config)
	float YSensitivity;

	UPROPERTY(config)
	bool bInvertY;

	UPROPERTY(config)
	bool bToggleSprint;

	/*AUDIO*/
	
	UPROPERTY(config)
	TArray<float> AudioVolumeLevels;

	/*VIDEO*/
	UPROPERTY(config)
	bool MotionBlurQuality;

	UPROPERTY(config)
	float Gamma;
	

	/*BLUEPRINT EVENTS*/

	UFUNCTION(BlueprintNativeEvent, Category = "Open World Framework | GameUserSettings")
	void BPApplySettings();
};
