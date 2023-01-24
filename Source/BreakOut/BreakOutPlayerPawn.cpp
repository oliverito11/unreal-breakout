// Fill out your copyright notice in the Description page of Project Settings.


#include "BreakOutPlayerPawn.h"

#include "PlayerPlatformActor.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputComponent.h"

// Sets default values
ABreakOutPlayerPawn::ABreakOutPlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root component"));
	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ABreakOutPlayerPawn::BeginPlay()
{
	Super::BeginPlay();

	PlayerPlatform = GetWorld()->SpawnActor<APlayerPlatformActor>(PlayerPlatformClass, SpawnLocation, FRotator::ZeroRotator);
}

// Called every frame
void ABreakOutPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABreakOutPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	
	Input->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &ABreakOutPlayerPawn::MovePlatform);
}

void ABreakOutPlayerPawn::MovePlatform(const FInputActionInstance &Instance)
{
	if(!PlayerPlatform) return;

	PlayerPlatform->MovePlatform(Instance.GetValue().Get<float>());
}
