#include <iomanip>
#include <sstream>
#include "G3DAll.h"
#include "DataModel/BaseButtonInstance.h"
#include "DataModel/TextButtonInstance.h"
#include "DataModel/ImageButtonInstance.h"
#include "DataModel/ToggleImageButtonInstance.h"
#include "DataModel/GuiRootInstance.h"
#include "DataModel/ImageButtonInstance.h"
#include "DataModel/LocalBackpackItem.h"
#include "Globals.h"
#include "StringFunctions.h"

#include "Listener/GUDButtonListener.h"
#include "Listener/ModeSelectionListener.h"
#include "Listener/MenuButtonListener.h"
#include "Listener/RotateButtonListener.h"
#include "Listener/CameraButtonListener.h"
#include "Listener/DeleteListener.h"
#include "Listener/ToolbarListener.h"


ImageButtonInstance* GuiRootInstance::makeImageButton(G3D::TextureRef newImage = NULL, G3D::TextureRef overImage = NULL, G3D::TextureRef downImage = NULL, G3D::TextureRef disableImage = NULL)
{
	ImageButtonInstance* part = new ImageButtonInstance(newImage,overImage, downImage, disableImage);
//	instances.push_back(part);
//	instances_2D.push_back(part);
	return part;
}

TextButtonInstance* GuiRootInstance::makeTextButton()
{
	TextButtonInstance* part = new TextButtonInstance();
	return part;
}

LocalBackpackItem* GuiRootInstance::makeLocalBackpackItem()
{
	LocalBackpackItem* part = new LocalBackpackItem();
	return part;
}
ToolbarListener * toolbar;
GuiRootInstance::GuiRootInstance() : _message(""), _messageTime(0)
{
	toolbar = new ToolbarListener();
	toolbar->doDelete = false;
	g_fntdominant = GFont::fromFile(GetFileInPath("/content/font/dominant.fnt"));
	g_fntlighttrek = GFont::fromFile(GetFileInPath("/content/font/lighttrek.fnt"));

	//Bottom Left
	TextButtonInstance* button = makeTextButton();
	button->boxBegin = Vector2(0, 0);
	button->boxEnd = Vector2(100, 20);
	button->setParent(this);
	button->font = g_fntlighttrek;
	button->textColor = Color3(0.3F,0.3F,0.3F);
	button->boxColor = Color4(0.6F,0.6F,0.6F,0.4F);
	button->textOutlineColor = Color4(0.0F,0.0F,0.0F,0.0F);
	button->title = "Help...";
	button->textSize = 12;
	button->fontLocationRelativeTo = Vector2(10, 0);
	button->setAllColorsSame();
	button->boxColorOvr = Color4(0.4F,0.4F,0.4F,0.4F);
	button->name = "help";
	button->setButtonListener(new MenuButtonListener());

	button = makeTextButton();
	button->boxBegin = Vector2(100, 0);
	button->boxEnd = Vector2(200, 20);
	button->setParent(this);
	button->font = g_fntlighttrek;
	button->textColor = Color3(0.3F,0.3F,0.3F);
	button->boxColor = Color4(0.6F,0.6F,0.6F,0.4F);
	button->textOutlineColor = Color4(0.0F,0.0F,0.0F,0.0F);
	button->title = "Fullscreen";
	button->textSize = 12;
	button->fontLocationRelativeTo = Vector2(10, 0);
	button->setAllColorsSame();
	button->boxColorOvr = Color4(0.4F,0.4F,0.4F,0.4F);
	button->name = "fullscreen";
	button->setButtonListener(new MenuButtonListener());

	button = makeTextButton();
	button->boxBegin = Vector2(200, 0);
	button->boxEnd = Vector2(300, 20);
	button->setParent(this);
	button->font = g_fntlighttrek;
	button->textColor = Color3(0.3F,0.3F,0.3F);
	button->boxColor = Color4(0.6F,0.6F,0.6F,0.4F);
	button->textOutlineColor = Color4(0.0F,0.0F,0.0F,0.0F);
	button->title = "Exit";
	button->textSize = 12;
	button->fontLocationRelativeTo = Vector2(10, 0);
	button->setAllColorsSame();
	button->boxColorOvr = Color4(0.4F,0.4F,0.4F,0.4F);
	button->name = "exit";
	button->setButtonListener(new MenuButtonListener());

	button = makeLocalBackpackItem();
	button->setParent(this);
	button->font = g_fntlighttrek;
	button->title = "Test";
	//button->name = "item";

	ImageButtonInstance* instance = makeImageButton(
		Texture::fromFile(GetFileInPath("/content/images/CameraTiltUp.png")),
		Texture::fromFile(GetFileInPath("/content/images/CameraTiltUp_ovr.png")),
		Texture::fromFile(GetFileInPath("/content/images/CameraTiltUp_dn.png")));
	instance->size = Vector2(32,32);
	instance->floatBottom = true;
	instance->floatRight = true;
	instance->position = Vector2(-64, -64);
	instance->setParent(this);
	instance->name = "TiltUp";
	instance->setButtonListener(new CameraButtonListener());

	instance = makeImageButton(
		Texture::fromFile(GetFileInPath("/content/images/CameraTiltDown.png")),
		Texture::fromFile(GetFileInPath("/content/images/CameraTiltDown_ovr.png")),
		Texture::fromFile(GetFileInPath("/content/images/CameraTiltDown_dn.png")));
	instance->size = Vector2(32,32);
	instance->floatBottom = true;
	instance->floatRight = true;
	instance->position = Vector2(-64, -32);
	instance->setParent(this);
	instance->name = "TiltDown";
	instance->setButtonListener(new CameraButtonListener());

	instance = makeImageButton(
		Texture::fromFile(GetFileInPath("/content/images/CameraZoomIn.png")),
		Texture::fromFile(GetFileInPath("/content/images/CameraZoomIn_ovr.png")),
		Texture::fromFile(GetFileInPath("/content/images/CameraZoomIn_dn.png")));
	instance->size = Vector2(32,32);
	instance->floatBottom = true;
	instance->floatRight = true;
	instance->position = Vector2(-32, -64);
	instance->setParent(this);
	instance->name = "ZoomIn";
	instance->setButtonListener(new CameraButtonListener());

	instance = makeImageButton(
		Texture::fromFile(GetFileInPath("/content/images/CameraZoomOut.png")),
		Texture::fromFile(GetFileInPath("/content/images/CameraZoomOut_ovr.png")),
		Texture::fromFile(GetFileInPath("/content/images/CameraZoomOut_dn.png")));
	instance->size = Vector2(32,32);
	instance->floatBottom = true;
	instance->floatRight = true;
	instance->position = Vector2(-32, -32);
	instance->setParent(this);
	instance->name = "ZoomOut";
	instance->setButtonListener(new CameraButtonListener());
	
	
}


