// Fill out your copyright notice in the Description page of Project Settings.

#include "SMenuWidget.h"

#include "SlateCore.h"
#include "SMainMenuButtons.h"
#include "MenuHUD.h"
#include "Widgets/Layout/SScaleBox.h"

// for localization
#define LOCTEXT_NAMESPACE "MainMenu"

void SMenuWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	OwningHUD = InArgs._OwningHUD;

	UTexture2D* BackgroundTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/Images/MainMenu_Background.MainMenu_Background"));
	FSlateBrush* BackgroundBrush = new FSlateBrush();
	BackgroundBrush->SetResourceObject(BackgroundTexture);

	UTexture2D* BoardTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/Images/MainMenu_Board.MainMenu_Board"));
	FSlateBrush* BoardBrush = new FSlateBrush();
	BoardBrush->SetResourceObject(BoardTexture);

	UTexture2D* LogoTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/Images/MainMenu_Logo.MainMenu_Logo"));
	FSlateBrush* LogoBrush = new FSlateBrush();
	LogoBrush->SetResourceObject(LogoTexture);
	LogoBrush->SetImageSize(FVector2D(1024.f, 1024.f));

	ChildSlot
		[
			
			SNew(SOverlay)
			+SOverlay::Slot()	
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage)
				.Image(BackgroundBrush)
				
			]

			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(50.0f)
			[
				SNew(SImage)
				.Image(BoardBrush)
			]

			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(100.0f)
			[
				SNew(SHorizontalBox)
				
				+SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Center)
				.FillWidth(1)
				[
					SNew(SScaleBox)
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					.Stretch(EStretch::ScaleToFit)
					[
						SNew(SImage)
						.Image(LogoBrush)						
					]
				]

				// Buttons box
				+SHorizontalBox::Slot()
				.VAlign(VAlign_Center)
				.HAlign(HAlign_Center)
				.FillWidth(1)
				[			
					SNew(SScaleBox)
					.HAlign(HAlign_Center)
					.VAlign(VAlign_Center)
					.Stretch(EStretch::ScaleToFit)
					[
						SNew(SMainMenuButtons)
					]
				]
			]
		];

}

FReply SMenuWidget::OnQuitClicked() const
{
	if (OwningHUD.IsValid())
	{
		if (APlayerController* PC = OwningHUD->PlayerOwner)
		{
			PC->ConsoleCommand("quit");
		}
	}

	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE