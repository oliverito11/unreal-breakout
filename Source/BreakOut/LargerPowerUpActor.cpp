// Fill out your copyright notice in the Description page of Project Settings.


#include "LargerPowerUpActor.h"

#include "BreakOutPlayerPawn.h"
#include "PlayerPlatformActor.h"
#include "GameFramework/PlayerState.h"

void ALargerPowerUpActor::AddPowerUp()
{
	Super::AddPowerUp();
	
	const ABreakOutPlayerPawn *PlayerPawn = Cast<ABreakOutPlayerPawn>(GetWorld()->GetFirstPlayerController()->GetPlayerState<APlayerState>()->GetPawn());
	if(!PlayerPawn) return;

	PlayerPlatformActor = PlayerPawn->GetPlayerPlatform();
	if(!PlayerPlatformActor) return;

	FVector NewScale = PlayerPlatformActor->GetActorScale();
	NewScale.Y *= ScaleFactorMultiplier;
	
	PlayerPlatformActor->SetActorScale3D(NewScale);
}

void ALargerPowerUpActor::RemovePowerUp()
{
	if(!PlayerPlatformActor) return;
	PlayerPlatformActor->SetDefaultScale();
	
	Super::RemovePowerUp();
}
