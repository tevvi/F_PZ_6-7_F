// Fill out your copyright notice in the Description page of Project Settings.

#include "TopDownCharacter.h"


// Sets default values
ATopDownCharacter::ATopDownCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	//character movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;


	//camera distance
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false;


	//camera
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false;


	PersonInventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("PersonInventory"));
	//cursor
	CursorToWorld = CreateDefaultSubobject<UDecalComponent>("CursorToWorld");
	CursorToWorld->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UMaterial> DecalMaterialAsset(TEXT("Material'/Game/TopDownCPP/Blueprints/M_Cursor_Decal.M_Cursor_Decal'"));
	if (DecalMaterialAsset.Succeeded())
	{
		CursorToWorld->SetDecalMaterial(DecalMaterialAsset.Object);
	}
	CursorToWorld->DecalSize = FVector(16.0f, 32.0f, 32.0f);
	CursorToWorld->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f).Quaternion());

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

// Called when the game starts or when spawned
void ATopDownCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATopDownCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATopDownCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("PickupItem", IE_Pressed, this, &ATopDownCharacter::ExecutePickup);
	PlayerInputComponent->BindAction("ToggleInventory", IE_Pressed, this, &ATopDownCharacter::ToggleInventory);
	PlayerInputComponent->BindAction("DropItem", IE_Pressed, this, &ATopDownCharacter::DropItem);


	PlayerInputComponent->BindAxis("MoveForward", this, &ATopDownCharacter::MyMoveForward);
	PlayerInputComponent->BindAxis("MoveLeft", this, &ATopDownCharacter::MyMoveLeft);
}

void ATopDownCharacter::MyMoveForward(float MoveValue)
{
	if (Controller)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, MoveValue);
	}
}

void ATopDownCharacter::MyMoveLeft(float MoveLeftValue)
{
	if (Controller)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, MoveLeftValue);
	}
}

void ATopDownCharacter::ExecutePickup()
{
	PersonInventory->PickupItem.ExecuteIfBound();
	//DoActorPickup.ExecuteIfBound();
}

void ATopDownCharacter::ToggleInventory()
{
	PersonInventory->WInventory->ToggleInvVisibility();
}

void ATopDownCharacter::DropItem()
{
	if (ItemsBackpack.Num())
	{
		FItemConfig Item = ItemsBackpack.Pop();
		auto CurWorld = GetWorld();
		
		if (CurWorld && Item.SpawnActorClass)//&& Item.SpawnActorClass
		{
			FVector Location = GetActorLocation();
			Location.X += 100;
			CurWorld->SpawnActor<AActor>(Item.SpawnActorClass, Location, GetActorRotation());
		}
			//CurWorld->SpawnActor<APickupActor>(GetActorLocation(),GetActorRotation());
	}
}