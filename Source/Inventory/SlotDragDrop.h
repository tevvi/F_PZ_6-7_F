// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/DragDropOperation.h"
#include "SlotWidget.h"
#include "SlotDragDrop.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API USlotDragDrop : public UDragDropOperation
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn))
	USlotWidget* DraggedSlot;
	
};
