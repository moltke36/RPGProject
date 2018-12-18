// Fill out your copyright notice in the Description page of Project Settings.

#include "AiCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

AAiCharacter::AAiCharacter()
{

}

void AAiCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void AAiCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}

void AAiCharacter::MoveRight(float InputAxis)
{
	if (InputAxis != 0)
	{
		GetMovementComponent()->AddInputVector(FVector(0, MaxSpeed*InputAxis, 0));
	}
}

void AAiCharacter::MoveUp(float InputAxis)
{
	if (InputAxis != 0)
	{
		GetMovementComponent()->AddInputVector(FVector(MaxSpeed*InputAxis, 0, 0));
	}
}

