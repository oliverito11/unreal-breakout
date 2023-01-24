// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PowerUpActor.generated.h"

UCLASS()
class BREAKOUT_API APowerUpActor : public AActor
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly)
	UStaticMeshComponent *PowerUpMesh;

	UPROPERTY(EditAnywhere)
	float PowerUpDuration {5};

	UPROPERTY(VisibleAnywhere)
	bool HasPickedUpPowerUp;

	UPROPERTY(EditAnywhere)
	float DownSpeed {200};

public:	
	// Sets default values for this actor's properties
	APowerUpActor();

protected:
	virtual void BeginPlay() override;
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
	virtual void Tick(float DeltaTime) override;
	
	virtual void AddPowerUp();
	virtual void RemovePowerUp();
};
