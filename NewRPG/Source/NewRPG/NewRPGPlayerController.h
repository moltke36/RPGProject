// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "NewRPGPlayerController.generated.h"

class ANewRPGCharacter;

UCLASS()
class ANewRPGPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ANewRPGPlayerController();

	ANewRPGCharacter * MyPawn;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = Movement)
	void MoveUp(float Value);

	UFUNCTION(BlueprintCallable, Category = Movement)
	void MoveRight(float Value);


protected:


	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent();



	

	// End PlayerController interface

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);
	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();
};


