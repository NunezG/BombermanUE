// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BMDestructibleWall.h"
#include "BMHardWall.h"
#include "Map.h"
#include "TempActors/BMPickupItem.h"
#include "TempActors/BMBomb.h"

#include "BMBlockGrid.generated.h"

UCLASS()
class BOMBERMANUE_API ABMBlockGrid : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ABMBlockGrid();

	/** Returns DummyRoot subobject **/
	FORCEINLINE class USceneComponent* GetDummyRoot() const { return DummyRoot; }

	ABMBaseActor* SpawnBlock(FVector2D blockPosition, TSubclassOf<ABMBaseActor> blockToSpawn);

	/** Returns Actor found **/
	FORCEINLINE ABMBaseActor* CheckPosition(FVector2D position) const { return *(blocksMap.Find(position)); }

	FORCEINLINE void AddActor(FVector2D position, ABMBaseActor* actor) { blocksMap.Add(position, actor); }

	//The blocks on the grid
	UPROPERTY(Category = Grid, VisibleAnywhere)
		TMap<FVector2D, ABMBaseActor*> blocksMap;

	bool TestBlock(FVector2D position);

	bool DropItem(FVector2D position);

	void BombExplodes(ABMBomb* bomb);


	UPROPERTY(Category = Grid, EditAnywhere, BlueprintReadOnly)
		TArray<TSubclassOf<ABMPickupItem>> Pickups;

private:

	/** Dummy root component */
	UPROPERTY(Category = Grid, VisibleDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		class USceneComponent* DummyRoot;

	/** Number of blocks along each side of grid */
	UPROPERTY(Category = Grid, EditAnywhere)
		int32 Size;

	/** Number of blocks that will fill the outside */
	UPROPERTY(Category = Grid, EditDefaultsOnly)
		int32 MaxSize;

	/** Spacing of blocks */
	UPROPERTY(Category = Grid, EditDefaultsOnly)
		float BlockSpacing;



	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
};