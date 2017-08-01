// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BMTimedActor.h"
#include "BMPickupItem.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMANUE_API ABMPickupItem : public ABMTimedActor
{
	GENERATED_UCLASS_BODY()
	
public:


	// Overlap
	UFUNCTION()
		virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult) override;

	UFUNCTION(BlueprintImplementableEvent)
		void Action(ACharacter* Target);
};
