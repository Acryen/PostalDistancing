// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"

#include "EnemyCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	if (!AIBehaviorTree) return;
	RunBehaviorTree(AIBehaviorTree);

	BlackboardComponent = GetBlackboardComponent();
	if (BlackboardComponent == nullptr) return;

	if (bNotOma)
		BlackboardComponent->SetValueAsVector("StartLocation", GetPawn()->GetActorLocation());

	if (!GetAIPerceptionComponent()) return;
	GetAIPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyAIController::OnTargetPerceptionUpdated);
}

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (BlackboardComponent->GetValueAsBool("bWalkingInRange"))
	{
		if (FVector::Distance(GetPawn()->GetActorLocation(), BlackboardComponent->GetValueAsVector("StartLocation")) > 1000)
			BlackboardComponent->SetValueAsBool("bWalkingInRange", false);

		//UE_LOG(LogTemp, Warning, TEXT("%s"), BlackboardComponent->GetValueAsBool("bWalkin"));
	}
}

void AEnemyAIController::OnTargetPerceptionUpdated(AActor* SensedActor, FAIStimulus Stimulus)
{
	bool SomethingIsInSight = GetAIPerceptionComponent()->HasActiveStimulus(*(UGameplayStatics::GetPlayerPawn(this, 0)), UAISense::GetSenseID<UAISense_Sight>());
	if (SomethingIsInSight)
	{
		BlackboardComponent->SetValueAsVector("PlayerLocation", UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation());
		BlackboardComponent->SetValueAsVector("LastKnownLocation", UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation());
		BlackboardComponent->SetValueAsBool("bWalkingInRange", true);
	}
	else
	{
		BlackboardComponent->ClearValue("PlayerLocation");
	}
}