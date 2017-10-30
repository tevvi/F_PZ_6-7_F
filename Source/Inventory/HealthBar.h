// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Slate/Public/Widgets/Notifications/SProgressBar.h"
#include "InventoryHud.h"
#include "Engine.h"
/**
 * 
 */
class INVENTORY_API SHealthBar : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SHealthBar)
	{}
	SLATE_ARGUMENT(int32, Health)
	SLATE_ARGUMENT(int32, TotalHealth)
	SLATE_ARGUMENT(TWeakObjectPtr<class AInventoryHud>, SlateHud)
	SLATE_END_ARGS()

	int32 Health;
	int32 TotalHealth;

	TWeakObjectPtr<class AInventoryHud> SlateHud;

	TOptional<float> SetPercentage() const;

	void Construct(const FArguments& InArgs);
	~SHealthBar();
};
