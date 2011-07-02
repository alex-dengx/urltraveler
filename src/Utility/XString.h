#ifndef __OPENUI_STRING_H_
#define __OPENUI_STRING_H_

#pragma once
#include "stdafx.h"
#include "SndaBase.h"
#include <string>
#include "SndaBase.h"

using namespace std;

class UTILITY_API String
{
public:
	enum
	{
		NPOS	=	0xffffffff,	
	};
	//----------------------------------------------------------------------------------------
	//描述: 生成空字符串对象
	//----------------------------------------------------------------------------------------
	String();

	//----------------------------------------------------------------------------------------
	//描述: 根据一个字符生成字符串对象
	//----------------------------------------------------------------------------------------
	String(TCHAR ch);

	//----------------------------------------------------------------------------------------
	//描述: 生成的默认的颜色值为黑色
	//----------------------------------------------------------------------------------------
	String(String& src );

	//----------------------------------------------------------------------------------------
	//描述: 根据指定的字符串，生成对象
	//参数: 
	//	@param	lpszSrc	源字符串
	//	@param	nLen		原字符串中使用到的长度，默认为-1，表示全部被是用来进行构造
	//----------------------------------------------------------------------------------------
	String(LPCTSTR lpszSrc, int nLen = -1);

	virtual ~String();

	//----------------------------------------------------------------------------------------
	//名称: 运算符重载接口
	//----------------------------------------------------------------------------------------
	operator LPCTSTR() const;
	TCHAR operator[] (int nIndex) const;

	const String& operator=(const String& src);
	const String& operator=(String& src);
	const String& operator=(LPCTSTR lpszStr);
	const String& operator=(LPTSTR lpszStr);
	const String& operator=(const TCHAR ch);

	const String& operator+(const String& src);
	const String& operator+(String& src);
	const String& operator+(LPCTSTR lpszStr);
	const String& operator+(LPTSTR lpszStr);
	const String& operator+(const TCHAR ch);

	const String& operator+=(const String& src);
	const String& operator+=(String& src);
	const String& operator+=(LPCTSTR pstr);
	const String& operator+=(LPTSTR pstr);
	const String& operator+=(const TCHAR ch);

	bool operator == (LPCTSTR str) const;
	bool operator != (LPCTSTR str) const;
	bool operator <= (LPCTSTR str) const;
	bool operator <  (LPCTSTR str) const;
	bool operator >= (LPCTSTR str) const;
	bool operator >  (LPCTSTR str) const;

	//----------------------------------------------------------------------------------------
	//名称: 属性接口
	//----------------------------------------------------------------------------------------

	//----------------------------------------------------------------------------------------
	//名称: Compare
	//描述: 当前字符与lpszString进行比较。比较区分大小写
	//返回: 如果相等，返回0，如果当前字符串小于lpszString，则返回-1，否则返回1
	//----------------------------------------------------------------------------------------
	int	Compare(LPCTSTR lpszString);

	//----------------------------------------------------------------------------------------
	//名称: Compare
	//描述: 当前字符与lpszString进行比较。比较不区分大小写
	//返回: 如果相等，返回0，如果当前字符串小于lpszString，则返回-1，否则返回1
	//----------------------------------------------------------------------------------------
	int	CompareNoCase(LPCTSTR lpszString);

	//----------------------------------------------------------------------------------------
	//名称: IsEmpty
	//描述: 判断是否是空字符串。如果字符串为""，则为空字符串，返回true，否则返回false
	//----------------------------------------------------------------------------------------
	bool	IsEmpty() const;

	//----------------------------------------------------------------------------------------
	//名称: Clear
	//描述: 将字符串清空
	//----------------------------------------------------------------------------------------
	void	Clear();

	//----------------------------------------------------------------------------------------
	//名称: GetLength
	//描述: 返回字符串的长度
	//----------------------------------------------------------------------------------------
	int		GetLength() const;

	//----------------------------------------------------------------------------------------
	//名称: GetAt
	//描述: 返回指定位置的字符
	//----------------------------------------------------------------------------------------
	TCHAR	GetAt(int nIndex) const;

