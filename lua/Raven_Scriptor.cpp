#include "Raven_Scriptor.h"
#include "CCLuaEngine.h"

Raven_Scriptor* Raven_Scriptor::Instance()
{
  static Raven_Scriptor instance;

  return &instance;
}



Raven_Scriptor::Raven_Scriptor():Scriptor()
{
	// 没有做类别判断，可能不是lua。
	cocos2d::CCLuaEngine* pEngine = (cocos2d::CCLuaEngine*)cocos2d::CCScriptEngineManager::sharedManager()->getScriptEngine();
	// 没有做空指针检测
	RunScriptFile("Params.lua", pEngine->getLuaStack()->getLuaState());
}