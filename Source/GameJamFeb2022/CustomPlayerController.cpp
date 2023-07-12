// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerController.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "PlayerCharacter.h"

void ACustomPlayerController::BeginPlay()
{
	Super::BeginPlay();

	FInputModeGameOnly InputMode;
	InputMode.SetConsumeCaptureMouseDown(false);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void ACustomPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bMoveToMouseCursor)
		MoveToMouseCursor();
}

void ACustomPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("Move", IE_Pressed, this, &ACustomPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("Move", IE_Released, this, &ACustomPlayerController::OnSetDestinationReleased);
}

void ACustomPlayerController::MoveToMouseCursor()
{
	// Trace to see what is under the mouse cursor
	FHitResult Hit;
	GetHitResultUnderCursor(ECC_GameTraceChannel1, false, Hit);

	if (Hit.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(Hit.ImpactPoint);
	}
}

void ACustomPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void ACustomPlayerController::OnSetDestinationPressed()
{
	bMoveToMouseCursor = true;
}

void ACustomPlayerController::OnSetDestinationReleased()
{
	bMoveToMouseCursor = false;
}