#pragma once

// DataCenter的对外的头文件信息

#include "SndaBase.h"
#include "UrlTravelerHeader.h"
#include <vector>

using namespace std;


namespace datacenter
{
	// DataCenter对外公开的事件
	enum E_DataCenterEventValue
	{
		EVENT_VALUE_DATACENTER_OPEN = EVENT_VALUE_DATACENTER_BEGIN,		//打开主界面
		EVENT_VALUE_DATACENTER_FAVORITE_ICON_ARRIVE,						//收藏夹图标已经就绪
		EVENT_VALUE_DATACENTER_DELETE_FAVORITE,		//删除某个收藏的URL
		EVENT_VALUE_DATACENTER_DELETE_FAVORITE_FOLD,	//删除某个收藏夹的所有数据, param0为需要删除的收藏夹id
		EVENT_VALUE_DATACENTER_TREELIST_SELECT,		//	在树中某个结点被删除后，需要将焦点移动到上一个结点或者父结点中

		EVENT_VALUE_DATACENTER_END = EVENT_VALUE_DATACENTER_END ,		//所有的事件结束
	};

	// DataCenter能够可能对外发送的广播消息
	enum E_DataCenterMessageValue
	{
	};

	// DataCenter能够处理的直接调用
	enum E_DataCenterServiceValue
	{
		SERVICE_VALUE_DATACENTER_GET_FAVORITE_VECTOR	=	SERVICE_VALUE_DATACENTER_BEGIN,
		SERVICE_VALUE_DATACENTER_GET_FAVORITE_DATA,
		SERVICE_VALUE_DATACENTER_GET_FAVORITE_ICON,		//	获取给定Domain对应的URL
		SERVICE_VALUE_DATACENTER_CHECK_EXIST_SUBFOLD,		//	检查给定文件夹下是否存在子文件夹
	};

	//===========================================//
	//                   DataCenter中所使用到的数据结构			              //
	//===========================================//
	// 定义收藏夹数据结构

#define MAX_URL_LEN	1024

	// 收藏夹中每一个收藏记录的数据
	typedef struct FavoriteLineData
	{
		int32       nId;                //  ID
		wchar_t	    szTitle[MAX_PATH];	//	描述文本，或者为分类名称，或者为URL的title
		int32		nCatId;				//  分类ID
		int32		nPid;		        //	父类的ID
		bool        bFolder;            //  是否是目录结点。如果是true，表示是目录结点，否则是子结点
		wchar_t	    szUrl[MAX_URL_LEN];		//	收藏的URL
		time_t		nAddTimes;		    //	增加的时间
		time_t		nLastModifyTime;	//	最近的更改时间
		int32		nClickTimes;		//	点击次数
		uint32		nHashId;			//  Hash
		int32		nOrder;				//	当前结点在当前层次中的顺序
		bool        bDelete;

		FavoriteLineData()
		{
			nId	=	0;
			nCatId	=	0;
			nPid	=	0;
			bFolder	=	false;
			nAddTimes	=	0;
			nLastModifyTime	=	0;
			nClickTimes	=	0;
			nHashId	=	0;
			nOrder	=	0;
			bDelete =   false;

			ZEROMEM(szTitle);
			ZEROMEM(szUrl);
		}

		bool operator < (const FavoriteLineData& x)const
		{
			if (nPid < x.nPid)
			{
				return true;
			}

			return false;
		}

	} FAVORITELINEDATA, *PFAVORITELINEDATA; 

	// 历史记录中每一个历史记录的数据
	typedef struct HistoryLineData
	{
		wchar_t	    szTitle;			//	描述文本，或者为分类名称，或者为URL的title
		int32		nCatId;				//	分类ID
		int32		nParentCatId;		//	父类的ID，如果nParentCatId=0表示当前ID是目录结点
		wchar_t	    szUrl[MAX_URL_LEN];				//	收藏的URL
		int32		nAddTimes;			//	增加的时间
		int32		nLastModifyTime;	//	最近的更改时间
		int32		nClickTimes;		//	点击次数
		int32		nOrder;				//	当前结点在当前层次中的顺序

	} HISTORYLINEDATA, *PHISTORYLINEDATA;

#define MAX_COOKIE_NAME_LEN	128
#define MAX_COOKIE_VALUE_LEN	128
#define MAX_COOKIE_HOST_LEN	128

