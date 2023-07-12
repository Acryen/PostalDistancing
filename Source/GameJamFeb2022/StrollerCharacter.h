// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "StrollerCharacter.generated.h"

UCLASS()
class GAMEJAMFEB2022_API AStrollerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AStrollerCharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector StartLocation;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

};
