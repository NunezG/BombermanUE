// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BMBaseActor.h"
#include "DestructibleInterface.h"
#include "TempActors/BMPickupItem.h"
#include "BMDestructibleWall.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMANUE_API ABMDestructibleWall : public ABMBaseActor, public IDestructible
{
	GENERATED_UCLASS_BODY()

	virtual void BeginPlay() override;

	
	virtual bool OnTouchedByExplosion() override;

	bool DropItem(FVector2D position);

	class ABMBlockGrid* blocks;

};
