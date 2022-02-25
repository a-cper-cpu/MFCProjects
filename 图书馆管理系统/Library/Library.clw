; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLibraryDlg
LastTemplate=CRecordset
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Library.h"

ClassCount=13
Class1=CLibraryApp
Class2=CLibraryDlg
Class3=CAboutDlg

ResourceCount=8
Resource1=IDD_LIBRARY_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG_LOGIN
Class4=CLoginDlg
Class5=CClerkDataSet
Resource4=IDD_DIALOG_READER
Class6=CBookDlg
Class7=CBookDataSet
Resource5=IDD_DIALOG_BOOK
Class8=CReaderDlg
Class9=CReaderDataSet
Resource6=IDD_ABOUTBOX
Class10=CBorrowDlg
Class11=CBorrowDataSet
Resource7=IDD_DIALOG_BORROW
Class12=CReturnDlg
Class13=CBorrowSet
Resource8=IDD_DIALOG_RETURN

[CLS:CLibraryApp]
Type=0
HeaderFile=Library.h
ImplementationFile=Library.cpp
Filter=N
LastObject=CLibraryApp

[CLS:CLibraryDlg]
Type=0
HeaderFile=LibraryDlg.h
ImplementationFile=LibraryDlg.cpp
Filter=D
LastObject=CLibraryDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=LibraryDlg.h
ImplementationFile=LibraryDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LIBRARY_DIALOG]
Type=1
Class=CLibraryDlg
ControlCount=11
Control1=IDC_STATIC,static,1342177294
Control2=IDC_BUTTON_BOOK,button,1342242816
Control3=IDC_BUTTON_READER,button,1342242816
Control4=IDC_BUTTON_BORROW,button,1342242816
Control5=IDC_BUTTON_RETURN,button,1342242816
Control6=IDC_BUTTON_GOODBYE,button,1342242816
Control7=IDC_STATIC,static,1342308865
Control8=IDC_STATIC,static,1342308865
Control9=IDC_STATIC,static,1342308865
Control10=IDC_STATIC,static,1342308865
Control11=IDC_STATIC,static,1342308865

[DLG:IDD_DIALOG_LOGIN]
Type=1
Class=CLoginDlg
ControlCount=9
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308354
Control3=IDC_STATIC,static,1342308354
Control4=IDC_LOGIN_NAME,edit,1350631552
Control5=IDC_LOGIN_PASSWORD,edit,1350631584
Control6=IDC_CONFIRM,button,1342242817
Control7=IDC_CANCEL,button,1342242816
Control8=IDC_STATIC,static,1342177287
Control9=IDC_STATIC,static,1342177287

[CLS:CLoginDlg]
Type=0
HeaderFile=LoginDlg.h
ImplementationFile=LoginDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLoginDlg
VirtualFilter=dWC

[CLS:CClerkDataSet]
Type=0
HeaderFile=ClerkDataSet.h
ImplementationFile=ClerkDataSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CClerkDataSet

[DB:CClerkDataSet]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[CLERK_ID], 12, 60
Column2=[NAME], 12, 16
Column3=[ID_CARD], 12, 36
Column4=[PASSWORD], 12, 60
Column5=[OFFICIER], 12, 60

[DLG:IDD_DIALOG_BOOK]
Type=1
Class=CBookDlg
ControlCount=31
Control1=IDC_BOOKNAME_Q,edit,1350631552
Control2=IDC_BOOKID_Q,edit,1350631552
Control3=IDC_BOOKID,edit,1350631552
Control4=IDC_BOOKNAME,edit,1350631552
Control5=IDC_AUTHOR,edit,1350631552
Control6=IDC_PRESS,edit,1350631552
Control7=IDC_PRESSDATE,edit,1350631552
Control8=IDC_FLAG_BORROW,edit,1350631552
Control9=IDC_STATIC,static,1342177287
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342177287
Control13=IDC_STATIC,static,1342308354
Control14=IDC_STATIC,static,1342308354
Control15=IDC_STATIC,static,1342308354
Control16=IDC_STATIC,static,1342177287
Control17=IDC_FIRST,button,1342242816
Control18=IDC_PRIOR,button,1342242816
Control19=IDC_NEXT,button,1342242816
Control20=IDC_LAST,button,1342242816
Control21=IDC_NEW,button,1342242816
Control22=IDC_EDIT,button,1342242816
Control23=IDC_SAVE,button,1342242816
Control24=IDC_CANCEL_REC,button,1342242816
Control25=IDC_ENQUERY,button,1342242816
Control26=IDC_DELETE,button,1342242816
Control27=IDC_EXIT,button,1342242816
Control28=IDC_STATIC,static,1342308354
Control29=IDC_STATIC,static,1342308354
Control30=IDC_STATIC,static,1342308354
Control31=IDC_STATIC,static,1342308352

[CLS:CBookDlg]
Type=0
HeaderFile=BookDlg.h
ImplementationFile=BookDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CBookDlg
VirtualFilter=dWC

