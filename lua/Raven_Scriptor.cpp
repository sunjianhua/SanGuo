#include "Raven_Scriptor.h"
#include "CCLuaEngine.h"

Raven_Scriptor* Raven_Scriptor::Instance()
{
  static Raven_Scriptor instance;

  return &instance;
}



Raven_Scriptor::Raven_Scriptor():Scriptor()
{
	// û��������жϣ����ܲ���lua��
	cocos2d::CCLuaEngine* pEngine = (cocos2d::CCLuaEngine*)cocos2d::CCScriptEngineManager::sharedManager()->getScriptEngine();
	// û������ָ����
	RunScriptFile("Params.lua", pEngine->getLuaStack()->getLuaState());
}