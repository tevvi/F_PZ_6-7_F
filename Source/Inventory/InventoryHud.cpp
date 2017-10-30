// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryHud.h"

void AInventoryHud::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	SAssignNew(MainMenuUI, SMainMenu).SlateHud(this);

	if (GEngine)
	{
		GEngine->GameViewport->AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(MainMenuUI.ToSharedRef()));
	}

}

