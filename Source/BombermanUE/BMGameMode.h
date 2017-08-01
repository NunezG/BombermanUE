// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Blocks/TempActors/BMBomb.h"
#include "Blocks/BMblockGrid.h"
#include "BMGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMANUE_API ABMGameMode : public AGameModeBase
{
	GENERATED_UCLASS_BODY()
	

public:

	UPROPERTY(Category = Grid, EditAnywhere, BlueprintReadWrite)
		ABMBlockGrid* BlockGrid;


	void SpawnABomb(FVector2D position);



};