	// 每一个Cookie记录
	typedef struct CookieLineData
	{
		int nId;			
		wchar_t	szName[MAX_COOKIE_NAME_LEN];
		wchar_t	szValue[MAX_COOKIE_VALUE_LEN];
		wchar_t	szHost[MAX_COOKIE_HOST_LEN];
		wchar_t	szPath[MAX_PATH];
		int	nExpiry;
		int	nLastAccessed;
		bool	bIsSecure;
		bool	bIsHttpOnly;

	}COOKIELINEDATA, *PCOOKIELINEDATA;


	//===========================================//
	//                   DataCenter中所使用到的event结构			              //
	//===========================================//
	struct DataCenterEvent	:	public ExtraInfo
	{
	public:
		DataCenterEvent()
		{
			srcMId	=	MODULE_ID_DATACENTER;
			desMId	=	MODULE_ID_INVALID;
		}
	};

	struct DataCenter_FavoriteIconArriveEvent	: DataCenterEvent 
	{
		DataCenter_FavoriteIconArriveEvent()
		{
			eventValue	=	EVENT_VALUE_DATACENTER_FAVORITE_ICON_ARRIVE;
		}

		wchar_t	szDomain[MAX_PATH];
		HICON	hIcon;
	};

	struct DataCenter_DeleteFavoriteEvent	: DataCenterEvent 
	{
		DataCenter_DeleteFavoriteEvent()
		{
			eventValue	=	EVENT_VALUE_DATACENTER_DELETE_FAVORITE;
			nFavoriteId = 0;
			ZEROMEM(szUrl);
		}

		int nFavoriteId;
		wchar_t	szUrl[MAX_PATH];
	};

	//===========================================//
	//                   DataCenter中所使用到的Service结构			              //
	//===========================================//
	struct DataCenter_GetFavoriteVectorService : public Service
	{
		DataCenter_GetFavoriteVectorService()
		{
			serviceId	=	SERVICE_VALUE_DATACENTER_GET_FAVORITE_VECTOR;
			pvFavoriteData = NULL;
		}

		std::vector<FAVORITELINEDATA>*	pvFavoriteData;
	};

	struct DataCenter_GetFavoriteService : public Service
	{
		DataCenter_GetFavoriteService()
		{
			serviceId = SERVICE_VALUE_DATACENTER_GET_FAVORITE_DATA;
			nNum = 0;
			pFavoriteData	=	NULL;
		}

		int nNum;										//	
		FAVORITELINEDATA*		pFavoriteData;			//	收藏夹的数据	
	};

	// 获取给定的URL 域对应的ICON
	struct DataCenter_GetFavoriteIconService : public Service
	{
		DataCenter_GetFavoriteIconService()
		{
			serviceId = SERVICE_VALUE_DATACENTER_GET_FAVORITE_ICON;

			ZEROMEM(szDomain);
			hIcon = NULL;
		}

		wchar_t	szDomain[MAX_PATH];
		HICON	hIcon;
	};


	// 检查给定的收藏夹下是否存在子文件夹
	struct DataCenter_CheckExistSubFoldService : public Service
	{
		DataCenter_CheckExistSubFoldService()
		{
			serviceId = SERVICE_VALUE_DATACENTER_CHECK_EXIST_SUBFOLD;
			nFoldId	=	0;
			bExistSubFolder	=	FALSE;
			bExistFavorite	=	FALSE;
		}

		int nFoldId;					//	收藏夹的ID
		BOOL	bExistSubFolder;		//	是否存在子文件夹
		BOOL	bExistFavorite;			//	该文件夹下是否存在收藏记录
	};
};