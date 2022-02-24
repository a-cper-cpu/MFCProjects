; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CUGMSDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "UGMS.h"

ClassCount=8
Class1=CUGMSApp
Class2=CUGMSDlg
Class3=CAboutDlg

ResourceCount=8
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_UGMS_DIALOG
Class4=CPageStu
Resource4=IDD_PAGE_CHO
Resource5=IDD_PAGE_COU
Class5=CPageCou
Resource6=IDD_PAGE_STU
Class6=CPageStat
Class7=CPageCho
Resource7=IDD_PAGE_STAT
Class8=CPageWelcome
Resource8=IDD_PAGE_WELCOME

[CLS:CUGMSApp]
Type=0
HeaderFile=UGMS.h
ImplementationFile=UGMS.cpp
Filter=N

[CLS:CUGMSDlg]
Type=0
HeaderFile=UGMSDlg.h
ImplementationFile=UGMSDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_DIALOG_AREA

[CLS:CAboutDlg]
Type=0
HeaderFile=UGMSDlg.h
ImplementationFile=UGMSDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_UGMS_DIALOG]
Type=1
Class=CUGMSDlg
ControlCount=2
Control1=IDC_OUTLOOKBAR,SysListView32,1350631424
Control2=IDC_DIALOG_AREA,static,1073741831

[DLG:IDD_PAGE_STU]
Type=1
Class=CPageStu
ControlCount=20
Control1=IDC_BUTTON_QUERY,button,1342242816
Control2=IDC_BUTTON_ADD,button,1342242816
Control3=IDC_BUTTON_DELETE,button,1342242816
Control4=IDC_BUTTON_MODIFY,button,1342242816
Control5=IDC_BUTTON_FIRST,button,1342242816
Control6=IDC_BUTTON_PREVIOUS,button,1342242816
Control7=IDC_BUTTON_NEXT,button,1342242816
Control8=IDC_BUTTON_LAST,button,1342242816
Control9=IDC_STATIC,button,1342177287
Control10=IDC_EDIT_SID,edit,1350639744
Control11=IDC_EDIT_SNAME,edit,1350631552
Control12=IDC_DATETIMEPICKER_SCOMEDATE,SysDateTimePick32,1342242848
Control13=IDC_BUTTON_OK,button,1342242816
Control14=IDC_BUTTON_CANCEL,button,1342242816
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_STATIC,button,1342177287
Control20=IDC_COMBO_SSEX,combobox,1344340227

[CLS:CPageStu]
Type=0
HeaderFile=PageStu.h
ImplementationFile=PageStu.cpp
BaseClass=CDialog
Filter=D
LastObject=CPageStu
VirtualFilter=dWC

[DLG:IDD_PAGE_COU]
Type=1
Class=CPageCou
ControlCount=20
Control1=IDC_BUTTON_QUERY,button,1342242816
Control2=IDC_BUTTON_ADD,button,1342242816
Control3=IDC_BUTTON_DELETE,button,1342242816
Control4=IDC_BUTTON_MODIFY,button,1342242816
Control5=IDC_BUTTON_FIRST,button,1342242816
Control6=IDC_BUTTON_PREVIOUS,button,1342242816
Control7=IDC_BUTTON_NEXT,button,1342242816
Control8=IDC_BUTTON_LAST,button,1342242816
Control9=IDC_STATIC,button,1342177287
Control10=IDC_EDIT_COUID,edit,1350631552
Control11=IDC_EDIT_COUNAME,edit,1350631552
Control12=IDC_EDIT_COUSCORE,edit,1350631552
Control13=IDC_BUTTON_OK,button,1342242816
Control14=IDC_BUTTON_CANCEL,button,1342242816
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_COMBO_KIND,combobox,1344340227
Control20=IDC_STATIC,button,1342177287

[CLS:CPageCou]
Type=0
HeaderFile=PageCou.h
ImplementationFile=PageCou.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_COMBO_KIND

[DLG:IDD_PAGE_CHO]
Type=1
Class=CPageCho
ControlCount=20
Control1=IDC_BUTTON_QUERY,button,1342242816
Control2=IDC_BUTTON_ADD,button,1342242816
Control3=IDC_BUTTON_DELETE,button,1342242816
Control4=IDC_BUTTON_MODIFY,button,1342242816
Control5=IDC_BUTTON_FIRST,button,1342242816
Control6=IDC_BUTTON_PREVIOUS,button,1342242816
Control7=IDC_BUTTON_NEXT,button,1342242816
Control8=IDC_BUTTON_LAST,button,1342242816
Control9=IDC_STATIC,button,1342177287
Control10=IDC_EDIT_SID,edit,1350631552
Control11=IDC_EDIT_CHOID,edit,1350631552
Control12=IDC_EDIT_SCORE,edit,1350631552
Control13=IDC_BUTTON_OK,button,1342242816
Control14=IDC_BUTTON_CANCEL,button,1342242816
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352
Control17=IDC_STATIC,static,1342308352
Control18=IDC_STATIC,static,1342308352
Control19=IDC_COMBO_PASS,combobox,1344340227
Control20=IDC_STATIC,button,1342177287

[DLG:IDD_PAGE_STAT]
Type=1
Class=CPageStat
ControlCount=12
Control1=IDC_EDIT_SID,edit,1350631552
Control2=IDC_STATIC,static,1342308352
Control3=IDC_DATAGRID,{CDE57A43-8B86-11D0-B3C6-00A0C90AEA82},1342242816
Control4=IDC_EDIT_AVERAGE,edit,1350633600
Control5=IDC_EDIT_NUMCOU,edit,1350633600
Control6=IDC_EDIT_NPASSNum,edit,1350633600
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,button,1342177287
Control11=IDC_BUTTON_OK,button,1342242816
Control12=IDC_ADODC,{67397AA3-7FB1-11D0-B148-00A0C922E820},1073741824

[CLS:CPageStat]
Type=0
HeaderFile=PageStat.h
ImplementationFile=PageStat.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT_AVERAGE

[CLS:CPageCho]
Type=0
HeaderFile=PageCho.h
ImplementationFile=PageCho.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT_SID

[CLS:CPageWelcome]
Type=0
HeaderFile=PageWelcome.h
ImplementationFile=PageWelcome.cpp
BaseClass=CDialog
Filter=D
LastObject=CPageWelcome

[DLG:IDD_PAGE_WELCOME]
Type=1
Class=CPageWelcome
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,button,1342177287

