// Fill out your copyright notice in the Description page of Project Settings.

#include "BMTimedActor.h"



ABMTimedActor::ABMTimedActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, Timer(0)
{
	PrimaryActorTick.bCanEverTick = true;
	BlockMesh->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	GetBlockMesh()->OnComponentBeginOverlap.AddDynamic(this, &ABMTimedActor::BeginOverlap);

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
	Destroy();
}