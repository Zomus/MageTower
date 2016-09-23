// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "MageTower.h"
#include "MageTowerGameMode.h"
#include "MageTowerCharacter.h"

AMageTowerGameMode::AMageTowerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
