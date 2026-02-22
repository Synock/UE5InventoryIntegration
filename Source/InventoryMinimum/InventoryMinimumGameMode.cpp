// Copyright Epic Games, Inc. All Rights Reserved.

#include "InventoryMinimumGameMode.h"
#include "IMGameInstance.h"

AInventoryMinimumGameMode::AInventoryMinimumGameMode()
{
	// stub
}

UInventoryItemBase* AInventoryMinimumGameMode::FetchItemFromID(int32 ID)
{
	if (auto* GameInstance = GetGameInstance<UIMGameInstance>())
	{
		return GameInstance->FetchItemFromID(ID);
	}

	return nullptr;
}

void AInventoryMinimumGameMode::RegisterItem(UInventoryItemBase* NewItem)
{
	if (auto* GameInstance = GetGameInstance<UIMGameInstance>())
	{
		GameInstance->RegisterItem(NewItem);
	}
}
