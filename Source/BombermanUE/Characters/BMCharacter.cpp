// Fill out your copyright notice in the Description page of Project Settings.

#include "BMCharacter.h"
//#include "BMPlayerState.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/InputComponent.h"
//#include "BMBaseActor.h"
#include "BMGameMode.h"

// Sets default values
ABMCharacter::ABMCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
,	availableBombs(1)
, speedLevel(1)

{
	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;


	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->RelativeRotation = FRotator(-60.f, 0.f, 0.f);
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

										  // Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

															 // Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

}

// Called when the game starts or when spawned
void ABMCharacter::BeginPlay()
{

	Super::BeginPlay();
	
}

// Called every frame
void ABMCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ABMCharacter::BeginDestroy()
{
	Super::BeginDestroy();

	if (!GExitPurge)
	{
		
	}
}


	//////////////////////////////////////////////////////////////////////////
	// Input
void ABMCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("DropBomb", IE_Pressed, this, &ABMCharacter::DropABomb);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABMCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABMCharacter::MoveRight);

}


bool ABMCharacter::DropABomb_Validate()
{
	return true;
}

void ABMCharacter::DropABomb_Implementation()
{
	if (availableBombs > 0)
	{
		availableBombs--;

		// Make postion vector, offset from Grid location
		const FVector2D BlockLocation = FVector2D(FMath::RoundToInt(GetActorLocation().X / 100), FMath::RoundToInt(GetActorLocation().Y / 100));

		if (!blocks) blocks = ((ABMGameMode*)GetWorld()->GetAuthGameMode())->BlockGrid;


		ABMBaseActor* spawnedActor = blocks->SpawnBlock(BlockLocation, ABMBomb::StaticClass());
		
		if (spawnedActor)
		{
			blocks->blocksMap.Add(BlockLocation, spawnedActor);

			spawnedActor->SetOwner(this);
		}
	}

	
}

bool ABMCharacter::OnTouchedByExplosion()
{
	Destroy();
	return true;

}

void ABMCharacter::MoveForward(float Val)
{
	if ((Controller != NULL) && (Val != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Val);
	}
}


void ABMCharacter::MoveRight(float Val)
{

	if ((Controller != NULL) && (Val != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Val);
	}
}


void ABMCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	if (Role == ROLE_Authority)
	{
		//Health = GetMaxHealth();
		availableBombs = 1;
		speedLevel = 1;
	}

}

void ABMCharacter::Destroyed()
{
	Super::Destroyed();
}