	//----------------------------------------------------------------------------------------
	//名称: Append
	//描述: 在当前字符串的尾部添加一个字符
	//参数: 
	//	@param	ch		需要在尾部添加的字符
	//	@param	nCount	字符添加重复的次数
	//返回: 添加之后的字符串
	//----------------------------------------------------------------------------------------	
	String	Append(TCHAR ch, uint16 nCount = 1);

	//----------------------------------------------------------------------------------------
	//名称: Append
	//描述: 在当前字符串的尾部添加一个字符串
	//参数: 
	//	@param	pszAppended		需要在尾部添加的字符串
	//返回: 添加之后的字符串
	//----------------------------------------------------------------------------------------	
	String	Append(const TCHAR* pszAppended);

	//----------------------------------------------------------------------------------------
	//名称: Insert
	//描述: 在当前字符串的给定索引位置插入一个字符
	//参数: 
	//	@param	ch		需要在尾部添加的字符
	//	@param	nIndex	插入字符所在的索引
	//	@param	nCount	插入字符ch的个数，默认为1
	//返回: 插入之后的字符串
	//----------------------------------------------------------------------------------------	
	String	Insert(TCHAR ch, size_t nIndex, size_t nCount = 1);

	//----------------------------------------------------------------------------------------
	//名称: Insert
	//描述: 在当前字符串的给定索引位置插入一个字符串
	//参数: 
	//	@param	pszInserted		需要在尾部添加的字符
	//	@param	nIndex	插入字符所在的索引
	//返回: 插入之后的字符串
	//----------------------------------------------------------------------------------------	
	String	Insert(const TCHAR* pszInserted, size_t nIndex);

	//----------------------------------------------------------------------------------------
	//名称: Assign
	//描述: 将给定字符串赋值给当前字符串
	//参数: 
	//	@param	lpszSrc	源字符串
	//	@param	nLen		原字符串中使用到的长度，默认为-1，表示全部被是用来进行构造
	//----------------------------------------------------------------------------------------
	void		Assign(LPCTSTR lpszSrc, int nLength = -1);

	//----------------------------------------------------------------------------------------
	//名称: GetData
	//描述: 返回字符串的原生数据指针
	//----------------------------------------------------------------------------------------
	LPCTSTR GetData();

	//----------------------------------------------------------------------------------------
	//名称: ValueOf
	//描述: 将给定的整数转换成字符串对象
	//参数: 
	//	@param	nValue	需要转换的整数
	//----------------------------------------------------------------------------------------
	static String ValueOf(int nValue);

	//----------------------------------------------------------------------------------------
	//名称: ValueOf
	//描述: 将给定的整数转换成字符串对象
	//参数: 
	//	@param	lValue	需要转换的整数
	//----------------------------------------------------------------------------------------
	static String ValueOf(long lValue);

	//----------------------------------------------------------------------------------------
	//名称: ValueOf
	//描述: 将给定的整数转换成字符串对象
	//参数: 
	//	@param	dwValue	需要转换的整数
	//----------------------------------------------------------------------------------------
	static String ValueOf(double dwValue);

	//----------------------------------------------------------------------------------------
	//名称: ValueOf
	//描述: 将给定的浮点数转换为字符串对象
	//参数: 
	//	@param	flValue	需要转换的整数
	//----------------------------------------------------------------------------------------
	static String ValueOf(float flValue);

	//----------------------------------------------------------------------------------------
	//名称: ValueOf
	//描述: 将给定的字符转换成字符串对象
	//参数: 
	//	@param	nValue	需要转换的字符串整数
	//----------------------------------------------------------------------------------------
	static String ValueOf(char ch);

	//----------------------------------------------------------------------------------------
	//名称: ValueOf
	//描述: 将给定的布尔变量转换成字符串对象
	//参数: 
	//	@param	bValue	需要转换的布尔值
	//----------------------------------------------------------------------------------------
	static String ValueOf(bool bValue);

