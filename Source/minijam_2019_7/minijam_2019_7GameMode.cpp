// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "minijam_2019_7GameMode.h"
#include "minijam_2019_7Character.h"
#include "UObject/ConstructorHelpers.h"

Aminijam_2019_7GameMode::Aminijam_2019_7GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
