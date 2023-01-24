// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PowerUpActor.h"
#include "DoubleBallPowerUpActor.generated.h"

class ABallActor;
/**
 * 
 */
UCLASS()
class BREAKOUT_API ADoubleBallPowerUpActor : public APowerUpActor
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere)
	ABallActor *BallActor;
protected:
	virtual void AddPowerUp() override;
	virtual void RemovePowerUp() override;
};