	//----------------------------------------------------------------------------------------
	//名称: 操作接口
	//----------------------------------------------------------------------------------------

	//----------------------------------------------------------------------------------------
	//名称: TrimLeft
	//描述: 剔除最左侧的空格、 Tab等内容
	//返回: 函数返回剔除之后的字符串，同时当前字符串的值也会被更改
	//----------------------------------------------------------------------------------------
	String TrimLeft(TCHAR ch=_T(' '));

	//----------------------------------------------------------------------------------------
	//名称: TrimRight
	//描述: 剔除最的空右侧格、 Tab等内容
	//返回: 函数返回剔除之后的字符串，同时当前字符串的值也会被更改
	//----------------------------------------------------------------------------------------
	String TrimRight(TCHAR ch=_T(' '));

	//----------------------------------------------------------------------------------------
	//名称: Trim
	//描述: 剔除左右两边的空格
	//返回: 函数返回剔除之后的字符串，同时当前字符串的值也会被更改
	//----------------------------------------------------------------------------------------
	String Trim(TCHAR ch=_T(' '));

	//----------------------------------------------------------------------------------------
	//名称: Find
	//描述: 从当前的字符串的给定偏移nOffset开始 查找子串pszToFind第一次出现的位置。
	//参数: 
	//	@param	pszToFind	需要查找的子字符串
	//	@param	nOffset	查找的起始偏移，默认是0，即从头开始查找
	//返回: 目标字符的索引，如果没有找到，则返回-1；
	//----------------------------------------------------------------------------------------
	int	Find(const TCHAR* pszToFind,  uint16 nOffset = 0);

	//----------------------------------------------------------------------------------------
	//名称: ReverseFind
	//描述: 从当前的字符串尾部的给定偏移nOffset开始反向查找子串pszToFind第一次出现的位置。
	//参数: 
	//	@param	pszToFind	需要查找的子字符串
	//	@param	nOffset	查找的起始偏移，默认是-1，即从尾部开始查找
	//返回: 目标字符的索引，如果没有找到，则返回-1；
	//----------------------------------------------------------------------------------------
	int	ReverseFind(const TCHAR* pszToFind,  int16 nOffset = NPOS);

	//----------------------------------------------------------------------------------------
	//名称: FindFirstCharOf
	//描述: 从当前的字符串的给定偏移nOffset开始找到第一个出现的chToFind字符
	//参数: 
	//	@param	chToFind	需要查找的字符
	//	@param	nOffset	查找的起始偏移，默认是0，即从头开始查找
	//返回: 目标字符的索引，如果没有找到，则返回-1；
	//----------------------------------------------------------------------------------------
	int	FindFirstCharOf(TCHAR chToFind,  uint16 nOffset = 0);

	//----------------------------------------------------------------------------------------
	//名称: FindFirstCharOf
	//描述: 从当前的字符串的给定偏移nOffset开始查找第一个出现的子串pszToFind中的字符的索引
	//参数: 
	//	@param	pszToFind	需要查找的子字符串
	//	@param	nOffset	查找的起始偏移，默认是0，即从头开始查找
	//返回: 目标字符的索引，如果没有找到，则返回-1；
	//----------------------------------------------------------------------------------------
	int	FindFirstCharOf(const TCHAR* pszToFind, uint16 nOffset = 0);

	//----------------------------------------------------------------------------------------
	//名称: FindFirstCharNotOf
	//描述: 从当前的字符串的给定偏移nOffset开始查找第一个不是szToFind的字符的开始索引
	//参数: 
	//	@param	pszToFind指定的字符
	//	@param	nOffset	查找的起始偏移，默认是0，即从头开始查找
	//返回: 目标字符的索引，如果没有找到，则返回-1；
	//----------------------------------------------------------------------------------------
	int	FindFirstCharNotOf(TCHAR szToFind, uint16 nOffset = 0);

