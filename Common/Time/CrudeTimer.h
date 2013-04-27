#ifndef CRUDETIMER_H
#define CRUDETIMER_H
//------------------------------------------------------------------------
//
//  Name:   CrudeTimer.h
//
//  Desc:   timer to measure time in seconds
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------

//this library must be included
//#pragma comment(lib, "winmm.lib")

//#include <windows.h>

#include "platform/platform.h"
#include "CCStdC.h"

#define Clock CrudeTimer::Instance()

class CrudeTimer
{
private:
  

  //set to the time (in seconds) when class is instantiated
  //double m_dStartTime;
  struct cocos2d::cc_timeval m_dStartTime;

  //set the start time
  CrudeTimer(){
	  if (cocos2d::CCTime::gettimeofdayCocos2d(&m_dStartTime, NULL) != 0)
		  CCLOG("error in gettimeofday");
		  //m_dStartTime = timeGetTime() * 0.001;
  }

  //copy ctor and assignment should be private
  CrudeTimer(const CrudeTimer&);
  CrudeTimer& operator=(const CrudeTimer&);
  
public:

  static CrudeTimer* Instance();

  //returns how much time has elapsed since the timer was started
  double GetCurrentTime()
  {
	  double deltaTime = 0;

	  struct cocos2d::cc_timeval now;

	  if (cocos2d::CCTime::gettimeofdayCocos2d(&now, NULL) != 0)
	  {
		  CCLOG("error in gettimeofday");
	  }else
	  {
		  deltaTime = (now.tv_sec - m_dStartTime.tv_sec) + (now.tv_usec - m_dStartTime.tv_usec) / 1000000.0f;
		  deltaTime = MAX(0, deltaTime);
	  }

	  return deltaTime;
	  //return timeGetTime() * 0.001 - m_dStartTime;
  }

};







#endif