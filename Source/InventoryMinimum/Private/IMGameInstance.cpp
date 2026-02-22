// Fill out your copyright notice in the Description page of Project Settings.


#include "IMGameInstance.h"
#include "Items/InventoryItemBase.h"

void UIMGameInstance::Init()
{
	Super::Init();
	LoadItems();
}

void UIMGameInstance::LoadItems()
{
	// load from data table
	if (ItemDataTable)
	{
		for (auto & Row : ItemDataTable->GetRowMap())
		{
			FItemContainerLine* ItemRow = reinterpret_cast<FItemContainerLine*>(Row.Value);
			if (ItemRow && ItemRow->Item)
			{
				ItemLUT.Add(ItemRow->Item->ItemID, ItemRow->Item);
			}
		}
	}

	// Load from manual array
	for (UInventoryItemBase* Item : ItemTable)
	{
		if (Item && Item->ItemID >= 0)
		{
			ItemLUT.Add(Item->ItemID, Item);
		}
	}

	UE_LOG(LogTemp, Log, TEXT("Item LUT Table Load Completed"));

	UE_LOG(LogTemp, Log, TEXT("Inventory: Registered %d items"), ItemLUT.Num());

}

UInventoryItemBase* UIMGameInstance::FetchItemFromID(int32 ID)
{
	if (UInventoryItemBase** Found = ItemLUT.Find(ID))
		return *Found;

	return nullptr;
}

void UIMGameInstance::RegisterItem(UInventoryItemBase* NewItem)
{
	if (NewItem && NewItem->ItemID >= 0)
		ItemLUT.Add(NewItem->ItemID, NewItem);

}

UTexture2D* UIMGameInstance::GetCopperCoinIconTexture() const
{
	return CopperCoinIconTexture;
}

UTexture2D* UIMGameInstance::GetSilverCoinIconTexture() const
{
	return SilverCoinIconTexture;
}

UTexture2D* UIMGameInstance::GetGoldCoinIconTexture() const
{
	return GoldCoinIconTexture;
}

UTexture2D* UIMGameInstance::GetPlatinumCoinIconTexture() const
{
	return PlatinumCoinIconTexture;
}

