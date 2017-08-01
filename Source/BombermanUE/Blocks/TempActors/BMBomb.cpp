// Fill out your copyright notice in the Description page of Project Settings.

#include "BMBomb.h"
#include "BMExplosionBlock.h"
#include "Engine/World.h"
#include "TimerManager.h"


ABMBomb::ABMBomb(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

	ConstructorHelpers::FObjectFinderOptional<UStaticMesh> sphere = TEXT("/Game/Meshes/Sphere.Sphere");
	ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> RedMaterial = TEXT("/Game/Meshes/BlackMaterial.BlackMaterial");
	BlockMesh->SetStaticMesh(sphere.Get());

	BlockMesh->SetMaterial(0, RedMaterial.Get());
}

void ABMBomb::EndEvent()
{

	if (HasAuthority())
	{
		//TODO Explosion
		Destroy();

	}

	Super::EndEvent();
}

void ABMBomb::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult)
{


	if (OtherActor->GetClass()->IsChildOf(ABMExplosionBlock::StaticClass()))
	{
		//TODO Explosion
		Destroy();	
	}
}

