; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CServerSocket
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "chat.h"

ClassCount=6
Class1=CChatApp
Class2=CChatDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CClientSocket
Class5=ServerSocket
Class6=CServerSocket
Resource3=IDD_CHAT_DIALOG

[CLS:CChatApp]
Type=0
HeaderFile=chat.h
ImplementationFile=chat.cpp
Filter=N

[CLS:CChatDlg]
Type=0
HeaderFile=chatDlg.h
ImplementationFile=chatDlg.cpp
Filter=D
LastObject=IDC_MESSAGE
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=chatDlg.h
ImplementationFile=chatDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CHAT_DIALOG]
Type=1
Class=CChatDlg
ControlCount=15
Control1=IDC_STATIC,button,1342178055
Control2=IDC_SHOWMESSAGE,edit,1353783428
Control3=IDC_STATIC,button,1342177287
Control4=IDC_CONNECT,button,1342242816
Control5=IDC_SETSERVER,button,1342242816
Control6=IDC_STATIC,static,1342308865
Control7=IDC_NAME,edit,1350631552
Control8=IDC_STATIC,static,1342308865
Control9=IDC_MESSAGE,edit,1350631552
Control10=IDC_SEND,button,1342242816
Control11=IDC_STATIC,button,1342177287
Control12=IDC_STATIC,static,1342308865
Control13=IDC_IPADDRESS,SysIPAddress32,1342242816
Control14=IDC_STATIC,static,1342308865
Control15=IDC_PORT,edit,1350631552

[CLS:CClientSocket]
Type=0
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq
LastObject=CClientSocket

[CLS:ServerSocket]
Type=0
HeaderFile=ServerSocket.h
ImplementationFile=ServerSocket.cpp
BaseClass=CSocket
Filter=N

[CLS:CServerSocket]
Type=0
HeaderFile=ServerSocket.h
ImplementationFile=ServerSocket.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq
LastObject=CServerSocket

