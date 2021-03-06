#include "stdafx.h"
#include "StringHelper.h"
#include <algorithm>
#include <locale.h>
#include "algorithm"
#include <assert.h>
#include "Windows.h"
#include <locale.h>
#include <vector>

using namespace std;

StringHelper::StringHelper(void)
{
}

StringHelper::~StringHelper(void)
{
}

string	StringHelper::MakeLower( string in_str)
{
	string instr = in_str;
	std::transform( instr.begin(), instr.end(), instr.begin(),tolower);

	return instr;
}

string	StringHelper::MakeUpper( string in_str )
{
	string instr = in_str;
	std::transform( instr.begin(), instr.end(), instr.begin(),toupper);

	return instr;
}

std::wstring StringHelper::HexToString(std::string strHex)
{
	BYTE *pbyHex = (BYTE *)strHex.c_str();
	unsigned int nLen = strHex.length();
	wchar_t szTemp[16] = {0};

	std::wstring str;

	while (nLen--)
	{
		_snwprintf_s(szTemp, 16, 2, L"%02x", *pbyHex++);
		str += szTemp;
	}

	return str;
}

std::string StringHelper::StringToHex(std::wstring strString)
{
	std::string strHex;
	int nLen = strString.length();

	if (nLen % 2 != 0)
	{
		return "";
	}

	wchar_t *pbyBuffer = (wchar_t *)strString.c_str();
	BYTE     byValue = 0;

	for (int i = 0; i < nLen - 1; i = i + 2)
	{
		if (pbyBuffer[i] >= 48  && pbyBuffer[i] <= 57)
		{
			byValue = pbyBuffer[i] - '0';
		}
		else if(pbyBuffer[i] >= 65 && pbyBuffer[i] <= 70)
		{
			byValue = pbyBuffer[i] - 55;
		}
		else if(pbyBuffer[i] >= 97 && pbyBuffer[i] <= 102)
		{
			byValue = pbyBuffer[i] - 87;
		}
		else
		{
			return "";
		}

		if (pbyBuffer[i + 1] >= 48  && pbyBuffer[i + 1] <= 57)
		{
			byValue = byValue * 16 + pbyBuffer[i + 1] - '0';
		}
		else if(pbyBuffer[i + 1] >= 65 && pbyBuffer[i + 1] <= 70)
		{
			byValue = byValue * 16 + pbyBuffer[i + 1] - '0' - 7;
		}
		else if(pbyBuffer[i + 1] >= 97 && pbyBuffer[i + 1] <= 102)
		{
			byValue = byValue * 16 + pbyBuffer[i + 1] - 87;
		}
		else
		{
			return "";
		}

		strHex.append(1, (char)byValue);
	}

	return strHex;
}


string	StringHelper::ConvertFromInt( long	in_int)
{
	char instr[256];
	sprintf(instr, "%d", in_int);
	return instr;
}

long	StringHelper::ConvertToInt( string in_str)
{
	return atol( in_str.c_str());
}

string	StringHelper::Reverse(string& src_string)
{
	string inner_src = src_string;
	std::reverse( inner_src.begin(), inner_src.end());

	return inner_src;
}

bool StringHelper::IsNumberic(const string& num) 
{ 
	return num.find_first_not_of("0123456789.") == string::npos;
} 

string StringHelper::TrimAll( string src_str )
{
	if (src_str.empty())
	{
		return src_str;
	}
	src_str.erase(0,src_str.find_first_not_of(" \r\n\t"));
	src_str.erase(src_str.find_last_not_of(" \r\n\t") + 1);
	return src_str;
}

/*
** Convert a UTF-8 string to microsoft unicode (UTF-16?). 
**
** Space to hold the returned string is obtained from malloc.
*/
wstring	StringHelper::Utf8ToUnicode( string strUtf8)
{
	int len = ::MultiByteToWideChar(CP_UTF8, 0, strUtf8.c_str(), -1, NULL, 0);   
	if (len == 0) return L"";   

	std::vector<wchar_t> unicode(len);   
	::MultiByteToWideChar(CP_UTF8, 0, strUtf8.c_str(), -1, &unicode[0], len);   

	return &unicode[0];   
}

