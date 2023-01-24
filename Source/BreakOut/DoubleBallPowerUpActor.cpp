// Fill out your copyright notice in the Description page of Project Settings.


#include "DoubleBallPowerUpActor.h"

#include "BallActor.h"
#include "BreakOutGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void ADoubleBallPowerUpActor::AddPowerUp()
{
	Super::AddPowerUp();
	
	ABreakOutGameModeBase *GameMode = Cast<ABreakOutGameModeBase>(UGameplayStatics::GetGameMode(this));
	if(!GameMode) return;

	GameMode->AddPlayerLive();
	BallActor = GameMode->SpawnNewBall();
}

void ADoubleBallPowerUpActor::RemovePowerUp()
{
	BallActor->Destroy();
}
