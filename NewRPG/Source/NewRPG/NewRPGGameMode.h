// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "NewRPGGameMode.generated.h"

UCLASS(minimalapi)
class ANewRPGGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ANewRPGGameMode();

	virtual void Tick(float DeltaSeconds) override;

	virtual void BeginPlay() override;
};



