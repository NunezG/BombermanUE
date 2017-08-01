// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../BMBaseActor.h"
#include "GameFramework/Character.h"
#include "BMTimedActor.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMANUE_API ABMTimedActor : public ABMBaseActor
{
	GENERATED_UCLASS_BODY()
	
protected:
	float Timer = 0;
	float TimeToEnd = 2;

	virtual void EndEvent();

	virtual void Tick(float DeltaTime) override;
	

	// Overlap
	UFUNCTION()
		virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult) {};
};
