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
class INVENTORYMINIMUM_API UIMGameInstance : public UGameInstance , public IInventoryGameInstanceInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	virtual UInventoryItemBase* FetchItemFromID(int32 ID) override;

	UFUNCTION(BlueprintCallable)
	virtual void RegisterItem(UInventoryItemBase* NewItem) override;

protected:
	// Item lookup table - maps ItemID to item pointer
	UPROPERTY()
	TMap<int32, UInventoryItemBase*> ItemLUT;
	
};
