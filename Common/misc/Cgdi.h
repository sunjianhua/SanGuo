#ifndef CGDI_H
#define CGDI_H
//------------------------------------------------------------------------
//
//  Name:   Cgdi.h
//
//  Desc:   A singleton class to help alleviate the tedium of using the
//          GDI. Call each method using the #define for gdi->
//          eg gdi->Line(10, 20, 300, 300)
//          You must always call gdi->StartDrawing() prior to any 
//          rendering, and isComplete any rendering with gdi->StopDrawing()
//
//  Author: Mat Buckland 2001 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
//#include <windows.h>
#include <string>
#include <vector>
//#include <cassert>

#include "2D/Vector2D.h"


//------------------------------- define some colors
const int NumColors = 15;

const unsigned char colors[NumColors][4] =
{
  {255,0,0, 255},
  {0,0,255, 255},
  {0,255,0, 255},
  {0,0,0, 255},
  {255,200,200, 255},
  {200,200,200, 255},
  {255,255,0, 255},
  {255,170,0, 255},
  {255,0,170, 255},
  {133,90,0, 255},
  {255,255,255, 255},  
  {0, 100, 0, 255},        //dark green
  {0, 255, 255, 255},       //light blue
  {200, 200, 200, 255},     //light grey
  {255, 230, 230,255}      //light pink
};


//make life easier on the fingers
#define gdi Cgdi::Instance()

class Cgdi
{
public:
  
  int NumPenColors()const{return NumColors;}

  //enumerate some colors
  enum
  {
    red,
    blue, 
    green,
    black,
    pink,
    grey,
    yellow,
    orange,
    purple,
    brown,   
    white,
    dark_green,
    light_blue,
    light_grey,
    light_pink,
    hollow
  };

  
  
private:

  //constructor is private
  Cgdi();

  //copy ctor and assignment should be private
  Cgdi(const Cgdi&);
  Cgdi& operator=(const Cgdi&);

public:

  ~Cgdi();
  
  static Cgdi* Instance();

  void BlackPen();
  void WhitePen();
  void RedPen();
  void GreenPen();
  void BluePen();
  void GreyPen();
  void PinkPen();
  void YellowPen();
  void OrangePen();
  void PurplePen();
  void BrownPen();
  
  void DarkGreenPen();
  void LightBluePen();
  void LightGreyPen();
  void LightPinkPen();

  void ThickBlackPen();
  void ThickWhitePen();
  void ThickRedPen();
  void ThickGreenPen();
  void ThickBluePen();

  void BlackBrush();
  void WhiteBrush();
  void HollowBrush();
  void GreenBrush();
  void RedBrush();
  void BlueBrush();
  void GreyBrush();
  void BrownBrush();
  void YellowBrush();
  void LightBlueBrush();
  void DarkGreenBrush();
  void OrangeBrush();



  //ALWAYS call this before drawing
  void StartDrawing(HDC hdc)
  {
    //assert(m_hdc == NULL);
    //
    //m_hdc = hdc;

    ////get the current pen
    //m_OldPen = (HPEN)SelectObject(hdc, m_BlackPen);
    ////select it back in
    //SelectObject(hdc, m_OldPen);

    //m_OldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(BLACK_BRUSH));
    //SelectObject(hdc, m_OldBrush);
  }

  
  
  //ALWAYS call this after drawing
  void StopDrawing(HDC hdc)
  {
    //assert(hdc != NULL);
    //
    //SelectObject(hdc, m_OldPen);
    //SelectObject(hdc, m_OldBrush);

    //m_hdc = NULL;
 
  }


  //---------------------------Text

  void TextAtPos(int x, int y, const std::string &s)
  {
    //TextOutA(m_hdc, x, y, s.c_str(), (int)s.size());
	CCLOG("TextAtPos: %s", s.c_str());
  }

  void TextAtPos(double x, double y, const std::string &s)
  {
    //TextOutA(m_hdc, (int)x, (int)y, s.c_str(), (int)s.size());
	CCLOG("TextAtPos: %s", s.c_str());
  }

  void TextAtPos(Vector2D pos, const std::string &s)
  {
    //TextOutA(m_hdc, (int)pos.x, (int)pos.y, s.c_str(), (int)s.size());
	CCLOG("TextAtPos: %s", s.c_str());
  }

