// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerPlatformActor.generated.h"

UCLASS()
class BREAKOUT_API APlayerPlatformActor : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent *PlatformMesh;

	UPROPERTY(EditAnywhere)
	float MovementSpeed {100};

	FVector OriginalScaleActor;
	float OriginalSpeed;
public:	
	// Sets default values for this actor's properties
	APlayerPlatformActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void MovePlatform(float Axis);

	void SetMovementSpeed(float Speed) { this->MovementSpeed = Speed; }
	float GetMovementSpeed() const { return this->MovementSpeed; }

	void SetDefaultScale();
	void SetDefaultSpeed();
};
