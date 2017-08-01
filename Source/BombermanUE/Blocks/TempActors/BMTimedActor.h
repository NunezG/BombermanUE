// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../BMBaseActor.h"
#include "GameFramework/Character.h"
//#include "./BMGameMode.h"
//#include "BMBlockGrid.h"
#include "./DestructibleInterface.h"
#include "BMTimedActor.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMANUE_API ABMTimedActor : public ABMBaseActor, public IDestructible
{
	GENERATED_UCLASS_BODY()
	
public:

	UPROPERTY(VisibleAnywhere)
	float Timer = 0;

	float TimeToEnd = 2;

	UPROPERTY(VisibleAnywhere)
	class ABMBlockGrid* blocks;

	virtual void EndEvent();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
	

	// Overlap
	UFUNCTION()
		virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult &SweepResult) {};

	virtual bool OnTouchedByExplosion() override;

};
