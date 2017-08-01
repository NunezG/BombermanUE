// Fill out your copyright notice in the Description page of Project Settings.

#include "BMBlockGrid.h"
#include "BMHardWall.h"
#include "Engine/World.h"
#include "BMBaseActor.h"

// Sets default values
ABMBlockGrid::ABMBlockGrid()
{
	PrimaryActorTick.bCanEverTick = false;

	//This actor will only exist on Server
	bNetLoadOnClient = false;

	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// These values will be changed by Host player
	Size = 15;
	MaxSize = Size+ 4;

	BlockSpacing = 100;

	//Sets a random seed
	int64 DateInSeconds = FDateTime::Now().ToUnixTimestamp();
	FMath::SRandInit(DateInSeconds);

}

// Called when the game starts or when spawned
void ABMBlockGrid::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		// Loop to spawn each block
		for (int x = 0; x < MaxSize; x++)
		{
			for (int y = 0; y < MaxSize; y++)
			{
				// Position of the block
				// Divide by dimension, modulo gives remainder
				FVector2D vec = FVector2D(x, y);
				float startMapping = (float)(MaxSize - Size) / 2.0f;

				if (vec.X < startMapping || vec.Y < startMapping || vec.X >= MaxSize - startMapping || vec.Y >= MaxSize - startMapping)
				{
					//Fill external blocks with Hard wall type
					AddActor(vec, SpawnBlock(vec, ABMHardWall::StaticClass()));
				}
				//Hard blocks in fixed positions
				else if ((int)vec.X % 2 == 0 && (int)vec.Y % 2 != 0)
				{
					AddActor(vec, SpawnBlock(vec, ABMHardWall::StaticClass()));
				}
				//Destructible blocks spawns randomly
				else {
					float randomNumber = FMath::SRand();

					if (randomNumber > 0.7)
					{
						AddActor(vec, SpawnBlock(vec, ABMDestructibleWall::StaticClass()));
					}
				}
			}
		}
	}
}


ABMBaseActor* ABMBlockGrid::SpawnBlock(FVector2D blockPosition, TSubclassOf<ABMBaseActor> blockToSpawn)
{

	// Make postion vector, offset from Grid location
	// Vector2 position is transformed to the world 3D position
	const FVector BlockLocation = FVector(blockPosition.X * BlockSpacing, blockPosition.Y * BlockSpacing, 1.f) + GetActorLocation();
	const FRotator rotation = FRotator(0, 0, 0);
	// Spawn a block
	ABMBaseActor* newBlock = (ABMBaseActor*)GetWorld()->SpawnActor(blockToSpawn.Get(), &BlockLocation, &rotation);

	newBlock->SetPosition(blockPosition);


	return newBlock;
}
