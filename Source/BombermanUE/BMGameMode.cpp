// Fill out your copyright notice in the Description page of Project Settings.

#include "BMGameMode.h"
#include "BombermanUE.h"

#include "Characters/BMCharacter.h"
#include "./Characters/BMPlayerState.h"
#include "Characters/BMPlayerController.h"
//#include "BMGameState.h"

ABMGameMode::ABMGameMode(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer)
{

	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnOb(TEXT("/Game/Blueprints/Pawns/PlayerPawn"));
//	DefaultPawnClass = PlayerPawnOb.Class;

	PlayerControllerClass = ABMPlayerController::StaticClass();
	PlayerStateClass = ABMPlayerState::StaticClass();
	//GameStateClass = ABMGameState::StaticClass();
}



void ABMGameMode::SpawnABomb(FVector2D position)
{
	BlockGridd->blocksMap.Add(position, BlockGridd->SpawnBlock(position, ABMBomb::StaticClass()));
}