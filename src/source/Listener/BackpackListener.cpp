#include "Listener/BackpackListener.h"
#include "Application.h"
#include "Globals.h"
#include "Tool/ArrowTool.h"
BackpackListener::BackpackListener()
{

}
BackpackListener::~BackpackListener()
{

}
void BackpackListener::onButton1MouseClick(LocalBackpackItem* button, bool selected)
{
	std::cout << "Hopper found; selecting" << std::endl;
	if(selected)
	{
		g_usableApp->changeTool(new ArrowTool());
	}
	else
	{
		g_usableApp->changeTool(new Tool());
	}
}