// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BombermanUE.h"
#include "GameFramework/Actor.h"
#include "UObject/ConstructorHelpers.h"
#include "BMBaseActor.generated.h"

UCLASS(minimalapi)
class ABMBaseActor : public AActor
{
	GENERATED_UCLASS_BODY()
	
protected:
		/** Dummy root component */
	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* DummyRoot;

	/** StaticMesh component for the clickable block */
	UPROPERTY(Category = Block, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* BlockMesh;

	UPROPERTY()
		FVector2D Position;

public:	


	/** Returns Position **/
	FORCEINLINE struct FVector2D GetPosition() const { return Position; }

	/** Returns Position **/
	FORCEINLINE void SetPosition(FVector2D pos) { Position = pos; }

	/** Returns DummyRoot subobject **/
	FORCEINLINE class USceneComponent* GetDummyRoot() const { return DummyRoot; }

	/** Returns BlockMesh subobject **/
	FORCEINLINE class UStaticMeshComponent* GetBlockMesh() const { return BlockMesh; }
};
