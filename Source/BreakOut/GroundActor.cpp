// Fill out your copyright notice in the Description page of Project Settings.


#include "GroundActor.h"

#include "BallActor.h"
#include "BreakOutGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AGroundActor::AGroundActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DebugMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Debug mesh"));
	SetRootComponent(DebugMesh);
}

// Called when the game starts or when spawned
void AGroundActor::BeginPlay()
{
	Super::BeginPlay();

	DebugMesh->SetHiddenInGame(true);
}

void AGroundActor::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	if(Cast<ABallActor>(Other))
	{
		UE_LOG(LogTemp, Warning, TEXT("Una vida menos.."));
		
		ABreakOutGameModeBase *GameMode = Cast<ABreakOutGameModeBase>(UGameplayStatics::GetGameMode(this));
		if(!GameMode) return;

		GameMode->RemovePlayerLive();
	}
	else
	{
		Other->Destroy();
	}
}
