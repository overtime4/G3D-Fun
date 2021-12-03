#pragma once
#include "DataModel/TextButtonInstance.h"
#include "Listener/BackpackListener.h"

class LocalBackpackItem : public TextButtonInstance
{
public:
	LocalBackpackItem(void);
	~LocalBackpackItem(void);
	void onMouseClick();
	void drawObj(RenderDevice*, Vector2, bool);
	Vector2 Size;
	Vector2 Position;
	bool item_selected;
//private:
//	Vector2 boxBegin;
//	Vector2 boxEnd;
protected:
	class BackpackListener* listener;
};
