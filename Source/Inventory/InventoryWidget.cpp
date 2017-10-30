// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryWidget.h"



bool UInventoryWidget::AddItem_Implementation(UPARAM(ref) FItemConfig& item)
{
	for (auto& i : Slots)
	{
		if (i->bIsEmpty)
		{
			i->InitSlot(item);
			i->SetIsEmpty(false);
			return true;
		}
	}
	return false;
}

void UInventoryWidget::ToggleInvVisibility()
{
	bIsVisible = !bIsVisible;
	SetIsEnabled(bIsVisible);
	if (bIsVisible)
		SetVisibility(ESlateVisibility::Visible);
	else
		SetVisibility(ESlateVisibility::Hidden);

}

void UInventoryWidget::DeleteItem(USlotWidget& ItemSlot)
{

}

void UInventoryWidget::NativeConstruct()
{
	bIsVisible = false;
	SetVisibility(ESlateVisibility::Hidden);
	SetIsEnabled(false);
	if ((InventoryPanel) && (TemplatedSlot))
	{
		for (int i = 0; i < Rows; i++)
		{
			for (int j = 0; j < Columbs; j++)
			{
				USlotWidget* Slot = CreateWidget<USlotWidget>(GetWorld(), TemplatedSlot);
				UUniformGridSlot* GridSLot = InventoryPanel->AddChildToUniformGrid(Slot);
				Slots.Add(Slot);
				Slot->DefaultSlot();
				GridSLot->SetColumn(j);
				//k->SetColumn(i);
				GridSLot->SetRow(i);
			}
		}

	}
}