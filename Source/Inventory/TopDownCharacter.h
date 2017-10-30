// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/DecalComponent.h"
#include "Runtime/Engine/Classes/GameFramework/SpringArmComponent.h"
#include "ItemConfig.h"
#include "Runtime/Core/Public/Containers/Array.h"
#include "Runtime/Engine/Classes/Engine/Engine.h"
#include "InventoryComponent.h"
#include "Kismet/HeadMountedDisplayFunctionLibrary.h"
#include "Materials/Material.h"
#include "UObject/ConstructorHelpers.h"
#include "TopDownCharacter.generated.h"


DECLARE_DELEGATE(FVoidDelegate);


UCLASS()
class INVENTORY_API ATopDownCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATopDownCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Top down camera */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
		UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Camera)
	USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory")
	TArray<FItemConfig > ItemsBackpack;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Inventory")
	UInventoryComponent* PersonInventory;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UDecalComponent* CursorToWorld;

	FVoidDelegate DoDrop;

	void MyMoveForward(float MoveValue);
	void MyMoveLeft(float MoveLeftValue);

	void ExecutePickup();
	void ToggleInventory();
	void DropItem();
};
