// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SMainMenu.h"
#include "Engine.h"
#include "InventoryHud.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORY_API AInventoryHud : public AHUD
{
	GENERATED_BODY()
	
	virtual void PostInitializeComponents()override;

	// SharedPtr 
	TSharedPtr<class SMainMenu> MainMenuUI;
	
	
};
