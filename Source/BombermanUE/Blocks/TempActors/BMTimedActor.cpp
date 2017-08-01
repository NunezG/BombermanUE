// Fill out your copyright notice in the Description page of Project Settings.

#include "BMTimedActor.h"
#include "./BMGameMode.h"

ABMTimedActor::ABMTimedActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, Timer(0)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	BlockMesh->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	GetBlockMesh()->OnComponentBeginOverlap.AddDynamic(this, &ABMTimedActor::BeginOverlap);

}



void ABMTimedActor::BeginPlay()
{
	Super::BeginPlay();
	blocks = ((ABMGameMode*)GetWorld()->GetAuthGameMode())->BlockGrid;

}

// Called every frame
void ABMTimedActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Timer += DeltaTime;

	if (Timer >= TimeToEnd)
	{
		EndEvent();
	}
}

void ABMTimedActor::EndEvent()
{
	blocks->RemoveBlock(Position);
	Destroy();

}



bool ABMTimedActor::OnTouchedByExplosion()
{
	Destroy();
	return true;
 }