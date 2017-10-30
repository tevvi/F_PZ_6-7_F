
#include "SMainMenu.h"






BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION
void SMainMenu::Construct(const SMainMenu::FArguments &args)
{
	SlateHud = args._SlateHud;

	//Load Style

	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Top)
			[
				SNew(SBox)
				.HeightOverride(200)
				.WidthOverride(200)
				[
					SAssignNew(MyHealthBar ,SHealthBar)
					.SlateHud(SlateHud)
					.TotalHealth(100)
					.Health(100)
				]
			]
			+ SOverlay::Slot()
			.HAlign(HAlign_Right)
			.VAlign(VAlign_Bottom)
			[
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				[
					SNew(SBox)
					.HeightOverride(200)
					.WidthOverride(200)
					[
						SNew(SButton)
						.Text(FText::FromString("Play Game"))
						.OnClicked(this, &SMainMenu::PlayGameClicked)
					]
				]
				+ SVerticalBox::Slot()
				[
					SNew(SButton)
					.Text(FText::FromString("Quit Game"))
					.OnClicked(this, &SMainMenu::PlayQuitGameClicked)
				]
			]
		];
}
END_SLATE_FUNCTION_BUILD_OPTIMIZATION

FReply SMainMenu::PlayGameClicked()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("PlayGameClicked"));
	}
	MyHealthBar->Health = (MyHealthBar->Health + 10 ) % 100;
	MyHealthBar->SetPercentage();
	return FReply::Handled();
}

FReply SMainMenu::PlayQuitGameClicked()
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Yellow, TEXT("QuitGameClicked"));
		//SlateHud->
	}
	if(MyHealthBar->Health - 10 > 0)
		MyHealthBar->Health = MyHealthBar->Health - 10;
	MyHealthBar->SetPercentage();
	return FReply::Handled();
}


SMainMenu::~SMainMenu()
{
}



