/****************************** 模块头 *************************************\
模块名:  CppCLINETAssemblyWrapper.h
项目:    CppCLINETAssemblyWrapper
版权：   (c) Microsoft Corporation.

文件中的代码声明了C++的类CSSimpleObjectWrapper封装在.NET类库CSClassLibrary
中定义的类CSSimpleObject。本地的C++应用程序可以引用这个封装类并链接DLL去间
接调用.NET类。


  CppCallNETAssemblyWrapper (本地C++应用程序)
          -->
      CppCLINETAssemblyWrapper (C++/CLI的封装)
              -->
          CSClassLibrary (.NET程序集)

This source is subject to the Microsoft Public License.
See http://www.microsoft.com/opensource/licenses.mspx#Ms-PL.
All other rights reserved.

THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, 
EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
\***************************************************************************/

#pragma once

#include <windows.h>

#ifdef CPPCLINETASSEMBLYWRAPPER_EXPORTS
#define SYMBOL_DECLSPEC __declspec(dllexport)
#else
#define SYMBOL_DECLSPEC	__declspec(dllimport)
#endif


// C#类库上的CSClassLibrary进行封装的类CSSimpleObjectWrapper. 
class SYMBOL_DECLSPEC CSSimpleObjectWrapper
{
public:
    CSSimpleObjectWrapper(void);
    virtual ~CSSimpleObjectWrapper(void);

    // 属性
    float get_FloatProperty(void);
    void set_FloatProperty(float fVal);

    // 方法
    HRESULT ToString(PWSTR pszBuffer, DWORD dwSize);

    // 静态方法
    static int GetStringLength(PWSTR pszString);

private:
    void *m_impl;
};