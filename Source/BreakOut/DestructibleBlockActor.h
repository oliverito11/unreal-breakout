// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DestructibleBlockActor.generated.h"

class APowerUpActor;
UCLASS()
class BREAKOUT_API ADestructibleBlockActor : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent *BlockMesh;

	UPROPERTY(EditDefaultsOnly)
	TArray<TSubclassOf<APowerUpActor>> PowerUpActorsClasses;

	UPROPERTY(EditAnywhere)
	int SpawnPowerUpPossibility {25};

	bool WasHit {false};

public:	
	// Sets default values for this actor's properties
	ADestructibleBlockActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	void HitByBall();
};
