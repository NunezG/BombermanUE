// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BMTimedActor.h"
#include "BMBomb.generated.h"



/**
 * 
 */
UCLASS()
class BOMBERMANUE_API ABMBomb : public ABMTimedActor
{
	GENERATED_UCLASS_BODY()

public:

	virtual void EndEvent() override;

	// Overlap
	UFUNCTION()
		virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult) override;



	virtual bool OnTouchedByExplosion() override;

	virtual void Tick(float DeltaTime) override;

};

