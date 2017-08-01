// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Blocks/TempActors/BMBomb.h"
#include "./DestructibleInterface.h"

#include "BMCharacter.generated.h"



UCLASS()
class BOMBERMANUE_API ABMCharacter : public ACharacter, public IDestructible
{
	GENERATED_UCLASS_BODY()

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

public:

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Server, Reliable, WithValidation)
		void DropABomb();

	virtual void BeginDestroy() override;

	/** spawn inventory, setup initial variables */
	virtual void PostInitializeComponents() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** cleanup inventory */
	virtual void Destroyed() override;

	virtual bool OnTouchedByExplosion() override;


	UPROPERTY(Category = Bomb, VisibleAnywhere, BlueprintReadWrite)
		int availableBombs = 1;


	UPROPERTY(Category = Bomb, VisibleAnywhere, BlueprintReadWrite)
		int bombRadius = 1;

private:

	UPROPERTY(VisibleAnywhere)
		class ABMBlockGrid* blocks;

	/**
	* Move forward/back
	*
	* @param Val Movment input to apply
	*/
	void MoveForward(float Val);

	/**
	* Strafe right/left
	*
	* @param Val Movment input to apply
	*/
	void MoveRight(float Val);
};
