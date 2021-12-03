#pragma once
#include "buttonlistener.h"
#include "Tool/Tool.h"
#include "DataModel/LocalBackpackItem.h"

class LocalBackpackItem;

class BackpackListener :
	public ButtonListener
{
public:
	BackpackListener(void);
	~BackpackListener(void);
	void onButton1MouseClick(LocalBackpackItem* button, bool selected);
};
