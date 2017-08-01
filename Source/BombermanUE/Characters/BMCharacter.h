// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../Blocks/TempActors/BMBomb.h"

#include "BMCharacter.generated.h"



UCLASS()
class BOMBERMANUE_API ABMCharacter : public ACharacter
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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UFUNCTION(Server, Reliable, WithValidation)
	void DropABomb();

public:	

	virtual void BeginDestroy() override;

	/** spawn inventory, setup initial variables */
	virtual void PostInitializeComponents() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** cleanup inventory */
	virtual void Destroyed() override;


private:

	UPROPERTY(Category = Bomb, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int availableBombs;

	UPROPERTY(Category = Bomb, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int BombBlastLevel;

	UPROPERTY(Category = Bomb, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	int speedLevel;


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