void GuiRootInstance::drawButtons(RenderDevice* rd)
{
	rd->pushState();
	rd->beforePrimitive();
			//this->render(rd);
	rd->afterPrimitive();
	rd->popState();
}

void GuiRootInstance::setDebugMessage(std::string msg, G3D::RealTime msgTime)
{
	_messageTime = msgTime;
	_message = msg;
}

//void GuiRootInstance::render(G3D::RenderDevice* renderDevice) {}

void GuiRootInstance::renderGUI(G3D::RenderDevice* rd, double fps)
{
	//TODO--Move these to their own instance

	std::stringstream stream;
	stream << std::fixed << std::setprecision(1) << g_dataModel->getLevel()->timer;
	//FPS
#ifdef _DEBUG
	stream.str("");
    stream.clear();
    stream << std::fixed << std::setprecision(3) << fps;
    g_fntdominant->draw2D(rd, "FPS: " + stream.str(), Vector2(120, 25), 10, Color3::fromARGB(0xFFFF00), Color3::black());
#endif
	
	//drawButtons(rd);
	if(System::time() - 3 < _messageTime)
	{
		g_fntdominant->draw2D(rd, _message, Vector2((rd->getWidth()/2)-(g_fntdominant->get2DStringBounds(_message, 20).x/2),(rd->getHeight()/2)-(g_fntdominant->get2DStringBounds(_message, 20).y/2)), 20, Color3::yellow(), Color3::black());
	}

	g_dataModel->drawMessage(rd);
	render(rd);
}

bool GuiRootInstance::mouseInGUI(G3D::RenderDevice* renderDevice,int x,int y)
{
	std::vector<Instance*> instances_2D = g_dataModel->getGuiRoot()->getAllChildren();
	for(size_t i = 0; i < instances_2D.size(); i++)
	{
		if(BaseButtonInstance* button = dynamic_cast<BaseButtonInstance*>(instances_2D.at(i)))
		{
			if(button->mouseInButton(x,y, renderDevice))
			{
				return true;
			}
		}
	}
	return false;
}

void GuiRootInstance::update()
{		
	Instance * obj6 = this->findFirstChild("Delete");
	Instance * obj = this->findFirstChild("Duplicate");
	Instance * obj2 = this->findFirstChild("Group");
	Instance * obj3 = this->findFirstChild("UnGroup");
	Instance * obj4 = this->findFirstChild("Rotate");
	Instance * obj5 = this->findFirstChild("Tilt");
	if(obj != NULL && obj2 != NULL && obj3 != NULL && obj4 !=NULL && obj5 != NULL && obj6 != NULL)
	{
		BaseButtonInstance* button = (BaseButtonInstance*)obj;
		BaseButtonInstance* button2 = (BaseButtonInstance*)obj2;
		BaseButtonInstance* button3 = (BaseButtonInstance*)obj3;
		BaseButtonInstance* button4 = (BaseButtonInstance*)obj4;
		BaseButtonInstance* button5 = (BaseButtonInstance*)obj5;
		BaseButtonInstance* button6 = (BaseButtonInstance*)obj6;
		button->disabled = true;
		button2->disabled = true;
		button3->disabled = true;
		button4->disabled = true;
		button5->disabled = true;
		button6->disabled = true;
		for(size_t i = 0; i < g_selectedInstances.size(); i++)
			if(g_selectedInstances.at(i)->canDelete)
			{
				button->disabled = false;
				button2->disabled = false;
				button3->disabled = false;
				button4->disabled = false;
				button5->disabled = false;
				button6->disabled = false;
				break;
			}
	}
}

GuiRootInstance::~GuiRootInstance()
{
	delete toolbar;
}

void GuiRootInstance::onMouseLeftUp(G3D::RenderDevice* renderDevice, int x,int y)
{
	std::vector<Instance*> instances_2D = this->getAllChildren();
	for(size_t i = 0; i < instances_2D.size(); i++)
	{
		if(BaseButtonInstance* button = dynamic_cast<BaseButtonInstance*>(instances_2D[i]))
		{
			if(button->mouseInButton(x, y, renderDevice))
			{
				button->onMouseClick();
			}
		}
	}
}
