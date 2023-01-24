// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallActor.generated.h"

UCLASS()
class BREAKOUT_API ABallActor : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent *BallMesh;

	UPROPERTY(EditAnywhere)
	float Speed {100};

	UPROPERTY(VisibleAnywhere)
	FVector BallDirection;
public:	
	// Sets default values for this actor's properties
	ABallActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void DoIfHit(const FHitResult& Hit);
	void MoveBall(float DeltaTime);
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
