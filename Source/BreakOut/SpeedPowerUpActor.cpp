// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedPowerUpActor.h"

#include "BreakOutPlayerPawn.h"
#include "PlayerPlatformActor.h"
#include "GameFramework/PlayerState.h"

void ASpeedPowerUpActor::AddPowerUp()
{
	Super::AddPowerUp();

	const ABreakOutPlayerPawn *PlayerPawn = Cast<ABreakOutPlayerPawn>(GetWorld()->GetFirstPlayerController()->GetPlayerState<APlayerState>()->GetPawn());
	if(!PlayerPawn) return;

	PlayerPlatformActor = PlayerPawn->GetPlayerPlatform();
	if(!PlayerPlatformActor) return;
	
	PlayerPlatformActor->SetMovementSpeed(PlayerPlatformActor->GetMovementSpeed() * SpeedMultiplier);
}

void ASpeedPowerUpActor::RemovePowerUp()
{
	if(!PlayerPlatformActor) return;
	PlayerPlatformActor->SetDefaultSpeed();
	
	//Destroy at the end
	Super::RemovePowerUp();
}