  void TransparentText(){CCLOG("TransparentText");/*SetBkMode(m_hdc, TRANSPARENT);*/}

  void OpaqueText(){CCLOG("OpaqueText");/*SetBkMode(m_hdc, OPAQUE);*/}

  void TextColor(int color){CCLOG("TextColor: %i", color);/*assert(color < NumColors); SetTextColor(m_hdc, RGB(colors[color][0],colors[color][1],colors[color][2]));*/}
  void TextColor(int r, int g, int b){CCLOG("TextColor: R:%i, G:%i, B:%i", r, g, b);/*SetTextColor(m_hdc, RGB(r,g,b));*/}


  //----------------------------pixels
  void DrawDot(Vector2D pos, COLORREF color)
  {
	  //SetPixel(m_hdc, (int)pos.x, (int)pos.y, color);
	  cocos2d::ccPointSize(10);
	  //cocos2d::ccDrawColor4B(0,0,255,128);
	  cocos2d::ccDrawPoint( ccp(pos.x, pos.y) );
  }

  void DrawDot(int x, int y, COLORREF color)
  {
    //SetPixel(m_hdc, x, y, color);
	  cocos2d::ccPointSize(10);
	  cocos2d::ccDrawPoint( ccp(x, y) );
  }
  
  //-------------------------Line Drawing

  void Line(Vector2D from, Vector2D to)
  {
    //MoveToEx(m_hdc, (int)from.x, (int)from.y, NULL);
    //LineTo(m_hdc, (int)to.x, (int)to.y);
	cocos2d::ccDrawLine( ccp(from.x, from.y), ccp(to.x, to.y) );
  }

  void Line(int a, int b, int x, int y)
  {
	  //MoveToEx(m_hdc, a, b, NULL);
	  //LineTo(m_hdc, x, y);
	  cocos2d::ccDrawLine( ccp(a, b), ccp(x, y) );
  }

  void Line(double a, double b, double x, double y)
  {
	  //MoveToEx(m_hdc, (int)a, (int)b, NULL);
	  //LineTo(m_hdc, (int)x, (int)y);
	  cocos2d::ccDrawLine( ccp(a, b), ccp(x, y) );
  }

  void PolyLine(const std::vector<Vector2D>& points)
  {
	  //make sure we have at least 2 points
	  if (points.size() < 2) return;

	  //MoveToEx(m_hdc, (int)points[0].x, (int)points[0].y, NULL);

	  //for (unsigned int p=1; p<points.size(); ++p)
	  //{
	  // LineTo(m_hdc, (int)points[p].x, (int)points[p].y);
	  //}
	  cocos2d::CCPoint *pvertices = new cocos2d::CCPoint[points.size()];

	  for (unsigned int p=0; p<points.size(); ++p)
		  pvertices[p] = ccp(points[p].x, points[p].y);
	  cocos2d::ccDrawPoly( pvertices, points.size(), false);

	  delete []pvertices;
  }

 // void LineWithArrow(Vector2D from, Vector2D to, double size)
 // {
 //   Vector2D norm = Vec2DNormalize(to-from);

 //   //calculate where the arrow is attached
 //   Vector2D CrossingPoint = to - (norm * size);
 //   
 //   //calculate the two extra points required to make the arrowhead
 //   Vector2D ArrowPoint1 = CrossingPoint + (norm.Perp() * 0.4f * size); 
 //   Vector2D ArrowPoint2 = CrossingPoint - (norm.Perp() * 0.4f * size); 

 //   //draw the line
 //   //MoveToEx(m_hdc, (int)from.x, (int)from.y, NULL);
 //   //LineTo(m_hdc, (int)CrossingPoint.x, (int)CrossingPoint.y);
	//cocos2d::ccDrawLine( ccp(from.x, from.y), ccp(CrossingPoint.x, CrossingPoint.y) );