/*
** Convert microsoft unicode to UTF-8.  Space to hold the returned string is
** obtained from malloc().
*/
string	StringHelper::UnicodeToUtf8( wstring strUnicode)
{
	int len = ::WideCharToMultiByte(CP_UTF8, 0, strUnicode.c_str(), -1, 0, 0, 0, 0);   
	if (len == 0) return "";   

	std::vector<char> utf8(len);   
	::WideCharToMultiByte(CP_UTF8, 0, strUnicode.c_str(), -1, &utf8[0], len, 0, 0);   

	return &utf8[0];   
}

/*
** Convert an ansi string to microsoft unicode, based on the
** current codepage settings for file apis.
** 
** Space to hold the returned string is obtained
** from malloc.
*/
wstring	StringHelper::ANSIToUnicode( string strAnsi)
{
	int nCodePage = AreFileApisANSI() ? CP_ACP : CP_OEMCP;

	int len = ::MultiByteToWideChar(nCodePage, 0, strAnsi.c_str(), -1, NULL, 0)*sizeof(WCHAR);   
	if (len == 0) return L"";   

	std::vector<wchar_t> unicode(len);   
	::MultiByteToWideChar(nCodePage, 0, strAnsi.c_str(), -1, &unicode[0], len);   

	return &unicode[0];   
}

/*
** Convert microsoft unicode to multibyte character string, based on the
** user's Ansi codepage.
**
** Space to hold the returned string is obtained from
** malloc().
*/
string	StringHelper::UnicodeToANSI( wstring strUnicode)
{
	int nCodePage = AreFileApisANSI() ? CP_ACP : CP_OEMCP;

	int len = ::WideCharToMultiByte(nCodePage, 0, strUnicode.c_str(), -1, NULL, 0, NULL, NULL);   
	if (len == 0) return "";   

	std::vector<char> utf8(len);   
	::WideCharToMultiByte(nCodePage, 0, strUnicode.c_str(), -1, &utf8[0], len, NULL, NULL);   

	return &utf8[0];   
}

string	StringHelper::ANSIToUft8( string strAnsi)
{
	wstring	wstrUnicode = StringHelper::ANSIToUnicode(strAnsi);
	return StringHelper::UnicodeToUtf8(wstrUnicode);
}

string	StringHelper::Utf8ToANSI( string strUtf8)
{
	wstring	wstrUnicode = StringHelper::Utf8ToUnicode(strUtf8);
	return StringHelper::UnicodeToANSI(wstrUnicode);
}

string	StringHelper::Replace( string strSrc, 
			      const string &strReplaced, 
			      const string &strReplacing )
{
	string strResult = strSrc;

	string::size_type pos = 0;
	string::size_type srclen = strReplaced.size();
	string::size_type dstlen = strReplacing.size();

	while( (pos =strSrc.find(strReplaced, pos)) != string::npos )
	{
		strResult.replace( pos, srclen, strReplacing );
		pos += dstlen;
	}

	return strResult;
}

std::vector<std::string> StringHelper::Split(std::string strOri, char _Ch)
{
	int i = 0;
	int nLastPos = 0;
	std::vector<std::string> vecResutl;
	std::string strSub;

	i = strOri.find(_Ch);

	while (i != -1)
	{
		strSub = strOri.substr(nLastPos, i - nLastPos);
		nLastPos = i + 1;
		i = strOri.find(_Ch, nLastPos);

		vecResutl.push_back(strSub);
	}

	if (nLastPos != 0)
	{
		strSub = strOri.substr(nLastPos, strOri.length() - nLastPos);
		vecResutl.push_back(strSub);
	}

	return vecResutl;
}
