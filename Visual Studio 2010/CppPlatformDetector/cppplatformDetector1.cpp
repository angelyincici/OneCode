{\rtf1\ansi\ansicpg936\deff0\deflang1033\deflangfe2052{\fonttbl{\f0\fmodern\fprq6\fcharset134 \'cb\'ce\'cc\'e5;}}
{\*\generator Msftedit 5.41.15.1515;}\viewkind4\uc1\pard\lang2052\f0\fs20 /****************************** \'c4\'a3\'bf\'e9\'cd\'b7******************************\\\par
\'c4\'a3\'bf\'e9\'d7\'d6:    CppPlatformDetector.cpp\par
\'cf\'ee\'c4\'bf\'c3\'fb:        CppPlatformDetector\par
\'b0\'e6\'c8\'a8 (c) Microsoft Corporation.\par
\par
The CppPlatformDetector code sample demonstrates the following tasks related \par
to platform detection:\par
\par
1. Detect the name of the current operating system. \par
   (e.g. "Microsoft Windows 7 Enterprise")\par
2. Detect the version of the current operating system.\par
   (e.g. "Microsoft Windows NT 6.1.7600.0")\par
3. Determine whether the current operating system is a 64-bit operating \par
   system. \par
4. Determine whether the current process is a 64-bit process. \par
5. Determine whether an arbitrary process running on the system is 64-bit. \par
\par
This source is subject to the Microsoft Public License.\par
See http://www.microsoft.com/opensource/licenses.mspx#Ms-PL.\par
All other rights reserved.\par
\par
THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, \par
EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED \par
WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.\par
\\***************************************************************************/\par
\par
#include <stdio.h>\par
#include <Windows.h>\par
#include "PlatformDetector.h"\par
\par
\par
int wmain(int argc, wchar_t *argv[])\par
\{\par
    //\par
    // \'b4\'f2\'d3\'a1\'b5\'b1\'c7\'b0\'b2\'d9\'d7\'f7\'cf\'b5\'cd\'b3\'b5\'c4\'c3\'fb\'d7\'d6\par
    //\par
\par
    wchar_t szName[512];\par
    if (GetOSName(szName, ARRAYSIZE(szName)))\par
    \{\par
        wprintf(L"Current OS: %s\\n", szName);\par
    \}\par
    else\par
    \{\par
        wprintf(L"Cannot get the operating system name\\n");\par
    \}\par
\par
    //\par
    // \'b4\'f2\'d3\'a1\'b5\'b1\'c7\'b0\'b2\'d9\'d7\'f7\'cf\'b5\'cd\'b3\'b5\'c4\'b0\'e6\'b1\'be\'d7\'d6\'b7\'fb\'b4\'ae.\par
    //\par
\par
    wchar_t szVersionString[512];\par
    if (GetOSVersionString(szVersionString, ARRAYSIZE(szVersionString)))\par
    \{\par
        wprintf(L"Version: %s\\n", szVersionString);\par
    \}\par
    else\par
    \{\par
        wprintf(L"Cannot get the operating system version\\n");\par
    \}\par
\par
    //\par
    // \'c8\'b7\'b6\'a8\'b5\'b1\'c7\'b0\'b2\'d9\'d7\'f7\'cf\'b5\'cd\'b3\'ca\'c7\'b7\'f1\'ca\'c764\'ce\'bb.\par
    //\par
\par
    BOOL f64bitOS = Is64BitOS();\par
    wprintf(L"Current OS is %s64-bit\\n", f64bitOS ? L"" : L"not ");\par
\par
    //\par
    // \'c8\'b7\'b6\'a8\'b5\'b1\'c7\'b0\'b5\'c4\'bd\'f8\'b3\'cc\'ca\'c7\'b7\'f1\'ca\'c764\'ce\'bb\'b5\'c4. \par
    //\par
\par
    BOOL f64bitProc = Is64BitProcess();\par
    wprintf(L"Current process is %s64-bit\\n", f64bitProc ? L"" : L"not ");\par
\par
    //\par
    // \'c8\'b7\'b6\'a8\'d4\'cb\'d0\'d0\'d4\'da\'cf\'b5\'cd\'b3\'d6\'d0\'b5\'c4\'c8\'ce\'d2\'e2\'d2\'bb\'b8\'f6\'bd\'f8\'b3\'cc\'ca\'c7\'b7\'f1\'ca\'c764\'ce\'bb\'bd\'f8\'b3\'cc.\par
    //\par
\par
    if (argc > 1)\par
    \{\par
        // \'c8\'e7\'b9\'fb\'d2\'bb\'b8\'f6\'bd\'f8\'b3\'ccID\'d4\'da\'c3\'fc\'c1\'ee\'d0\'d0\'d6\'d0\'b1\'bb\'d6\'b8\'b6\'a8\'a3\'ac\'d4\'f2\'bb\'f1\'c8\'a1\'bd\'f8\'b3\'ccID\'a3\'ac\'b2\'a2\'b4\'f2\'bf\'aa\'bd\'f8\'b3\'cc\'be\'e4\'b1\'fa.\par
        DWORD dwProcessId = _wtoi(argv[1]);\par
        if (dwProcessId != 0 /*conversion succeeds*/)\par
        \{\par
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE,\par
                dwProcessId);\par
            if (hProcess != NULL)\par
            \{\par
                // \'bc\'ec\'b2\'e2\'d6\'b8\'b6\'a8\'bd\'f8\'b3\'cc\'ca\'c7\'b7\'f1\'ca\'c764\'ce\'bb.\par
                BOOL f64bitProc = Is64BitProcess(hProcess);\par
                wprintf(L"Process %d is %s64-bit\\n", dwProcessId, \par
                    f64bitProc ? L"" : L"not ");\par
\par
                CloseHandle(hProcess);\par
            \}\par
            else\par
            \{\par
                wprintf(L"OpenProcess(%d) failed w/err 0x%08lx\\n", \par
                    dwProcessId, GetLastError());\par
            \}\par
        \}\par
        else\par
        \{\par
            wprintf(L"Invalid process ID: %s\\n", argv[1]);\par
        \}\par
    \}\par
\par
    return 0;\par
\}\par
}
 