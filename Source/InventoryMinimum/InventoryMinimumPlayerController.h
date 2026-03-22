// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Interfaces/InventoryPlayerInterface.h"
#include "InventoryMinimumPlayerController.generated.h"

class UInputMappingContext;
class UUserWidget;

class UInventoryComponent;
class UCoinComponent;
class UStagingAreaComponent;
class UBankComponent;
class UInventoryNetComponent;

/**
 *  Basic PlayerController class for a third person game
 *  Manages input mappings
 */
UCLASS()
class AInventoryMinimumPlayerController : public APlayerController, public IInventoryPlayerInterface
{
	GENERATED_BODY()

public:
	AInventoryMinimumPlayerController();

	virtual UInventoryNetComponent* GetInventoryNetComponent() override;
	virtual UInventoryComponent* GetInventoryComponent() override;
	virtual const UInventoryComponent* GetInventoryComponentConst() const override;
	virtual UCoinComponent* GetCoinComponent() override;
	virtual const UCoinComponent* GetCoinComponentConst() const override;

	virtual AActor* GetInventoryOwningActor() override;
	virtual AActor const* GetInventoryOwningActorConst() const override;

	virtual bool GetTransactionBoolean() override;
	virtual void SetTransactionBoolean(bool Value) override;

	virtual AActor* GetMerchantActor() override;
	virtual const AActor* GetMerchantActorConst() const override;
	virtual void SetMerchantActor(AActor* Actor) override;

	virtual AActor* GetLootedActor() override;
	virtual const AActor* GetLootedActorConst() const override;
	virtual void SetLootedActor(AActor* Actor) override;

	virtual IInventoryHUDInterface* GetInventoryHUDInterface() override;
	virtual UObject* GetInventoryHUDObject() override;

	virtual UCoinComponent* GetStagingAreaCoin() override;
	virtual UStagingAreaComponent* GetStagingAreaItems() override;

	virtual FOnWeightChanged& GetWeightChangedDelegate() override;



protected:

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Inventory")
	UInventoryComponent* InventoryComponent;

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Inventory")
	UInventoryNetComponent* InventoryNetComponent;

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Inventory")
	UCoinComponent* CoinComponent;

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Inventory")
	UCoinComponent* StagingAreaCoinComponent;

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Inventory")
	UStagingAreaComponent* StagingAreaComponent;

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Inventory")
	UBankComponent* BankComponent;

	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Inventory")
	UCoinComponent* BankCoinComponent;

	UPROPERTY()
	UObject* InventoryHUDObject = nullptr;

	UPROPERTY(BlueprintAssignable, Category = "Inventory")
	FOnWeightChanged OnWeightChanged;

	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;


	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category ="Input|Input Mappings")
	TArray<UInputMappingContext*> DefaultMappingContexts;

	/** Input Mapping Contexts */
	UPROPERTY(EditAnywhere, Category="Input|Input Mappings")
	TArray<UInputMappingContext*> MobileExcludedMappingContexts;

	/** Mobile controls widget to spawn */
	UPROPERTY(EditAnywhere, Category="Input|Touch Controls")
	TSubclassOf<UUserWidget> MobileControlsWidgetClass;

	/** Pointer to the mobile controls widget */
	UPROPERTY()
	TObjectPtr<UUserWidget> MobileControlsWidget;

	/** If true, the player will use UMG touch controls even if not playing on mobile platforms */
	UPROPERTY(EditAnywhere, Config, Category = "Input|Touch Controls")
	bool bForceTouchControls = false;

	/** Gameplay initialization */
	virtual void BeginPlay() override;

	/** Input mapping context setup */
	virtual void SetupInputComponent() override;

	/** Returns true if the player should use UMG touch controls */
	bool ShouldUseTouchControls() const;

};
