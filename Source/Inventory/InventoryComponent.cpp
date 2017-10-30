// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"


// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


bool UInventoryComponent::AddItem(UPARAM(ref) FItemConfig & Item)
{
	if(WInventory)
		return WInventory->AddItem(Item);
	return false;
	//call Event_AddItemToInventoryWidget
}

void UInventoryComponent::Event_DeleteItem_Implementation(const FItemConfig & Item)
{
	//Its Calls only from InvWidget

	//ItemsBackpack.Remove(Item);

	//call Event_AddItemToInventoryWidget
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

