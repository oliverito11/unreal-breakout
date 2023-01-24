// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPlatformActor.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerPlatformActor::APlayerPlatformActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform mesh"));
	SetRootComponent(PlatformMesh);
}

// Called when the game starts or when spawned
void APlayerPlatformActor::BeginPlay()
{
	Super::BeginPlay();

	OriginalScaleActor = GetActorScale();
	OriginalSpeed = MovementSpeed;
}

// Called every frame
void APlayerPlatformActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlayerPlatformActor::MovePlatform(float Axis)
{
	const FVector Movement = GetActorRightVector() * Axis * MovementSpeed * UGameplayStatics::GetWorldDeltaSeconds(this);
	AddActorWorldOffset(Movement, true);
}

void APlayerPlatformActor::SetDefaultScale()
{
	SetActorScale3D(OriginalScaleActor);
}

void APlayerPlatformActor::SetDefaultSpeed()
{
	MovementSpeed = OriginalSpeed;
}
