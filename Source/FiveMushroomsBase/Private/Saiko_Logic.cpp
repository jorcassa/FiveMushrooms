// Fill out your copyright notice in the Description page of Project Settings.

#include "FiveMushroomsBase.h"
#include "Saiko_Logic.h"
#include "Mushroom.h"


// Sets default values for this component's properties
USaiko_Logic::USaiko_Logic()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	MushroomCollected = 0;
	// ...
}


// Called when the game starts
void USaiko_Logic::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void USaiko_Logic::CollectMushroom() 
{

	ACharacter* SaikoBody = Cast<ACharacter>(GetOwner());
	UCapsuleComponent* Capsulacollision = SaikoBody->GetCapsuleComponent();//ObtenemosLaCapsula dentro del character??

	TArray<AActor*> MCollected;
	Capsulacollision->GetOverlappingActors(MCollected);

	for (int32 i = 0; i < MCollected.Num(); i++) {

		AMushroom* Mushroom = Cast<AMushroom>(MCollected[i]);//Casteamos a la clase AMushrooms

		if (Mushroom != NULL && !Mushroom->IsPendingKill() && Mushroom->IsMushroomActive)
		{
			//Incrementamos la cantidad de momendas recolectadas
			MushroomCollected++;

			//Por último llamamos al OnCollected de la Mushroom para ejecutar toda la lógica de la Mushroom cuando esta es tomada por el personaje
			Mushroom->OnCollected();
		}


	}



}




// Called every frame
void USaiko_Logic::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	CollectMushroom();
	// ...
}

