// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Mushroom.generated.h"

UCLASS()
class FIVEMUSHROOMSBASE_API AMushroom : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMushroom();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


	void OnCollected();
	void AddRotation();

	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mushroom)
	USphereComponent* BaseCollisionComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Mushroom)
	UStaticMeshComponent* MeshMushroom = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mushroom)
	bool IsMushroomActive;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Mushroom)
	FRotator VelocidadDeGiro;



	
};
