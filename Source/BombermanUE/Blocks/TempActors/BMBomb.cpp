// Fill out your copyright notice in the Description page of Project Settings.

#include "BMBomb.h"
#include "BMExplosionBlock.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "../BMBLockGrid.h" 
#include "./Characters/BMCharacter.h"

ABMBomb::ABMBomb(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	TimeToEnd = 2;
	ConstructorHelpers::FObjectFinderOptional<UStaticMesh> sphere = TEXT("/Game/Meshes/Sphere.Sphere");
	ConstructorHelpers::FObjectFinderOptional<UMaterial> RedMaterial = TEXT("/Game/Meshes/BlackMaterial.BlackMaterial");
	BlockMesh->SetStaticMesh(sphere.Get());

	BlockMesh->SetMaterial(0, RedMaterial.Get());
	
}

void ABMBomb::EndEvent()
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("BOMB!"));

	if (HasAuthority())
	{
		((ABMCharacter*)GetOwner())->availableBombs++;

		blocks->Explosion(GetPosition(), ((ABMCharacter*)GetOwner())->bombRadius);
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
		EndEvent();
	}
}



bool ABMBomb::OnTouchedByExplosion()
{
	EndEvent();

	return true;

}


// Called every frame
void ABMBomb::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}