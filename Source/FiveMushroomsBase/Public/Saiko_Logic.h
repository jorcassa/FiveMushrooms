// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Saiko_Logic.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FIVEMUSHROOMSBASE_API USaiko_Logic : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USaiko_Logic();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	
	/** Cantidad de monedas recolectadas por el personaje */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Coleccionados)
	int32 MushroomCollected;

	/** Se llama constantemente en el Tick del personaje para determinar si se está colisionando con una moneda */
	void CollectMushroom();
	
};
