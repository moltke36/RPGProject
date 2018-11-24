// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "NewRPGGameMode.h"
#include "NewRPGPlayerController.h"
#include "NewRPGCharacter.h"
#include "UObject/ConstructorHelpers.h"

ANewRPGGameMode::ANewRPGGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ANewRPGPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}