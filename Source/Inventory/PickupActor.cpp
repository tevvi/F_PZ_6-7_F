// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupActor.h"


// Sets default values
APickupActor::APickupActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemUsageRadius = CreateDefaultSubobject<USphereComponent>(TEXT("ItemUsageRadius"));
	ItemUsageRadius->InitSphereRadius(100.f);
	RootComponent = ItemUsageRadius;
}

// Called when the game starts or when spawned
void APickupActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickupActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickupActor::Pickup()
{
	if (CurrentCharacter)
	{
		CurrentCharacter->PersonInventory->AddItem(CurrentItem);
		//CurrentCharacter->ItemsBackpack.Add(this->CurrentItem);
		this->Destroy();
	}
}

void APickupActor::NotifyActorBeginOverlap(AActor* OtherActor)
{
	CurrentCharacter = Cast<ATopDownCharacter>(OtherActor);
	if (CurrentCharacter)
		CurrentCharacter->PersonInventory->PickupItem.BindUObject(this, &APickupActor::Pickup);
}

void APickupActor::NotifyActorEndOverlap(AActor* OtherActor)
{
	if (CurrentCharacter)
	{
		CurrentCharacter->PersonInventory->PickupItem.Unbind();
		CurrentCharacter = nullptr;
	}
}