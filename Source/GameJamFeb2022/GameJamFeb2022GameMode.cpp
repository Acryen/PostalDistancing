// Copyright Epic Games, Inc. All Rights Reserved.

#include "GameJamFeb2022GameMode.h"
#include "GameJamFeb2022Character.h"
#include "UObject/ConstructorHelpers.h"

AGameJamFeb2022GameMode::AGameJamFeb2022GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
