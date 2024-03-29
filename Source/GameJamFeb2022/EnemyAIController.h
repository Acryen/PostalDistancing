// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAMFEB2022_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
	bool bNotOma = true;
	
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehaviorTree;
	
protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
private:
	
	UPROPERTY()
	class UBlackboardComponent* BlackboardComponent;

	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* SensedActor, FAIStimulus Stimulus);
};
