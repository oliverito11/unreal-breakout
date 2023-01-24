// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputAction.h"
#include "GameFramework/Pawn.h"
#include "BreakOutPlayerPawn.generated.h"

class APlayerPlatformActor;
class UCameraComponent;
class UInputAction;
UCLASS()
class BREAKOUT_API ABreakOutPlayerPawn : public APawn
{
	GENERATED_BODY()
private:
	UPROPERTY(EditDefaultsOnly)
	UCameraComponent *Camera;

	UPROPERTY(EditDefaultsOnly, Category="Platform")
	TSubclassOf<APlayerPlatformActor> PlayerPlatformClass;

	UPROPERTY(EditAnywhere, meta=(MakeEditWidget), Category="Platform")
	FVector SpawnLocation;
	
	UPROPERTY(VisibleAnywhere, Category="Platform")
	APlayerPlatformActor *PlayerPlatform;

	UPROPERTY(EditDefaultsOnly)
	UInputAction *MoveInputAction;
public:
	// Sets default values for this pawn's properties
	ABreakOutPlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MovePlatform(const FInputActionInstance &Axis);

	APlayerPlatformActor *GetPlayerPlatform() const { return this->PlayerPlatform; }
};
