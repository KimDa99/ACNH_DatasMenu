// Fill out your copyright notice in the Description page of Project Settings.

#include "SMenuWidget.h"

#include "SMainMenuButtons.h"
#include "MenuHUD.h"

// for localization
#define LOCTEXT_NAMESPACE "MainMenu"

void SMenuWidget::Construct(const FArguments& InArgs)
{
	bCanSupportFocus = true;

	OwningHUD = InArgs._OwningHUD;

	const FMargin ContentPadding = FMargin(500.0f, 300.0f);
	const FMargin ButtonPadding = FMargin(10.0f);

	const FText TitleText = LOCTEXT("GameTitle", "ACNH Data Center");
	const FText FishingText = LOCTEXT("Fishing", "Fishing");
	const FText QuitText = LOCTEXT("Quit", "Quit");

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;

	FSlateFontInfo TitleTextStyle = ButtonTextStyle;
	TitleTextStyle.Size = 60.f;

	FString BackGroundImagePath = "/Game/Images/MainBackGround.MainBackGround";
	UTexture2D* BackgroundTexture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/Images/Phone_Background.Phone_Background"));
	FSlateBrush* BackgroundBrush = new FSlateBrush();


	if (BackgroundTexture)
	{
		BackgroundBrush->SetResourceObject(BackgroundTexture);
		BackgroundBrush->ImageSize = FVector2D(1920.0f, 1080.0f); // 적절한 해상도로 설정
	}

	USlateWidgetStyleAsset* ButtonStyle = LoadObject<USlateWidgetStyleAsset>(nullptr, TEXT("/Game/Test/mainMenuButtons.mainMenuButtons"));

	ChildSlot
		[
			SNew(SOverlay)
			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			[
				SNew(SImage)
				.Image(BackgroundBrush)
				//.ColorAndOpacity(FColor::Blue)
			]

			+SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(ContentPadding)
			
			[
				SNew(SVerticalBox)
				
				// Ttile Text
				+SVerticalBox::Slot()
				[
					SNew(STextBlock)
					.Font(TitleTextStyle)
					.Text(TitleText)
					.Justification(ETextJustify::Center)
				]

				// Buttons box
				+SVerticalBox::Slot()
				
				.Padding(ButtonPadding)
				[
					SNew(SMainMenuButtons)			
				]

				//	// Quit Button
				//	+SHorizontalBox::Slot()
				//	.Padding(ButtonPadding)
				//	[
				//		SNew(SButton)
				//		.OnClicked(this, &SMenuWidget::OnQuitClicked)
				//		.VAlign(VAlign_Center)
				//		[
				//			SNew(STextBlock)
				//			.Font(ButtonTextStyle)
				//			.Text(QuitText)
				//			.Justification(ETextJustify::Center)
				//		]
				//	]

				//]
			
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