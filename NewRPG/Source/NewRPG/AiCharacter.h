// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NewRPGCharacter.h"
#include "AiCharacter.generated.h"

/**
 * 
 */
UCLASS()
class NEWRPG_API AAiCharacter : public ANewRPGCharacter
{
	GENERATED_BODY()
	
public:
	AAiCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override;

protected:
	virtual void MoveRight(float InputAxis);

	virtual void MoveUp(float InputAxis) override;
	
	
};
