#ifndef SCRIPTOR_H
#define SCRIPTOR_H
//-----------------------------------------------------------------------------
//
//  Name:   Scriptor.h
//
//  Author: Mat Buckland (www.ai-junkie.com)
//
//  Desc:   class encapsulating the basic functionality necessary to read a
//          Lua config file
//-----------------------------------------------------------------------------
//extern "C"
//{
//  #include <lua.h>
//  #include <lualib.h>
//  #include <lauxlib.h>
//}
//
//#pragma comment(lib, "lua5.1.lib")
////#pragma comment(lib, "lualib.lib")
//
#include "LuaHelperFunctions.h"

#include <string>

class Scriptor
{
private:

  lua_State* m_pLuaState;

public:

  Scriptor():m_pLuaState(0)
  {
    //open the libraries
    //luaL_openlibs(m_pLuaState);
  }

  ~Scriptor(){/*lua_close(m_pLuaState);*/}

  //void RunScriptFile(char* ScriptName)
  void RunScriptFile(char* ScriptName, lua_State* pState)
  {
	  //RunLuaScript(m_pLuaState, ScriptName);
	  if(0 == m_pLuaState)
		  m_pLuaState = pState;
  }

  lua_State* GetState(){return m_pLuaState;}


  int GetInt(char* VariableName)
  {
    return PopLuaNumber<int>(m_pLuaState, VariableName);
  }
    
  double GetFloat(char* VariableName)
  {
    return PopLuaNumber<float>(m_pLuaState, VariableName);
  }

  double GetDouble(char* VariableName)
  {
    return PopLuaNumber<double>(m_pLuaState, VariableName);
  }

  std::string GetString(char* VariableName)
  {
    return PopLuaString(m_pLuaState, VariableName);
  }

  bool GetBool(char* VariableName)
  {
    return PopLuaBool(m_pLuaState, VariableName);
  }
};

#endif

 
  

