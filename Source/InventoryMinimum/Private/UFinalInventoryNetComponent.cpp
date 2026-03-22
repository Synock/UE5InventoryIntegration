// Fill out your copyright notice in the Description page of Project Settings.


#include "UFinalInventoryNetComponent.h"


// Sets default values for this component's properties
UUFinalInventoryNetComponent::UUFinalInventoryNetComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UUFinalInventoryNetComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...

}

void UUFinalInventoryNetComponent::HandlePlayerLootItem(int32 InTopLeft, EBagSlot InSlot, int32 InItemId,
	int32 OutTopLeft)
{
	Super::HandlePlayerLootItem(InTopLeft, InSlot, InItemId, OutTopLeft);

	// Do something fun here
}
