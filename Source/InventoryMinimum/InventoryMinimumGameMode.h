// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Interfaces/InventoryGameModeInterface.h"
#include "InventoryMinimumGameMode.generated.h"

/**
 *  Simple GameMode for a third person game
 */
UCLASS(abstract)
class AInventoryMinimumGameMode : public AGameModeBase, public IInventoryGameModeInterface
{
	GENERATED_BODY()

public:
	
	/** Constructor */
	AInventoryMinimumGameMode();

	//------------------------------------------------------------------------------------------------------------------
	virtual void RegisterItem(UInventoryItemBase* NewItem) override;

	virtual UInventoryItemBase* FetchItemFromID(int32 ID) override;

};



