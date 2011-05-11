#pragma once

#include "SndaBase.h"
#include "PlugIn.h"

extern "C" 
{
	DLLEXPORT IPlugIn*	GetPlugIn();
	DLLEXPORT void	ReleasePlugIn( IPlugIn*);
}

class IEPlugIn : public IPlugInImp
{
public:
	IEPlugIn(void);
	~IEPlugIn(void);

	//----------------------------------------------------------------------------------------
	//名称: IsWorked
	//描述: 检查该插件是否能够正常工作。如果没有安装该PlugIn对应的浏览器，则该插件不需要
	//	处理，只需要返回FALSE即可。否则它将会被调用。
	//返回: 插件的版本号，通常为一整数。
	//----------------------------------------------------------------------------------------
	virtual BOOL IsWorked(wchar_t *pszBrowserVersion, int32 &nLen) ;

	//----------------------------------------------------------------------------------------
	//名称: GetPluginVersion
	//描述: 获取当前插件的版本号
	//返回: 插件的版本号，通常为一整数。
	//----------------------------------------------------------------------------------------
	virtual int32 GetPluginVersion() ;

	//----------------------------------------------------------------------------------------
	//名称: GetBrowserName
	//描述: 获取该插件对应的浏览器的名称和版本
	//----------------------------------------------------------------------------------------
	virtual const wchar_t* GetBrowserName() ;

	//----------------------------------------------------------------------------------------
	//名称: GetBrowserIcon
	//描述: 获取该插件对应的浏览器的图标
	//----------------------------------------------------------------------------------------
	virtual HICON GetBrowserIcon() ;

	//----------------------------------------------------------------------------------------
	//名称: GetInstallPath
	//描述: 获取插件对应的浏览器的安装目录
	//----------------------------------------------------------------------------------------
	virtual wchar_t* GetInstallPath() ;

	//----------------------------------------------------------------------------------------
	//名称: GetFavoriteDataPath
	//描述: 获取浏览器收藏夹对应的文件或者文件夹的路径
	//----------------------------------------------------------------------------------------
	virtual wchar_t* GetFavoriteDataPath() ;

	//----------------------------------------------------------------------------------------
	//名称: GetHistoryDataPath
	//描述: 获取浏览器收藏夹的历史数据对应的文件或者文件夹
	//----------------------------------------------------------------------------------------
	virtual wchar_t* GetHistoryDataPath() ;

	//----------------------------------------------------------------------------------------
	//名称: ExportFavoriteData
	//描述: 导出当前浏览器的所有的收藏夹数据
	//参数: 
	//		@param	pData			导出的收藏夹数据数组
	//		@param	nDataNum		导出的收藏夹条目的条数
	//----------------------------------------------------------------------------------------
	virtual BOOL ExportFavoriteData(PFAVORITELINEDATA pData, int32& nDataNum);

	//----------------------------------------------------------------------------------------
	//名称: ImportFavoriteData
	//描述: 将当前的记录导入到浏览器中
	//参数: 
	//		@param	pData			需要导入的的收藏夹数据数组
	//		@param	nDataNum		需要导入的收藏夹条目的条数
	//----------------------------------------------------------------------------------------
	virtual BOOL ImportFavoriteData(PFAVORITELINEDATA pData, int32 nDataNum);
};

namespace ieplugin
{
	extern IEPlugIn*	g_IEPlugIn;
}
using namespace ieplugin;