// Copyright Epic Games, Inc. All Rights Reserved.


#include "InventoryMinimumPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "Blueprint/UserWidget.h"
#include "InventoryMinimum.h"
#include "Widgets/Input/SVirtualJoystick.h"

#include "Components/InventoryComponent.h"
#include "Components/InventoryNetComponent.h"
#include "Components/CoinComponent.h"
#include "Components/StagingAreaComponent.h"
#include "Components/BankComponent.h"
#include "Net/UnrealNetwork.h"

AInventoryMinimumPlayerController::AInventoryMinimumPlayerController()
{

	InventoryNetComponent = CreateDefaultSubobject<UInventoryNetComponent>(TEXT("InventoryNetComponent"));

	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
	InventoryComponent->SetNetAddressable();
	InventoryComponent->SetIsReplicated(true);

	CoinComponent = CreateDefaultSubobject<UCoinComponent>(TEXT("CoinComponent"));
	CoinComponent->SetNetAddressable();
	CoinComponent->SetIsReplicated(true);

	StagingAreaComponent = CreateDefaultSubobject<UStagingAreaComponent>(TEXT("StagingAreaComponent"));
	StagingAreaComponent->SetNetAddressable();
	StagingAreaComponent->SetIsReplicated(true);

	StagingAreaCoinComponent = CreateDefaultSubobject<UCoinComponent>(TEXT("StagingAreaCoinComponent"));
	StagingAreaComponent->SetNetAddressable();
	StagingAreaComponent->SetIsReplicated(true);

	BankComponent = CreateDefaultSubobject<UBankComponent>(TEXT("BankComponent"));
	BankComponent->SetNetAddressable();
	BankComponent->SetIsReplicated(true);

	BankCoinComponent = CreateDefaultSubobject<UCoinComponent>(TEXT("BankCoinComponent"));
	BankCoinComponent->SetNetAddressable();
	BankCoinComponent->SetIsReplicated(true);

}

void AInventoryMinimumPlayerController::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AInventoryMinimumPlayerController, InventoryComponent);
	DOREPLIFETIME(AInventoryMinimumPlayerController, InventoryNetComponent);
	DOREPLIFETIME(AInventoryMinimumPlayerController, CoinComponent);
	DOREPLIFETIME(AInventoryMinimumPlayerController, StagingAreaComponent);
	DOREPLIFETIME(AInventoryMinimumPlayerController, StagingAreaCoinComponent);
	DOREPLIFETIME(AInventoryMinimumPlayerController, BankComponent);
	DOREPLIFETIME(AInventoryMinimumPlayerController, BankCoinComponent);
}

UInventoryNetComponent* AInventoryMinimumPlayerController::GetInventoryNetComponent()
{
	return InventoryNetComponent;
}

UInventoryComponent* AInventoryMinimumPlayerController::GetInventoryComponent()
{
	return InventoryComponent;
}

const UInventoryComponent* AInventoryMinimumPlayerController::GetInventoryComponentConst() const
{
	return InventoryComponent;
}

UCoinComponent* AInventoryMinimumPlayerController::GetCoinComponent()
{
	return CoinComponent;
}

const UCoinComponent* AInventoryMinimumPlayerController::GetCoinComponentConst() const
{
	return CoinComponent;
}

AActor* AInventoryMinimumPlayerController::GetInventoryOwningActor()
{
	return GetPawn();
}

const AActor* AInventoryMinimumPlayerController::GetInventoryOwningActorConst() const
{
	return GetPawn();
}

bool AInventoryMinimumPlayerController::GetTransactionBoolean()
{
	return InventoryNetComponent ? InventoryNetComponent->TransactionBoolean : false;
}

void AInventoryMinimumPlayerController::SetTransactionBoolean(bool Value)
{
	if (InventoryNetComponent)
	{
		InventoryNetComponent->TransactionBoolean = Value;
	}
}

AActor* AInventoryMinimumPlayerController::GetMerchantActor()
{
	return InventoryNetComponent ? InventoryNetComponent->MerchantActor : nullptr;
}

const AActor* AInventoryMinimumPlayerController::GetMerchantActorConst() const
{
	return InventoryNetComponent ? InventoryNetComponent->MerchantActor : nullptr;
}

void AInventoryMinimumPlayerController::SetMerchantActor(AActor* Actor)
{
	if (InventoryNetComponent)
	{
		InventoryNetComponent->MerchantActor = Actor;
	}
}

AActor* AInventoryMinimumPlayerController::GetLootedActor()
{
	return InventoryNetComponent ? InventoryNetComponent->LootedActor : nullptr;
}

const AActor* AInventoryMinimumPlayerController::GetLootedActorConst() const
{
	return InventoryNetComponent ? InventoryNetComponent->LootedActor : nullptr;
}

void AInventoryMinimumPlayerController::SetLootedActor(AActor* Actor)
{
	if (InventoryNetComponent)
	{
		InventoryNetComponent->LootedActor = Actor;
	}
}

IInventoryHUDInterface* AInventoryMinimumPlayerController::GetInventoryHUDInterface()
{
	return Cast<IInventoryHUDInterface>(MobileControlsWidget);
}

UObject* AInventoryMinimumPlayerController::GetInventoryHUDObject()
{
	return MobileControlsWidget;
}

UStagingAreaComponent* AInventoryMinimumPlayerController::GetStagingAreaItems()
{
	return StagingAreaComponent;
}

UCoinComponent* AInventoryMinimumPlayerController::GetStagingAreaCoin()
{
	return StagingAreaCoinComponent;
}

FOnWeightChanged& AInventoryMinimumPlayerController::GetWeightChangedDelegate()
{
	return OnWeightChanged;
}


void AInventoryMinimumPlayerController::BeginPlay()
{
	Super::BeginPlay();

	// only spawn touch controls on local player controllers
	if (ShouldUseTouchControls() && IsLocalPlayerController())
	{
		// spawn the mobile controls widget
		MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

		if (MobileControlsWidget)
		{
			// add the controls to the player screen
			MobileControlsWidget->AddToPlayerScreen(0);

		} else {

			UE_LOG(LogInventoryMinimum, Error, TEXT("Could not spawn mobile controls widget."));

		}

	}
}

void AInventoryMinimumPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Contexts
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

			// only add these IMCs if we're not using mobile touch input
			if (!ShouldUseTouchControls())
			{
				for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
}

bool AInventoryMinimumPlayerController::ShouldUseTouchControls() const
{
	// are we on a mobile platform? Should we force touch?
	return SVirtualJoystick::ShouldDisplayTouchInterface() || bForceTouchControls;
}
