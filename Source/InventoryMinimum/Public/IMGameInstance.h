// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/InventoryGameInstanceInterface.h"
#include "IMGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYMINIMUM_API UIMGameInstance : public UGameInstance, public IInventoryGameInstanceInterface
{
	GENERATED_BODY()

public:
	virtual UInventoryItemBase* FetchItemFromID(int32 ID) override;

	virtual void RegisterItem(UInventoryItemBase* NewItem) override;

	virtual UTexture2D* GetCopperCoinIconTexture() const override;

	virtual UTexture2D* GetSilverCoinIconTexture() const override;

	virtual UTexture2D* GetGoldCoinIconTexture() const override;

	virtual UTexture2D* GetPlatinumCoinIconTexture() const override;

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Inventory|Currency")
	UTexture2D* CopperCoinIconTexture = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory|Currency")
	UTexture2D* SilverCoinIconTexture = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory|Currency")
	UTexture2D* GoldCoinIconTexture = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory|Currency")
	UTexture2D* PlatinumCoinIconTexture = nullptr;

	UPROPERTY()
	TMap<int32, UInventoryItemBase*> ItemLUT;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	UDataTable* ItemDataTable = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TArray<UInventoryItemBase*> ItemTable;

	virtual void Init() override;

	void LoadItems();

};
