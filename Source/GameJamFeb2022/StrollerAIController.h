// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "StrollerAIController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAMFEB2022_API AStrollerAIController : public AAIController
{
	GENERATED_BODY()
	
protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehaviorTree;

	class UBlackboardComponent* BlackboardComponent;
};
