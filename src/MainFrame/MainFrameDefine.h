#pragma once

// MainFrame的对外的头文件信息

#include "SndaBase.h"

extern "C" 
{
	DLLEXPORT IModuleFactory*	GetModuleFactory();
	DLLEXPORT void	ReleaseModuleFactory( IModuleFactory*);
}

namespace mainframe
{
	// MainFrame对外公开的事件
	enum E_MainFrameEventValue
	{
		EVENT_VALUE_MAINFRAME_OPEN = EVENT_VALUE_MAINFRAME_BEGIN,		//打开主界面
		EVENT_VALUE_MAINFRAME_HIDE,							//	隐藏当前主界面
		EVENT_VALUE_MAINFRAME_CLOSE,						//	关闭当前主界面

		EVENT_VALUE_MAINFRAME_END = EVENT_VALUE_MAINFRAME_END ,			//所有的事件结束
	};

	// MainFrame能够可能对外发送的广播消息
	enum E_MainFrameMessageValue
	{

	};

	// MainFrame能够处理的直接调用
	enum E_MainFrameServiceValue
	{
	};

	//===========================================//
	//                   MainFrame中所使用到的event结构								 	  //
	//===========================================//
	struct MainFrameEvent	:	public ExtraInfo
	{
	public:
		MainFrameEvent()
		{
			srcMId	=	MODULE_ID_INVALID;
			desMId	=	MODULE_ID_MAINFRAME;
		}
	};

	enum	E_MainFrameTab
	{
		TAB_FAVORITE,
		TAB_HISTORY,	
	};

	// 打开主界面需要的对应的Event
	struct MainFrame_OpenEvent	:	public	MainFrameEvent
	{
	public:
		MainFrame_OpenEvent()
		{
			eventValue	=	 EVENT_VALUE_MAINFRAME_OPEN;
		}

		E_MainFrameTab	eTabType;			//	指定打开后显示哪一个Tab页面
	}

	//	隐藏主界面需要的对应的Event
	struct MainFrame_HideEvent	:	public	MainFrameEvent
	{
	public:
		MainFrame_OpenEvent()
		{
			eventValue	=	 EVENT_VALUE_MAINFRAME_HIDE;
		}
	}

};