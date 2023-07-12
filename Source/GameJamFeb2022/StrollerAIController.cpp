// Fill out your copyright notice in the Description page of Project Settings.


#include "StrollerAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "StrollerCharacter.h"

void AStrollerAIController::BeginPlay()
{
	Super::BeginPlay();

	if (!AIBehaviorTree) return;
	RunBehaviorTree(AIBehaviorTree);

	BlackboardComponent = GetBlackboardComponent();
	if (!BlackboardComponent) return;

	AStrollerCharacter* StrollerCharacter = Cast<AStrollerCharacter>(GetPawn());
	if (!StrollerCharacter) return;

	BlackboardComponent->SetValueAsVector("StartLocation", StrollerCharacter->StartLocation + GetPawn()->GetActorLocation());
	BlackboardComponent->SetValueAsVector("TargetLocation", StrollerCharacter->TargetLocation + GetPawn()->GetActorLocation());
}