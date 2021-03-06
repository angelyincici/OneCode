=============================================================================
        WIN32 应用程序 : CppReceiveWM_COPYDATA 项目概述
=============================================================================

/////////////////////////////////////////////////////////////////////////////
概要:

基于windows 消息 WM_COPYDATA 进程间通信(IPC) 是一种在本地机器上windows应用程序交换数据机制。

接受程序必须是一个windows应用程序。数据被传递必须不包含指针或者不能被应用程序接受的指向对象的引用。

当发送WM_COPYDATA消息时，引用数据不能被发送进程别的线程改变。 接受应用程序应该只考虑只读数据。

如果接受应用程序想要在SendMessage返回之后进入数据， 它必须拷贝数据到本地缓存。

这个代码例子示范了接受一个从应用程序（CppSendWM_COPYDATA）通过处理WM_COPYDATA,发送到客户端的数据结构
（MY_STRUCT）



/////////////////////////////////////////////////////////////////////////////
演示:

下面的步骤贯穿整个WM_COPYDATA例子演示。

步骤1. 当你成功的在vs2008编译了CppSendWM_COPYDATA和CppReceiveWM_COPYDATA例子后，你将会得到
CSSendwM_COPYDATA.exe以及CSReceiveWM_COPYDATA.exe.

步骤2： 运行CppSendWM_COPYDATA.exe以及CppReceiveWM_COPYDATA.exe程序， 在CppSendWM_COPYDATA程序中
输入数字和消息
	数字： 123456
	消息： 你好，世界



点击发送按钮。 数字和消息将会被发送到CppReceiveWM_COPYDATA通过 WM_COPYDATA消息， 当CppReceiveWM_COPYDATA

收到消息后， 应用程序解压它们并且把它们显示在窗口上。



/////////////////////////////////////////////////////////////////////////////
与本例相关:
(当前例子和其他例子在微软 All-In-One Code Framework http://1code.codeplex.com)

CppSendWM_COPYDATA -> CppReceiveWM_COPYDATA
CppSendWM_COPYDATA 发送数据到 CppReceiveWM_COPYDATA 通过WM_COPYDATA消息


/////////////////////////////////////////////////////////////////////////////
代码逻辑:

1. 在DiagPro或者WndProc窗口过程中，获取和处理WM_COPYDATA消息
	HANDLE_MSG (hWnd, WM_COPYDATA, OnCopyData);
	
	BOOL OnCopyData(HWND hWnd, HWND hwndFrom, PCOPYDATASTRUCT pcds)
	{  }

2. 在OnCopyData中，从WM_COPYDATA消息的lparam中得到COPYDATASTRUCT结构，并且从COPYDATASTRUCT.lpData
   获取数据结构（MY_STRUCT）

   接受程序必须考虑数据（COPYDATASTRUCT->lpData）数据只读。它在处理消息的过程中是有效的。
   接受程序不应该释放被参数引用的内存。如果接受程序在SendMessage返回后需要访问数据，它必须拷贝数据到
   本地缓存。

	MY_STRUCT myStruct;
	memcpy_s(&myStruct, sizeof(myStruct), pcds->lpData, pcds->cbData);

4. 在窗口中显示数据


/////////////////////////////////////////////////////////////////////////////
参考文献:

MSDN: WM_COPYDATA Message
http://msdn.microsoft.com/en-us/library/ms649011.aspx

MSDN: Using Data Copy
http://msdn.microsoft.com/en-us/library/ms649009.aspx


/////////////////////////////////////////////////////////////////////////////
