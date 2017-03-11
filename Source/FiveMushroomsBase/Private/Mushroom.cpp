// Fill out your copyright notice in the Description page of Project Settings.

#include "FiveMushroomsBase.h"
#include "Mushroom.h"
#include "Engine.h"


// Sets default values
AMushroom::AMushroom()
{
	//Creamos la instacia de la esfera para detectar colisiones
	BaseCollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("Esfera Colision"));
	RootComponent = BaseCollisionComponent;//Inicializamos el rootComponent
										   
	//Creamos la instancia para cargar la malla
	MeshMushroom = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Malla Collecionable"));
	MeshMushroom->AttachTo(RootComponent); //Atachamos o hacemos "hija" a la malla del rootComponent

	//Dejamos el objeto activado
	IsMushroomActive = true;


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

void AMushroom::OnCollected() 
{

	//A modo de Debug ponemos un log en la pantalla
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, "SETA RECOGIDA!!!!");

	//Pasamos a false el flag de bIsActive
	IsMushroomActive = false;

	//Y con el método Destroy de Actor, eliminamos la moneda del escenario
	Destroy();
}


