// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"

class ACNH_DATA_API SMainMenuButtons : public SCompoundWidget
{
public:
	// get ref to the hud
	SLATE_BEGIN_ARGS(SMainMenuButtons) {}

	SLATE_ARGUMENT(TWeakObjectPtr<class AMenuHUD>, OwningHUD)
	
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);
	virtual bool SupportsKeyboardFocus() const override { return true; }


	FReply OnFishingClicked() const;

	TSharedRef<SWidget> CreateButton(USlateWidgetStyleAsset* ButtonStyle,
		FReply(SMainMenuButtons::* OnClickFunc)()const,
		const FSlateBrush* ImageBrush,
		const FSlateFontInfo& FontInfo,
		const FString& ButtonText,
		const FMargin& Padding);

};
