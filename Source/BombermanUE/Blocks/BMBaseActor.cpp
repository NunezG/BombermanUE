// Fill out your copyright notice in the Description page of Project Settings.

#include "BMBaseActor.h"
#include "Engine/StaticMesh.h"


ABMBaseActor::ABMBaseActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;

	//Replication for multiplayer
	bReplicates = true;
	bAlwaysRelevant = true;

	ConstructorHelpers::FObjectFinderOptional<UStaticMesh> cube = TEXT("/Game/Meshes/Cube.Cube");

	// Create dummy root scene component
	DummyRoot = CreateDefaultSubobject<USceneComponent>(TEXT("Dummy0"));
	RootComponent = DummyRoot;

	// Create static mesh component
	BlockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BlockMesh0"));
	BlockMesh->SetStaticMesh(cube.Get());
	BlockMesh->SetRelativeScale3D(FVector(1.f, 1.f, 1.f));
	BlockMesh->SetRelativeLocation(FVector(0.f, 0.f, 25.f));
}