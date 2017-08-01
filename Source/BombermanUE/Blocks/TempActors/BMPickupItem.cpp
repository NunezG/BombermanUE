// Fill out your copyright notice in the Description page of Project Settings.

#include "BMPickupItem.h"

ABMPickupItem::ABMPickupItem(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

	TimeToEnd = 10;

	ConstructorHelpers::FObjectFinderOptional<UStaticMesh> sphere = TEXT("/Game/Meshes/Cone.Cone");
	BlockMesh->SetStaticMesh(sphere.Get());

}


void ABMPickupItem::BeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult &SweepResult)
{
	if (OtherActor->GetClass()->IsChildOf(ACharacter::StaticClass()))
	{
		Action((ACharacter*)OtherActor);
		Destroy();
	}
}