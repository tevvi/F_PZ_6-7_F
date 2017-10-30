// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ItemConfig.h"
#include "Runtime/SlateCore/Public/Input/Reply.h"
#include "Runtime/UMG/Public/Components/Image.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "SlotWidget.generated.h"



/**
 * 
 */

UCLASS()
class INVENTORY_API USlotWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	//virtual FReply NativeOnMouseButtonDown(const FGeometry & InGeometry, const FPointerEvent & InMouseEvent) override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slots")
	UImage* ItemImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slots")
	UTextBlock* ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slots")
	FItemConfig Item;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void InitSlot(UPARAM(ref) FItemConfig& CurItem);

	UFUNCTION(BlueprintCallable)
	void DefaultSlot();

	UFUNCTION(BlueprintCallable)
	void SetIsEmpty(bool IsEmpty);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Slots")
	bool bIsEmpty = true;

	


	UFUNCTION(BlueprintCallable)
	void SwapItems(UPARAM(ref) USlotWidget* MySlot);//UPARAM(ref)
};
