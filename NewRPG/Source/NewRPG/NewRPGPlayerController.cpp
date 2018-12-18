// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "NewRPGPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "NewRPGCharacter.h"
#include "Engine/World.h"

ANewRPGPlayerController::ANewRPGPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

}

void ANewRPGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// TODO: Remove this
	DefaultMouseCursor = EMouseCursor::Default;

	MyPawn = Cast<ANewRPGCharacter>(GetPawn());
	if (MyPawn == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Missing MyPawn"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MyPawn= %s"), *MyPawn->GetName());
	}
}

void ANewRPGPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

}

//void ANewRPGPlayerController::SetupInputComponent(class UInputComponent* PlayerInputComponent)
//{
//	// set up gameplay key bindings
//	check(PlayerInputComponent);
//	UE_LOG(LogTemp, Warning, TEXT("Right called"));
//	// Set up gameplay key bindings
//
//	// Bind jump events
//	//PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
//	//PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
//
//	// Bind movement events
//	PlayerInputComponent->BindAxis("MoveUp", this, &ANewRPGPlayerController::MoveUp);
//	PlayerInputComponent->BindAxis("MoveRight", this, &ANewRPGPlayerController::MoveRight);
//
//}

void ANewRPGPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	//InputComponent->BindAxis("MoveUp", this, &ANewRPGPlayerController::MoveUp);
	//InputComponent->BindAxis("MoveRight", this, &ANewRPGPlayerController::MoveRight);

	// support touch devices 

	InputComponent->BindAction("ResetVR", IE_Pressed, this, &ANewRPGPlayerController::OnResetVR);
}

void ANewRPGPlayerController::MoveUp(float InputAxis)
{
	if (MyPawn != nullptr)
	{
		MyPawn->MoveUp(InputAxis);
	}
}

void ANewRPGPlayerController::MoveRight(float InputAxis)
{
	if (MyPawn != nullptr)
	{
		MyPawn->MoveRight(InputAxis);
	}
}

void ANewRPGPlayerController::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ANewRPGPlayerController::MoveToMouseCursor()
{
	//if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	//{
	//	if (ANewRPGCharacter* MyPawn = Cast<ANewRPGCharacter>(GetPawn()))
	//	{
	//		if (MyPawn->GetCursorToWorld())
	//		{
	//			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, MyPawn->GetCursorToWorld()->GetComponentLocation());
	//		}
	//	}
	//}
	//else
	//{
	//	// Trace to see what is under the mouse cursor
	//	FHitResult Hit;
	//	GetHitResultUnderCursor(ECC_Visibility, false, Hit);

	//	if (Hit.bBlockingHit)
	//	{
	//		// We hit something, move there
	//		SetNewMoveDestination(Hit.ImpactPoint);
	//	}
	//}
}

void ANewRPGPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	//FVector2D ScreenSpaceLocation(Location);

	//// Trace to see what is under the touch location
	//FHitResult HitResult;
	//GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	//if (HitResult.bBlockingHit)
	//{
	//	// We hit something, move there
	//	SetNewMoveDestination(HitResult.ImpactPoint);
	//}
}

void ANewRPGPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	//APawn* const MyPawn = GetPawn();
	//if (MyPawn)
	//{
	//	float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

	//	// We need to issue move command only if far enough in order for walk animation to play correctly
	//	if ((Distance > 120.0f))
	//	{
	//		UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
	//	}
	//}
}

void ANewRPGPlayerController::OnSetDestinationPressed()
{
	//// set flag to keep updating destination until released
	//bMoveToMouseCursor = true;
}

void ANewRPGPlayerController::OnSetDestinationReleased()
{
	//// clear flag to indicate we should stop updating the destination
	//bMoveToMouseCursor = false;
}