 //   //draw the arrowhead (filled with the currently selected brush)
 //   POINT p[3];
 //   
 //   p[0] = VectorToPOINT(ArrowPoint1);
 //   p[1] = VectorToPOINT(ArrowPoint2);
 //   p[2] = VectorToPOINT(to);                  
 //                      
 //   //SetPolyFillMode(m_hdc, WINDING);
 //   //Polygon(m_hdc, p, 3);
	//cocos2d::CCPoint vertices3[] = {ccp(p[0].x, p[0].y), ccp(p[1].x, p[1].y), ccp(p[2].x, p[2].y)};
	//cocos2d::ccDrawPoly( vertices3, 3, true);

 // }

  void Cross(Vector2D pos, int diameter)
  {
    Line((int)pos.x-diameter, (int)pos.y-diameter, (int)pos.x+diameter, (int)pos.y+diameter);
    Line((int)pos.x-diameter,(int)pos.y+diameter, (int)pos.x+diameter, (int)pos.y-diameter);
  }


  //---------------------Geometry drawing methods

  void Rect(int left, int top, int right, int bot)
  {
	  //Rectangle(m_hdc, left, top, right, bot);

	  cocos2d::CCPoint vertices3[] = {ccp(left,bot), ccp(left,top), ccp(right,top), ccp(right,bot)};
	  cocos2d::ccDrawSolidPoly( vertices3, 4, cocos2d::ccc4f(1,1,0,1) );
  }

  void Rect(double left, double top, double right, double bot)
  {
	  //Rectangle(m_hdc, (int)left, (int)top, (int)right, (int)bot);

	  cocos2d::CCPoint vertices3[] = {ccp(left,bot), ccp(left,top), ccp(right,top), ccp(right,bot)};
	  cocos2d::ccDrawSolidPoly( vertices3, 4, cocos2d::ccc4f(1,1,0,1) );
  }



  void ClosedShape(const std::vector<Vector2D> &points)
  {
	  //MoveToEx(m_hdc, (int)points[0].x, (int)points[0].y, NULL);

	  //for (unsigned int p=1; p<points.size(); ++p)
	  //{
		 // LineTo(m_hdc, (int)points[p].x, (int)points[p].y);
	  //}

	  //LineTo(m_hdc, (int)points[0].x, (int)points[0].y);

	  cocos2d::CCPoint *pvertices = new cocos2d::CCPoint[points.size()];

	  for (unsigned int p=0; p<points.size(); ++p)
		  pvertices[p] = ccp(points[p].x, points[p].y);
	  cocos2d::ccDrawPoly( pvertices, points.size(), true);

	  delete []pvertices;
  }


  void Circle(Vector2D pos, double radius)
  {
    //Ellipse(m_hdc,
    //       (int)(pos.x-radius),
    //       (int)(pos.y-radius),
    //       (int)(pos.x+radius+1),
    //       (int)(pos.y+radius+1));

	cocos2d::ccDrawCircle( ccp(pos.x, pos.y), radius, CC_DEGREES_TO_RADIANS(90), 50, true);
  }

  void Circle(double x, double y, double radius)
  {
	  //Ellipse(m_hdc,
	  //       (int)(x-radius),
	  //       (int)(y-radius),
	  //       (int)(x+radius+1),
	  //       (int)(y+radius+1));
	  cocos2d::ccDrawCircle( ccp(x, y), radius, CC_DEGREES_TO_RADIANS(90), 50, true);
  }

  void Circle(int x, int y, double radius)
  {
	  //Ellipse(m_hdc,
	  //       (int)(x-radius),
	  //       (int)(y-radius),
	  //       (int)(x+radius+1),
	  //       (int)(y+radius+1));

	  cocos2d::ccDrawCircle( ccp(x, y), radius, CC_DEGREES_TO_RADIANS(90), 50, true);
  }


  void SetPenColor(int color)
  {
   // assert (color < NumColors);
   // 
   //switch (color)
   //{
   // case black:BlackPen(); return;

   // case white:WhitePen(); return;
   // case red: RedPen(); return;
   // case green: GreenPen(); return;
   // case blue: BluePen(); return;
   // case pink: PinkPen(); return;
   // case grey: GreyPen(); return;
   // case yellow: YellowPen(); return;
   // case orange: OrangePen(); return;
   // case purple: PurplePen(); return;
   // case brown: BrownPen(); return;
   // case light_blue: LightBluePen(); return;
   // case light_grey: LightGreyPen(); return;
   // case light_pink: LightPinkPen(); return;
   // }//end switch
  }
};

#endif