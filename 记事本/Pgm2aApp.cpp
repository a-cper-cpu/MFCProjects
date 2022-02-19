#include "StdAfx.h"
#include "Pgm2aApp.h"
#include "FrameWin.h"
#include "resource.h"

Pgm02AApp   Pgm02a;  // launch app

/***************************************************************************/
/*                                                                         */
/* InitInstance:   allocate instance of our frame main window              */
/*                                                                         */
/***************************************************************************/

BOOL  Pgm02AApp::InitInstance () {

 char wintitle[70];

 LoadString (m_hInstance, IDS_MAINTITLE, wintitle, sizeof(wintitle));
 FrameWin *ptrframe = new FrameWin (NULL, wintitle);
 // install the frame window as the main app window and show that window
 m_pMainWnd = ptrframe;               // m_pMainWnd- public member of CFrameWnd
 m_pMainWnd->ShowWindow (m_nCmdShow); // install show type, nor, min, maximized
 m_pMainWnd->UpdateWindow ();         // force windows to be painted initially

 SetDialogBkColor ();                 // set gray dialog boxes and messageboxes
 return TRUE;
}
