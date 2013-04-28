#include "misc/Cgdi.h"

#include "cocos2d.h"

//--------------------------- Instance ----------------------------------------
//
//   this class is a singleton
//-----------------------------------------------------------------------------
Cgdi* Cgdi::Instance()
{
  static Cgdi instance;
  return &instance;
}

Cgdi::Cgdi()
{}

Cgdi::~Cgdi()
{}

void Cgdi::BlackPen(){cocos2d::ccDrawColor4B(colors[black][0], colors[black][1], colors[black][2], colors[black][3]);}
void Cgdi::WhitePen(){cocos2d::ccDrawColor4B(colors[white][0], colors[white][1], colors[white][2], colors[white][3]);}
void Cgdi::RedPen()  {cocos2d::ccDrawColor4B(colors[red][0], colors[red][1], colors[red][2], colors[red][3]);}
void Cgdi::GreenPen(){cocos2d::ccDrawColor4B(colors[green][0], colors[green][1], colors[green][2], colors[green][3]);}
void Cgdi::BluePen() {cocos2d::ccDrawColor4B(colors[blue][0], colors[blue][1], colors[blue][2], colors[blue][3]);}
void Cgdi::GreyPen() {cocos2d::ccDrawColor4B(colors[grey][0], colors[grey][1], colors[grey][2], colors[grey][3]);}
void Cgdi::PinkPen() {cocos2d::ccDrawColor4B(colors[pink][0], colors[pink][1], colors[pink][2], colors[pink][3]);}
void Cgdi::YellowPen() {cocos2d::ccDrawColor4B(colors[yellow][0], colors[yellow][1], colors[yellow][2], colors[yellow][3]);}
void Cgdi::OrangePen() {cocos2d::ccDrawColor4B(colors[orange][0], colors[orange][1], colors[orange][2], colors[orange][3]);}
void Cgdi::PurplePen() {cocos2d::ccDrawColor4B(colors[purple][0], colors[purple][1], colors[purple][2], colors[purple][3]);}
void Cgdi::BrownPen() {cocos2d::ccDrawColor4B(colors[brown][0], colors[brown][1], colors[brown][2], colors[brown][3]);}

void Cgdi::DarkGreenPen() {cocos2d::ccDrawColor4B(colors[dark_green][0], colors[dark_green][1], colors[dark_green][2], colors[dark_green][3]);}
void Cgdi::LightBluePen() {cocos2d::ccDrawColor4B(colors[light_blue][0], colors[light_blue][1], colors[light_blue][2], colors[light_blue][3]);}
void Cgdi::LightGreyPen() {cocos2d::ccDrawColor4B(colors[light_grey][0], colors[light_grey][1], colors[light_grey][2], colors[light_grey][3]);}
void Cgdi::LightPinkPen() {cocos2d::ccDrawColor4B(colors[light_pink][0], colors[light_pink][1], colors[light_pink][2], colors[light_pink][3]);}

void Cgdi::ThickBlackPen(){cocos2d::ccDrawColor4B(colors[black][0], colors[black][1], colors[black][2], colors[black][3]);}
void Cgdi::ThickWhitePen(){cocos2d::ccDrawColor4B(colors[white][0], colors[white][1], colors[white][2], colors[white][3]);}
void Cgdi::ThickRedPen()  {cocos2d::ccDrawColor4B(colors[red][0], colors[red][1], colors[red][2], colors[red][3]);}
void Cgdi::ThickGreenPen(){cocos2d::ccDrawColor4B(colors[green][0], colors[green][1], colors[green][2], colors[green][3]);}
void Cgdi::ThickBluePen() {cocos2d::ccDrawColor4B(colors[blue][0], colors[blue][1], colors[blue][2], colors[blue][3]);}

void Cgdi::BlackBrush(){cocos2d::ccDrawColor4B(colors[black][0], colors[black][1], colors[black][2], colors[black][3]);}
void Cgdi::WhiteBrush(){cocos2d::ccDrawColor4B(colors[white][0], colors[white][1], colors[white][2], colors[white][3]);} 
//void Cgdi::HollowBrush(){cocos2d::ccDrawColor4B(colors[hollow][0], colors[hollow][1], colors[hollow][2], colors[hollow][3]);}
void Cgdi::HollowBrush(){cocos2d::ccDrawColor4B(colors[green][0], colors[green][1], colors[green][2], colors[green][3]);}
void Cgdi::GreenBrush(){cocos2d::ccDrawColor4B(colors[green][0], colors[green][1], colors[green][2], colors[green][3]);}
void Cgdi::RedBrush()  {cocos2d::ccDrawColor4B(colors[red][0], colors[red][1], colors[red][2], colors[red][3]);}
void Cgdi::BlueBrush()  {cocos2d::ccDrawColor4B(colors[blue][0], colors[blue][1], colors[blue][2], colors[blue][3]);}
void Cgdi::GreyBrush()  {cocos2d::ccDrawColor4B(colors[grey][0], colors[grey][1], colors[grey][2], colors[grey][3]);}
void Cgdi::BrownBrush() {cocos2d::ccDrawColor4B(colors[brown][0], colors[brown][1], colors[brown][2], colors[brown][3]);}
void Cgdi::YellowBrush() {cocos2d::ccDrawColor4B(colors[yellow][0], colors[yellow][1], colors[yellow][2], colors[yellow][3]);}
void Cgdi::LightBlueBrush() {cocos2d::ccDrawColor4B(colors[light_blue][0], colors[light_blue][1], colors[light_blue][2], colors[light_blue][3]);}
void Cgdi::DarkGreenBrush() {cocos2d::ccDrawColor4B(colors[dark_green][0], colors[dark_green][1], colors[dark_green][2], colors[dark_green][3]);}
void Cgdi::OrangeBrush() {cocos2d::ccDrawColor4B(colors[orange][0], colors[orange][1], colors[orange][2], colors[orange][3]);}
