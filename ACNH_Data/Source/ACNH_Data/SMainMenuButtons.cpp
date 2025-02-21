// Fill out your copyright notice in the Description page of Project Settings.

#include "SMainMenuButtons.h"

#include "Widgets/Layout/SScaleBox.h"

void SMainMenuButtons::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	USlateWidgetStyleAsset* ButtonStyle = LoadObject<USlateWidgetStyleAsset>(nullptr, TEXT("/Game/SlateStyles/MainMenuButtons.MainMenuButtons"));
	USlateWidgetStyleAsset* CatalogueButtonStyle = LoadObject<USlateWidgetStyleAsset>(nullptr, TEXT("/Game/Test/mainMenuButtons.mainMenuButtons"));

	UObject* Font;
	Font = LoadObject<UObject>(nullptr, TEXT("/Game/Fonts/nintendoP_Humming-E_002pr_Font.nintendoP_Humming-E_002pr_Font"));
	FSlateFontInfo ButtonStyleText = FSlateFontInfo(Font, 60);

	UTexture2D* CreatureButtonTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/Images/Creatures_Button.Creatures_Button"));
	FSlateBrush* CreatureBrush = new FSlateBrush();
	CreatureBrush->SetResourceObject(CreatureButtonTexture);
	CreatureBrush->SetImageSize(FVector2D(256.f, 256.f));

	UTexture2D* ShoppingButtonTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/Images/Shopping_Button.Shopping_Button"));
	FSlateBrush* ShoppingBrush = new FSlateBrush();
	ShoppingBrush->SetResourceObject(ShoppingButtonTexture);
	ShoppingBrush->SetImageSize(FVector2D(256.f, 256.f));

	const FMargin ButtonPadding(20.f);

	ChildSlot
	[
		SNew(SVerticalBox)

		// Creature button
		+SVerticalBox::Slot()
		.AutoHeight()
		.Padding(ButtonPadding)
		.HAlign(HAlign_Left)
		[
			CreateButton(ButtonStyle, &SMainMenuButtons::OnFishingClicked, CreatureBrush, ButtonStyleText, "Fishing", ButtonPadding)
		]

		// Shopping button
		+SVerticalBox::Slot()
		.AutoHeight()
		.Padding(ButtonPadding)		
		.HAlign(HAlign_Left)
		[
			CreateButton(ButtonStyle, &SMainMenuButtons::OnFishingClicked, ShoppingBrush, ButtonStyleText, "Catalogue", ButtonPadding)
		]

	];
}

FReply SMainMenuButtons::OnFishingClicked() const
{
	return FReply::Handled();
}

TSharedRef<SWidget> SMainMenuButtons::CreateButton(USlateWidgetStyleAsset* ButtonStyle, FReply(SMainMenuButtons::* OnClickFunc)() const, const FSlateBrush* ImageBrush, const FSlateFontInfo& FontInfo, const FString& ButtonText, const FMargin& Padding)
{
	return SNew(SScaleBox)
		[
			SNew(SButton)
			.OnClicked(this, OnClickFunc)
			.ButtonStyle(ButtonStyle)
			.VAlign(VAlign_Center)
			[
				SNew(SHorizontalBox)

				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(Padding)
				.VAlign(VAlign_Center)
				[
					SNew(SImage)
					.Image(ImageBrush)
				]

				+ SHorizontalBox::Slot()
				.AutoWidth()
				.Padding(Padding)
				.VAlign(VAlign_Top)
				[
					SNew(STextBlock)
						.Font(FontInfo)
						.Text(FText::FromString(ButtonText))
						.ColorAndOpacity(FColor::Black)
				]
			]

		];

}
