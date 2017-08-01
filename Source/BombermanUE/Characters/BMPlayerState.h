// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "BMPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMANUE_API ABMPlayerState : public APlayerState
{
	GENERATED_BODY()

public:

	int32 GetPlayerNum() const;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int PlayerNumber;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsPlaying;

private:


	float score;
	
};
