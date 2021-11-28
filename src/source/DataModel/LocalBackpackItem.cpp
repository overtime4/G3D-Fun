#include "DataModel/LocalBackpackItem.h"
#include <iostream>
LocalBackpackItem::LocalBackpackItem(){
	Size = Vector2(100,100);
	Position = Vector2(0,-100);
	floatRight = false;
	floatCenter = false;
	visible = true;
	className = "LocalBackpackItem";
	disabled = false;
	selected = false;
	textColor = Color3(1.0F,1.0F,1.0F);
	textSize = 14;
	fontLocationRelativeTo = Vector2(15, 40);

	item_selected = false;
	floatBottom = true;
}
void LocalBackpackItem::onMouseClick()
{
	if (item_selected){
		item_selected = false;
		std::cout << "Unequip";
	}else{
		item_selected = true;
		std::cout << "Equip";
	}
}

void LocalBackpackItem::drawObj(RenderDevice* rd, Vector2 mousePos, bool mouseDown)
{
	boxBegin = Position;
	boxEnd = Position+Size;
	Vector3 point1;
	Vector3 point2;
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_COLOR_ARRAY);
	
	if(floatBottom)
	{
		point1 = Vector3(boxBegin.x, rd->getHeight() + boxBegin.y,0);
		point2 = Vector3(boxEnd.x, rd->getHeight() + boxEnd.y,0);
		
	}
	else
	{
		point1 = Vector3(boxBegin.x, boxBegin.y,0);
		point2 = Vector3(boxEnd.x, boxEnd.y,0);
	}

	Vector3 midpoint1;
	Vector3 midpoint2;
	midpoint1 = Vector3(point1.x + 10, point1.y + 10 ,0);
	midpoint2 = Vector3(point2.x - 10, point2.y - 10, 0);

	Vector3 keypoint1;
	Vector3 keypoint2;
	keypoint1 = Vector3(point1.x + 2, point2.y - 22 ,0);
	keypoint2 = keypoint1 + Vector3(20,20,0);

	//Draw::box(Box(midpoint1, midpoint2), rd, Color4(1.0F,1.0F,1.0F,0.2F), boxOutlineColorDis);
	Vector2 RelativeTo = Vector2(point1.x + fontLocationRelativeTo.x, point1.y + fontLocationRelativeTo.y);
	Color4 outcolor;

	if(item_selected == true){
		outcolor = Color4(0.0F,1.0F,0.0F,0.5F);
	}else{
		outcolor = Color4(0.0F,0.0F,0.0F,0.0F);
	}

	if(disabled)
	{
		Draw::box(Box(point1, point2), rd, boxColorDis, outcolor);
		font->draw2D(rd, title, RelativeTo, textSize, textColorDis, textOutlineColorDis);
	}
	else if(mouseInArea(point1.x, point1.y, point2.x, point2.y, mousePos.x, mousePos.y) && mouseDown)
	{
		Draw::box(Box(point1, point2), rd, Color4(1.0F,1.0F,0.0F,1.0F), outcolor);
		font->draw2D(rd, title, RelativeTo, textSize, textColor, textOutlineColorDn);
	}
	else if(selected || mouseInArea(point1.x, point1.y, point2.x, point2.y, mousePos.x, mousePos.y))
	{
		Draw::box(Box(point1, point2), rd, boxColorOvr, outcolor);
		font->draw2D(rd, title, RelativeTo, textSize, textColor, textOutlineColorOvr);
	}
	else
	{
		Draw::box(Box(point1, point2), rd, boxColor, outcolor);
		font->draw2D(rd, title, RelativeTo, textSize, textColor, textOutlineColor);
	}
	Draw::box(Box(keypoint1, keypoint2), rd, Color4(0.8F,0.8F,0.8F,0.4F), boxOutlineColorDis);
	font->draw2D(rd, "1", Vector2(keypoint1.x + 4,keypoint1.y+2), 11, textColor, textOutlineColor);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);
}
LocalBackpackItem::~LocalBackpackItem(){

}