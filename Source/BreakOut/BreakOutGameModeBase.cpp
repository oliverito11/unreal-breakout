// Copyright Epic Games, Inc. All Rights Reserved.


#include "BreakOutGameModeBase.h"

#include "BallActor.h"
#include "Kismet/GameplayStatics.h"

void ABreakOutGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	CurrentBallActor = SpawnNewBall();
	UGameplayStatics::GetAllActorsOfClass(this, BlockActorClass,BlockActorList);
	NumberOfBlocks = BlockActorList.Num();
}

void ABreakOutGameModeBase::RemovePlayerLive()
{
	if(!CurrentBallActor) return;

	CurrentBallActor->Destroy();
	PlayerLives--;		
	if(PlayerLives <= 0) return;

	CurrentBallActor = SpawnNewBall();
	UE_LOG(LogTemp, Warning, TEXT("Balls left: %i"), PlayerLives);
}

void ABreakOutGameModeBase::RemoveBlockFromLevel(ADestructibleBlockActor* BlockHit)
{
	NumberOfBlocks--;
	if(NumberOfBlocks <= 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Win"));
	}
	UE_LOG(LogTemp, Warning, TEXT("NumberOfBlocks: %i"), NumberOfBlocks);
}

ABallActor* ABreakOutGameModeBase::SpawnNewBall()
{
	return GetWorld()->SpawnActor<ABallActor>(BallActorClass, BallSpawnLocation, FRotator::ZeroRotator);
}

void ABreakOutGameModeBase::AddPlayerLive()
{
	PlayerLives++;
}

