// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemConfig.h"
#include "Runtime/Engine/Classes/Components/SphereComponent.h"
#include "TopDownCharacter.h"
#include "PickupActor.generated.h"

UCLASS()
class INVENTORY_API APickupActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupActor();

	void Pickup();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;

	virtual void NotifyActorEndOverlap(AActor* OtherActor) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	FItemConfig CurrentItem;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	USphereComponent* ItemUsageRadius;

	ATopDownCharacter* CurrentCharacter;
};
