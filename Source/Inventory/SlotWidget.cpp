// Fill out your copyright notice in the Description page of Project Settings.

#include "SlotWidget.h"


void USlotWidget::InitSlot_Implementation(UPARAM(ref) FItemConfig& CurItem)
{
	Item = CurItem;

	if (CurItem.Texture)
	{
		ItemImage->SetBrushFromTexture(CurItem.Texture);
		SetIsEmpty(false);
	}
	else
		SetIsEmpty(true);

	if(CurItem.ItemName != "")
		ItemName->SetText(FText::FromName(CurItem.ItemName));
		
}

void USlotWidget::SwapItems(UPARAM(ref) USlotWidget* MySlot)//
{
	auto MyItem = MySlot->Item;
	auto ThisItem = Item;
	MySlot->InitSlot(ThisItem);
	this->InitSlot(MyItem);

}

void USlotWidget::DefaultSlot()
{
	this->Item = FItemConfig();
	SetIsEmpty(true);
}

void USlotWidget::SetIsEmpty(bool IsEmpty)
{
	this->bIsEmpty = IsEmpty;
	
	if (!bIsEmpty)
	{
		ItemImage->SetVisibility(ESlateVisibility::Visible);
		ItemName->SetVisibility(ESlateVisibility::Visible);
		//SetIsEnabled(true);
	}
	else
	{
		ItemImage->SetVisibility(ESlateVisibility::Hidden);
		ItemName->SetVisibility(ESlateVisibility::Hidden);
		//SetIsEnabled(false);
	}
}