	//----------------------------------------------------------------------------------------
	//名称: FindFirstCharNotOf
	//描述: 从当前的字符串的给定偏移nOffset开始查找第一个不是pszToFind中字符的开始索引，比如
	//	  FindFirstCharNotOf("abcd")，则是查找当前字符串中的第一个不是a，不是b，不是c也不是d
	//	  的字符的开始索引
	//参数: 
	//	@param	pszToFind指定的字符
	//	@param	nOffset	查找的起始偏移，默认是0，即从头开始查找
	//返回: 目标字符的索引，如果没有找到，则返回-1；
	//----------------------------------------------------------------------------------------
	int	FindFirstCharNotOf(const TCHAR* pszToFind, uint16 nOffset = 0 );

	//----------------------------------------------------------------------------------------
	//名称: FindLastCharOf
	//描述: 从当前的字符串尾部的给定偏移nOffset开始反向查找第一个出现的chToFind字符
	//参数: 
	//	@param	chToFind	需要查找的字符
	//	@param	nOffset	查找的起始偏移，默认是NPOS，即从尾部开始查找
	//返回: 目标字符的索引，如果没有找到，则返回-1；
	//----------------------------------------------------------------------------------------
	int	FindLastCharOf(TCHAR chToFind,  uint16 nOffset = NPOS);

	//----------------------------------------------------------------------------------------
	//名称: FindLastCharOf
	//描述: 从当前的字符串尾部的给定偏移nOffset开始反向查找第一个出现在子串pszToFind中的字符
	//	  的索引
	//参数: 
	//	@param	pszToFind	需要查找的子字符串
	//	@param	nOffset	查找的起始偏移，默认是NPOS，即从尾部开始查找
	//返回: 目标字符的索引，如果没有找到，则返回-1；
	//----------------------------------------------------------------------------------------
	int	FindLastCharOf(const TCHAR* pszToFind, uint16 nOffset = NPOS);

	//----------------------------------------------------------------------------------------
	//名称: FindLastCharNotOf
	//描述: 从当前的字符串的尾部偏移nOffset位置反向查找第一个不是szToFind的字符的开始索引
	//参数: 
	//	@param	pszToFind指定的字符
	//	@param	nOffset	查找的起始偏移，默认是NPOS，即从尾部开始查找
	//返回: 目标字符的索引，如果没有找到，则返回-1；
	//----------------------------------------------------------------------------------------
	int	FindLastCharNotOf(TCHAR szToFind, uint16 nOffset = NPOS);

	//----------------------------------------------------------------------------------------
	//名称: FindLastCharNotOf
	//描述: 从当前的字符串尾部偏移为nOffset位置开始查找第一个不是pszToFind中字符的开始索引，比如
	//	  FindLastCharNotOf("abcd")，则是查找当前字符串的尾部开始的第一个不是a，
	//	 不是b，不是c也不是d 的字符的开始索引
	//参数: 
	//	@param	pszToFind指定的字符
	//	@param	nOffset	查找的起始偏移，默认是NPOS，即从尾部开始查找
	//返回: 目标字符的索引，如果没有找到，则返回-1；
	//----------------------------------------------------------------------------------------
	int	FindLastCharNotOf(const TCHAR* pszToFind, uint16 nOffset = NPOS );

	//----------------------------------------------------------------------------------------
	//名称: SubStr
	//描述: 获取当前字符串给定范围内的子字符串
	//参数: 
	//	@param	nBegin	起始偏移
	//	@param	nNumber		子字符串的数目
	//返回: 当前字符串中从nBegin开始的最多nNumber个字符
	//----------------------------------------------------------------------------------------
	String	SubStr(uint16 nBegin, uint16 nNumber) const;

	//----------------------------------------------------------------------------------------
	//名称: Left
	//返回: 获取当前字符串最左边的nLength个字符
	//----------------------------------------------------------------------------------------
	String	Left(uint16 nLength) const;

	//----------------------------------------------------------------------------------------
	//名称: Mid
	//返回: 获取当前字符串从指定位置iPos开始的nLength个字符。如果nLength为-1，则默认为到
	//	  字符串结尾
	//----------------------------------------------------------------------------------------
	String	Mid(uint16 iPos, int nLength = -1) const;

