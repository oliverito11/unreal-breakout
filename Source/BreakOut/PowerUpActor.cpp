// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpActor.h"

#include "BreakOutPlayerPawn.h"
#include "PlayerPlatformActor.h"

// Sets default values
APowerUpActor::APowerUpActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PowerUpMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Power up mesh"));
	SetRootComponent(PowerUpMesh);
}

// Called when the game starts or when spawned
void APowerUpActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APowerUpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if(!HasPickedUpPowerUp)
	{
		AddActorWorldOffset(-GetActorUpVector() * DownSpeed * DeltaTime, true);
		return;
	}

	PowerUpDuration -= DeltaTime;
	if(PowerUpDuration <= 0)
	{
		RemovePowerUp();
	}
}

void APowerUpActor::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	if(HasPickedUpPowerUp) return;
	if(APlayerPlatformActor *PlayerPlatform = Cast<APlayerPlatformActor>(Other))
	{
		AddPowerUp();
	}
}

void APowerUpActor::AddPowerUp()
{
	UE_LOG(LogTemp, Warning, TEXT("Adding power up to player"));
	HasPickedUpPowerUp = true;
	PowerUpMesh->SetHiddenInGame(true);
	PowerUpMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void APowerUpActor::RemovePowerUp()
{
	UE_LOG(LogTemp, Warning, TEXT("End of Power Up"));
	Destroy();
}
