// Fill out your copyright notice in the Description page of Project Settings.

#include "FiveMushroomsBase.h"
#include "NextWayPoint.h"
#include "AIController.h"
#include "PatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"



EBTNodeResult::Type UNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{



	//Get the patrol points

	auto ControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();
	if(!ensure(PatrolRoute)){ return EBTNodeResult::Failed;}

	//Warning about patrol routs empty
	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0) 
	{

	UE_LOG(LogTemp, Warning, TEXT(" La ruta no tiene puntos"));


	}

	//Set next Waypoint
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);// seteamos el valor del Waypoint

	 //Cycle the index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();//aumentamos el indice para pasar al siguiente punto	
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	return	EBTNodeResult::Succeeded;


 }

