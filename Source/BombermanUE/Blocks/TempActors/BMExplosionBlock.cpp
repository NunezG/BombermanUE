// Fill out your copyright notice in the Description page of Project Settings.

#include "BMExplosionBlock.h"
//#include "BMGameMode.h"
//#include "BMCharacter.h"

ABMExplosionBlock::ABMExplosionBlock(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ConstructorHelpers::FObjectFinderOptional<UMaterialInstance> RedMaterial = TEXT("/Game/Meshes/RedMaterial.RedMaterial");
	BlockMesh->SetMaterial(0, RedMaterial.Get());


}

void ABMExplosionBlock::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult)
{
	if (OtherActor->GetClass()->IsChildOf(ACharacter::StaticClass()))
	{
		OtherActor->Destroy();
	}
}