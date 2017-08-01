// Fill out your copyright notice in the Description page of Project Settings.

#include "BMDestructibleWall.h"


ABMDestructibleWall::ABMDestructibleWall(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ConstructorHelpers::FObjectFinder<UMaterialInstance> BlueMaterial = TEXT("/Game/Meshes/OrangeMaterial.OrangeMaterial");

	BlockMesh->SetMaterial(0, BlueMaterial.Object);
	BlockMesh->SetupAttachment(DummyRoot);
}

