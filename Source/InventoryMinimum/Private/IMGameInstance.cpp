// Fill out your copyright notice in the Description page of Project Settings.


#include "IMGameInstance.h"
#include "Items/InventoryItemBase.h"

UInventoryItemBase* UIMGameInstance::FetchItemFromID(int32 ID)
{
	if (ItemLUT.Contains(ID))
		return ItemLUT[ID];

	UE_LOG(LogTemp, Warning, TEXT("Item ID not found"));
	return nullptr;
}

void UIMGameInstance::RegisterItem(UInventoryItemBase* NewItem)
{
	if (!NewItem)
	{
		UE_LOG(LogTemp, Warning, TEXT("Item ID not found"));
		return;
	}

	if (NewItem->ItemID < 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Item ID is invalid"));
		return;
	}

	if (ItemLUT.Contains(NewItem->ItemID))
	{
		UE_LOG(LogTemp, Warning, TEXT("Item ID already exists"));
	}

	ItemLUT.Add(NewItem->ItemID, NewItem);
	UE_LOG(LogTemp, Log, TEXT("Registered item: %s (ID: %d)"),
		*NewItem->Name, NewItem->ItemID);

}