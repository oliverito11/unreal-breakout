// Fill out your copyright notice in the Description page of Project Settings.


#include "BallActor.h"

#include "DestructibleBlockActor.h"

// Sets default values
ABallActor::ABallActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball mesh"));
	SetRootComponent(BallMesh);
}

// Called when the game starts or when spawned
void ABallActor::BeginPlay()
{
	Super::BeginPlay();
	BallDirection = FVector(0, 0.5, 0.5);
}

// Called every frame
void ABallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveBall(DeltaTime);
}

void ABallActor::MoveBall(float DeltaTime)
{
	FHitResult Hit;
	const FVector DeltaLocation = BallDirection * Speed * DeltaTime;
	AddActorWorldOffset(DeltaLocation, true, &Hit);

	DoIfHit(Hit);
}

void ABallActor::DoIfHit(const FHitResult& Hit)
{
	if(!Hit.GetActor()) return;

	//Bounce formula
	BallDirection -= 2 * FVector::DotProduct(BallDirection, Hit.ImpactNormal) * Hit.ImpactNormal;

	if(ADestructibleBlockActor *ActorHit = Cast<ADestructibleBlockActor>(Hit.GetActor()))
	{
		ActorHit->HitByBall();
	}
}