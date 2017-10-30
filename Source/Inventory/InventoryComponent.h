// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ItemConfig.h"
#include "InventoryWidget.h"
#include "InventoryComponent.generated.h"

DECLARE_DELEGATE(FVoidDelegate);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INVENTORY_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInventoryWidget* WInventory;

	FVoidDelegate PickupItem;

	UFUNCTION(BlueprintCallable)
	bool AddItem(UPARAM(ref) FItemConfig& Item);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Event_DeleteItem(const FItemConfig& Item);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
	
};
