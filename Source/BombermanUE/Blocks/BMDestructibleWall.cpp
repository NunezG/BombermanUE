// Fill out your copyright notice in the Description page of Project Settings.

#include "BMDestructibleWall.h"
#include "BMGameMode.h"

ABMDestructibleWall::ABMDestructibleWall(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ConstructorHelpers::FObjectFinder<UMaterialInstance> BlueMaterial = TEXT("/Game/Meshes/OrangeMaterial.OrangeMaterial");

	BlockMesh->SetMaterial(0, BlueMaterial.Object);

}


void ABMDestructibleWall::BeginPlay()
{
	blocks = ((ABMGameMode*)GetWorld()->GetAuthGameMode())->BlockGrid;
}

bool ABMDestructibleWall::OnTouchedByExplosion()
{

	//Breaks wall
	blocks->blocksMap.Remove(GetPosition());

	DropItem(Position);

	Destroy();

	return true;
}


bool ABMDestructibleWall::DropItem(FVector2D position)
{
	float randomNum = FMath::SRand();

	if (randomNum > 0.7f && blocks->Pickups.Num() > 0)
	{

		float randomselector = FMath::SRand();

		int pickupPos = FMath::Round(randomselector * (blocks->Pickups.Num() - 1));

		blocks->blocksMap.Add(position, blocks->SpawnBlock(position, blocks->Pickups[pickupPos].Get()));

		return true;
	}

	return false;
}