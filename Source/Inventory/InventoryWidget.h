// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemConfig.h"
#include "SlotWidget.h"
#include "Runtime/UMG/Public/Components/UniformGridPanel.h"
#include "Runtime/UMG/Public/Components/UniformGridSlot.h"
#include "InventoryWidget.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FInvConfig
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slots")// Category = "Item|Mesh"
	USlotWidget* Slot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slots")
	bool bIsEmpty;


};

UCLASS()
class INVENTORY_API UInventoryWidget : public UUserWidget
{
	GENERATED_BODY()
protected:
	virtual void NativeConstruct() override;
public:

	//UInventoryWidget();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UUniformGridPanel* InventoryPanel;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	bool AddItem(UPARAM(ref) FItemConfig& item);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<USlotWidget> TemplatedSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<USlotWidget* > Slots;

	UFUNCTION(BlueprintCallable)
	void ToggleInvVisibility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsVisible;
	//UFUNCTION(BlueprintCallable)
	void DeleteItem(USlotWidget& ItemSlot);

	int32 Columbs = 4;
	int32 Rows = 2;
};
