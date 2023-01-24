// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BreakOutGameModeBase.generated.h"

class ADestructibleBlockActor;
class ABallActor;
/**
 * 
 */
UCLASS()
class BREAKOUT_API ABreakOutGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere)
	int PlayerLives {3};

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABallActor> BallActorClass;
	
	UPROPERTY(VisibleAnywhere)
	ABallActor *CurrentBallActor;

	UPROPERTY(EditAnywhere, meta=(MakeEditWidget))
	FVector BallSpawnLocation;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> BlockActorClass;
	
	UPROPERTY(VisibleAnywhere)
	TArray<AActor *> BlockActorList;

	UPROPERTY(VisibleAnywhere)
	int NumberOfBlocks;
public:
	virtual void BeginPlay() override;
	void RemovePlayerLive();
	void RemoveBlockFromLevel(ADestructibleBlockActor *BlockHit);
	ABallActor* SpawnNewBall();
	void AddPlayerLive();
};