	//----------------------------------------------------------------------------------------
	//名称: Right
	//返回: 获取当前字符串从右边开始的nLength个字符。
	//----------------------------------------------------------------------------------------
	String	Right(uint16 nLength) const;

	//----------------------------------------------------------------------------------------
	//名称: BeginWith
	//返回: 检测当前字符串是否以特定的字符串开始。
	//----------------------------------------------------------------------------------------
	BOOL	BeginWith(String	strBegin) const;

	//----------------------------------------------------------------------------------------
	//名称: EndWith
	//返回: 检测当前字符串是否以特定的字符串为结尾。
	//----------------------------------------------------------------------------------------
	BOOL	EndWith(String	strEnd) const;

	//----------------------------------------------------------------------------------------
	//名称: ToUpper和ToLower
	//描述: 将当前字符串中的字符全部转换为大写或者小写
	//返回: 转换之后的字符串
	//----------------------------------------------------------------------------------------
	String	ToUpper();
	String	ToLower();

	//----------------------------------------------------------------------------------------
	//名称: Reverse
	//描述: 将当前字符串变成反向
	//返回: 反向转换之后的字符串
	//----------------------------------------------------------------------------------------
	String	Reverse();

	//----------------------------------------------------------------------------------------
	//名称: Replace
	//描述: 将当前字符串中给定索引nBegin开始的nNumber个字符替换为pszReplacing
	//参数: 
	//	@param	nBegin	起始偏移
	//	@param	nNumber		子字符串的数目
	//	@param	pszReplacing	替换后的字符串
	//返回: 当前字符串中从nBegin开始的最多nNumber个字符
	//----------------------------------------------------------------------------------------	
	String	Replace( int nBegin, int nNumber, const TCHAR* pszAfterReplcing);

	//----------------------------------------------------------------------------------------
	//名称: Replace
	//描述: 将当前字符串中的所有的字符串pszBefore替换为pszAfter
	//参数: 
	//	@param	pszBefore		替换前的字符串
	//	@param	pszAfter		替换后的字符串
	//返回: 替换后的字符串，当前的字符串内容也会被更改
	//----------------------------------------------------------------------------------------	
	String	Replace( const TCHAR* pszBefore, const TCHAR* pszAfter);

	//----------------------------------------------------------------------------------------
	//名称: Format
	//描述: 格式化生成当前字符串，能够支持的目标字符串长度为1024。
	//参数: 
	//	@param	pstrFormat		格式化字符串
	//返回: 替换后的字符串，当前的字符串内容也会被更改
	//----------------------------------------------------------------------------------------	
	int __cdecl Format(LPCTSTR pstrFormat, ...);

	//----------------------------------------------------------------------------------------
	//名称: Format
	//描述: 格式化生成当前字符串，它能够支持的目标字符串长度为64。
	//参数: 
	//	@param	pstrFormat		格式化字符串
	//返回: 替换后的字符串，当前的字符串内容也会被更改
	//----------------------------------------------------------------------------------------	
	int __cdecl SmallFormat(LPCTSTR pstrFormat, ...);

	//----------------------------------------------------------------------------------------
	//名称: IsNumeric
	//描述: 当前字符串是否全部是数字
	//返回: 如果全部是数字，则返回true，否则返回false
	//----------------------------------------------------------------------------------------	
	bool	IsNumeric();

	//----------------------------------------------------------------------------------------
	//名称: Split
	//描述: 对当前的字符串按照给定的字符进行分割
	//参数: 
	//	@param	chSplit		分割的符号，如果要按照 | 进行分割，则chSplit为 |
	//	@param	nNum		分割后的字符串的数目
	//返回: 替换后的字符串，当前的字符串内容也会被更改
	//返回: 返回分割后的字符串数组指针
	//----------------------------------------------------------------------------------------	
	void Split(TCHAR chSplit, String* pString, uint16& nNum);

private:

#ifndef _UNICODE
	std::string	m_strString;
#else
	std::wstring m_strString;
#endif
};


#endif