// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Engine/Texture2D.h"
#include "Runtime/Core/Public/UObject/NameTypes.h"
#include "ItemConfig.generated.h"


/**
 * 
 */
USTRUCT(BlueprintType)
struct FItemConfig
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Config")// Category = "Item|Mesh"
	bool bIsImplemeted = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Config")// Category = "Item|Mesh"
	FName ItemName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Config")
	UTexture2D* Texture;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item|Config")
	TSubclassOf<AActor> SpawnActorClass;
};