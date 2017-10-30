#pragma once

#include "CoreMinimal.h"
#include "InventoryHud.h"
#include "HealthBar.h"
#include "Engine.h"
#include "Runtime/SlateCore/Public/Styling/ISlateStyle.h"
#include "Runtime/Engine/Public/Slate/SlateGameResources.h"
#include "Widgets/SCompoundWidget.h"
/**
*
*/
class INVENTORY_API SMainMenu : public SCompoundWidget
{
public:

	SLATE_BEGIN_ARGS(SMainMenu)
	{}
	SLATE_ARGUMENT(TWeakObjectPtr<class AInventoryHud>, SlateHud)
	SLATE_END_ARGS()

	void Construct(const FArguments& args);

	TWeakObjectPtr<class AInventoryHud> SlateHud;

	FReply PlayGameClicked();

	FReply PlayQuitGameClicked();

	TSharedPtr<class SHealthBar> MyHealthBar;

	~SMainMenu();
};