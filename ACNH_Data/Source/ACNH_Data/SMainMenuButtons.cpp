// Fill out your copyright notice in the Description page of Project Settings.


#include "SMainMenuButtons.h"

void SMainMenuButtons::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	const FMargin ButtonPadding = FMargin(30.0f);

	USlateWidgetStyleAsset* CreaturesButtonStyle = LoadObject<USlateWidgetStyleAsset>(nullptr, TEXT("/Game/SlateStyles/SWSCreaturesButton.SWSCreaturesButton"));
	USlateWidgetStyleAsset* CatalogueButtonStyle = LoadObject<USlateWidgetStyleAsset>(nullptr, TEXT("/Game/Test/mainMenuButtons.mainMenuButtons"));

	ChildSlot
	[
		SNew(SVerticalBox)

		// Creature button
		+ SVerticalBox::Slot()
		[
			SNew(SButton)
			.OnClicked(this, &SMainMenuButtons::OnFishingClicked)
			.ButtonStyle(CreaturesButtonStyle)
		]

		// Catalogue button
		+ SVerticalBox::Slot()	
		[
			SNew(SButton)
			.ButtonStyle(CatalogueButtonStyle)
		]

	];
}

FReply SMainMenuButtons::OnFishingClicked() const
{
	return FReply::Handled();
}