[CLS:CBookDataSet]
Type=0
HeaderFile=BookDataSet.h
ImplementationFile=BookDataSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CBookDataSet]
DB=1
DBType=ODBC
ColumnCount=6
Column1=[BOOK_ID], 12, 60
Column2=[BOOK_NAME], 12, 100
Column3=[AUTHOR], 12, 60
Column4=[PRESS], 12, 100
Column5=[PRESS_DATE], 11, 16
Column6=[FLAG_BORROW], 12, 20

[DLG:IDD_DIALOG_READER]
Type=1
Class=CReaderDlg
ControlCount=24
Control1=IDC_STATIC,static,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_READERNAME_Q,edit,1350631552
Control5=IDC_READERID_Q,edit,1350631552
Control6=IDC_STATIC,static,1342177287
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_READERID,edit,1350631552
Control11=IDC_READERNAME,edit,1350631552
Control12=IDC_IDCARD,edit,1350631552
Control13=IDC_STATIC,static,1342177287
Control14=IDC_FIRST,button,1342242816
Control15=IDC_PRIOR,button,1342242816
Control16=IDC_NEXT,button,1342242816
Control17=IDC_LAST,button,1342242816
Control18=IDC_NEW,button,1342242816
Control19=IDC_EDIT,button,1342242816
Control20=IDC_SAVE,button,1342242816
Control21=IDC_CANCEL_REC,button,1342242816
Control22=IDC_ENQUERY,button,1342242816
Control23=IDC_DELETE,button,1342242816
Control24=IDC_EXIT,button,1342242816

[CLS:CReaderDlg]
Type=0
HeaderFile=ReaderDlg.h
ImplementationFile=ReaderDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CReaderDlg

[DB:CReaderDataSet]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[READER_ID], 12, 16
Column2=[NAME], 12, 16
Column3=[IDCARD], 12, 36
Column4=[MAXNUM_CAN_BORROW], 5, 2
Column5=[FLAG_BORROW], 12, 2

[CLS:CReaderDataSet]
Type=0
HeaderFile=ReaderDataSet.h
ImplementationFile=ReaderDataSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CReaderDataSet

[DLG:IDD_DIALOG_BORROW]
Type=1
Class=CBorrowDlg
ControlCount=8
Control1=IDC_STATIC,static,1342177287
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_READER_ID,edit,1350631552
Control5=IDC_BOOK_ID,edit,1350631552
Control6=IDC_STATIC,static,1342177287
Control7=IDC_CONFIRM,button,1342242817
Control8=IDC_CANCEL,button,1342242816

[CLS:CBorrowDlg]
Type=0
HeaderFile=BorrowDlg.h
ImplementationFile=BorrowDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CBorrowDlg

[CLS:CBorrowDataSet]
Type=0
HeaderFile=BorrowDataSet.h
ImplementationFile=BorrowDataSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CBorrowDataSet

[DB:CBorrowDataSet]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[READER_ID], 12, 60
Column2=[BOOK_ID], 12, 60
Column3=[BORROW_DATE], 11, 16
Column4=[B_CLERK_ID], 12, 60
Column5=[ID], 4, 4

[DLG:IDD_DIALOG_RETURN]
Type=1
Class=CReturnDlg
ControlCount=14
Control1=ID_CONFIRM,button,1342177280
Control2=IDC_STATIC,static,1342308352
Control3=IDC_BOOK_ID,edit,1350631552
Control4=IDC_STATIC,static,1342308352
Control5=IDC_READERNAME,edit,1350631552
Control6=IDC_STATIC,static,1342308352
Control7=IDC_BORROWDATE,edit,1350631552
Control8=IDC_STATIC,static,1342308352
Control9=IDC_RETURNDATE,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_DAYS,edit,1350631552
Control12=IDC_STATIC,static,1342177287
Control13=IDC_STATIC,static,1342177287
Control14=IDC_STATIC,static,1342177287

[CLS:CReturnDlg]
Type=0
HeaderFile=ReturnDlg.h
ImplementationFile=ReturnDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CReturnDlg
VirtualFilter=dWC

[CLS:CBorrowSet]
Type=0
HeaderFile=BorrowSet.h
ImplementationFile=BorrowSet.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r

[DB:CBorrowSet]
DB=1
DBType=ODBC
ColumnCount=10
Column1=[BORROW].[READER_ID], 12, 60
Column2=[BOOK_ID], 12, 60
Column3=[BORROW_DATE], 11, 16
Column4=[B_CLERK_ID], 12, 60
Column5=[ID], 4, 4
Column6=[READER].[READER_ID], 12, 16
Column7=[NAME], 12, 16
Column8=[IDCARD], 12, 36
Column9=[MAXNUM_CAN_BORROW], 5, 2
Column10=[FLAG_BORROW], 12, 2

[DB:CClerkDatSet]
DB=1
DBType=ODBC
ColumnCount=0

[DB:CClerkDaSet]
DB=1
DBType=ODBC
ColumnCount=0

