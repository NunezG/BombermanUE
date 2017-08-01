// Fill out your copyright notice in the Description page of Project Settings.

#include "BMHardWall.h"


ABMHardWall::ABMHardWall(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	ConstructorHelpers::FObjectFinder<UMaterialInstance> BlueMaterial = TEXT("/Game/Meshes/BlueMaterial.BlueMaterial");

	BlockMesh->SetMaterial(0, BlueMaterial.Object);
}
