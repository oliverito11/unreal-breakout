// Fill out your copyright notice in the Description page of Project Settings.


#include "DestructibleBlockActor.h"

#include "BreakOutGameModeBase.h"
#include "PowerUpActor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ADestructibleBlockActor::ADestructibleBlockActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Block mesh"));
	SetRootComponent(BlockMesh);
}

// Called when the game starts or when spawned
void ADestructibleBlockActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ADestructibleBlockActor::HitByBall()
{
	//TODO: SFX and VFX
	if(WasHit) return;
	
	WasHit = true;
	ABreakOutGameModeBase *GameMode = Cast<ABreakOutGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if(!GameMode) return;

	//There's a chance to spawn a Power Up
	if(SpawnPowerUpPossibility >= FMath::RandRange(0, 100))
	{
		const TSubclassOf<APowerUpActor> PowerUpClass = PowerUpActorsClasses[FMath::RandRange(0, PowerUpActorsClasses.Num() - 1)];
		GetWorld()->SpawnActor<APowerUpActor>(PowerUpClass, GetActorLocation(), GetActorRotation());
	}
	
	Destroy();
	GameMode->RemoveBlockFromLevel(this);
}
