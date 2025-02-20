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
		SNew(SHorizontalBox)

		// Creature button
		+ SHorizontalBox::Slot()
		.FillWidth(2)
		[
			SNew(SButton)
			.ButtonStyle(CreaturesButtonStyle)
		]

		// Creature button
		+ SHorizontalBox::Slot()
		.FillWidth(1)
		[
			SNew(SSpacer)
		]


		// Catalogue button
		+ SHorizontalBox::Slot()	
		.FillWidth(2)
		[
			SNew(SButton)
			.ButtonStyle(CatalogueButtonStyle)
		]

	];
}
