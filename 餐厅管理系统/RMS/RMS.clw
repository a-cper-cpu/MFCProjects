; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPayPage
LastTemplate=CRecordset
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "RMS.h"

ClassCount=11
Class1=CRMSApp
Class2=CRMSDlg
Class3=CAboutDlg

ResourceCount=7
Resource1=IDD_DIALOG_DESK
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDD_DIALOG_DISH
Resource5=IDD_RMS_DIALOG
Class4=CDishPage
Class5=CDeskPage
Resource6=IDD_DIALOG_ORDER
Class6=COrderPage
Class7=CDishSet
Class8=CPayPage
Class9=CDeskSet
Class10=COrderSet
Class11=CPaySet
Resource7=IDD_DIALOG_PAY

[CLS:CRMSApp]
Type=0
HeaderFile=RMS.h
ImplementationFile=RMS.cpp
Filter=N

[CLS:CRMSDlg]
Type=0
HeaderFile=RMSDlg.h
ImplementationFile=RMSDlg.cpp
Filter=D
LastObject=CRMSDlg

[CLS:CAboutDlg]
Type=0
HeaderFile=RMSDlg.h
ImplementationFile=RMSDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_RMS_DIALOG]
Type=1
Class=CRMSDlg
ControlCount=1
Control1=IDC_STATIC,static,1342177294

[DLG:IDD_DIALOG_DISH]
Type=1
Class=CDishPage
ControlCount=17
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_CODE,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_KIND,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_NAME,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_EDIT_DESC,edit,1350631556
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDIT_PRICE,edit,1350631552
Control12=IDC_STATIC,button,1342177287
Control13=IDC_LIST_DISP,SysListView32,1350631425
Control14=IDC_BUTTON_ADD,button,1342242816
Control15=IDC_BUTTON_MODIFY,button,1342242816
Control16=IDC_BUTTON_DEL,button,1342242816
Control17=IDC_BUTTON_CLEAR,button,1342242816

[DLG:IDD_DIALOG_DESK]
Type=1
Class=CDeskPage
ControlCount=15
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT_CODE,edit,1350631552
Control4=IDC_EDIT_NUM,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_DESC,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_COMBO_FREE,combobox,1344340226
Control10=IDC_LIST_DISP,SysListView32,1350631425
Control11=IDC_STATIC,button,1342177287
Control12=IDC_BUTTON_ADD,button,1342242816
Control13=IDC_BUTTON_MODIFY,button,1342242816
Control14=IDC_BUTTON_DEL,button,1342242816
Control15=IDC_BUTTON_CLEAR,button,1342242816

[DLG:IDD_DIALOG_ORDER]
Type=1
Class=COrderPage
ControlCount=14
Control1=IDC_LIST_DISP,SysListView32,1350631425
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_NUM,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_DATETIMEPICKER_DATE,SysDateTimePick32,1342242852
Control8=IDC_BUTTON_ADD,button,1342242816
Control9=IDC_BUTTON_MODIFY,button,1342242816
Control10=IDC_BUTTON_DEL,button,1342242816
Control11=IDC_BUTTON_CLEAR,button,1342242816
Control12=IDC_STATIC,button,1342177287
Control13=IDC_EDIT_DESKCODE,edit,1350631552
Control14=IDC_EDIT_DISHCODE,edit,1350631552

[CLS:CDishPage]
Type=0
HeaderFile=DishPage.h
ImplementationFile=DishPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CDishPage
VirtualFilter=idWC

[DLG:IDD_DIALOG_PAY]
Type=1
Class=CPayPage
ControlCount=13
Control1=IDC_STATIC,static,1342308352
Control2=IDC_EDIT_DESKCODE,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_EDIT_DISHNAME,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT_MONEY,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_DATETIMEPICKER_DATE,SysDateTimePick32,1342242848
Control10=IDC_STATIC,button,1342177287
Control11=IDC_LIST_DISP,SysListView32,1350631425
Control12=IDC_BUTTON_PAY,button,1342242816
Control13=IDC_EDIT_DISHCODE,edit,1350631552

[DB:CDishSet]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[Dish_code], 12, 100
Column2=[Dish_name], 12, 100
Column3=[Dish_kind], 12, 100
Column4=[Dish_price], 7, 4
Column5=[Dish_detail], 12, 100

[CLS:CDishSet]
Type=0
HeaderFile=DishSet.h
ImplementationFile=DishSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[CLS:CDeskPage]
Type=0
HeaderFile=DeskPage.h
ImplementationFile=DeskPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CDeskPage
VirtualFilter=idWC

[CLS:COrderPage]
Type=0
HeaderFile=OrderPage.h
ImplementationFile=OrderPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=COrderPage
VirtualFilter=idWC

[CLS:CPayPage]
Type=0
HeaderFile=PayPage.h
ImplementationFile=PayPage.cpp
BaseClass=CPropertyPage
Filter=D
LastObject=CPayPage
VirtualFilter=idWC

[CLS:CDeskSet]
Type=0
HeaderFile=DeskSet.h
ImplementationFile=DeskSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CDeskSet]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[Desk_code], 12, 100
Column2=[Desk_num], 5, 2
Column3=[Desk_detail], 12, 100
Column4=[Desk_full], 5, 2

[CLS:COrderSet]
Type=0
HeaderFile=OrderSet.h
ImplementationFile=OrderSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:COrderSet]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[Desk_code], 12, 100
Column2=[Dish_code], 12, 100
Column3=[Dish_num], 4, 4
Column4=[AppendDate], 11, 16
Column5=[PayFor], 5, 2

[CLS:CPaySet]
Type=0
HeaderFile=PaySet.h
ImplementationFile=PaySet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CPaySet

[DB:CPaySet]
DB=1
DBType=ODBC
ColumnCount=10
Column1=[dish].[Dish_code], 12, 100
Column2=[Dish_name], 12, 100
Column3=[Dish_kind], 12, 100
Column4=[Dish_price], 7, 4
Column5=[Dish_detail], 12, 100
Column6=[Desk_code], 12, 100
Column7=[order].[Dish_code], 12, 100
Column8=[Dish_num], 4, 4
Column9=[AppendDate], 11, 16
Column10=[PayFor], 5, 2

