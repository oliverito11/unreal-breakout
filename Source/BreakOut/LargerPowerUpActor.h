// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PowerUpActor.h"
#include "LargerPowerUpActor.generated.h"

class APlayerPlatformActor;
/**
 * 
 */
UCLASS()
class BREAKOUT_API ALargerPowerUpActor : public APowerUpActor
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere)
	APlayerPlatformActor *PlayerPlatformActor;

	UPROPERTY(EditAnywhere)
	float ScaleFactorMultiplier;

protected:
	virtual void AddPowerUp() override;
	virtual void RemovePowerUp() override;
};
