// Fill out your copyright notice in the Description page of Project Settings.

#include "FiveMushroomsBase.h"
#include "Mushroom.h"


// Sets default values
AMushroom::AMushroom()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMushroom::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMushroom::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

