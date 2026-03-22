// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Components/InventoryNetComponent.h>
#include "UFinalInventoryNetComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class INVENTORYMINIMUM_API UUFinalInventoryNetComponent : public UInventoryNetComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UUFinalInventoryNetComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual void HandlePlayerLootItem(int32 InTopLeft, EBagSlot InSlot, int32 InItemId, int32 OutTopLeft) override;

public:
};
