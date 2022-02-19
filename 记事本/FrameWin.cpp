#include "StdAfx.h"
#include "FrameWin.h"
#include "resource.h"

/***************************************************************************/
/*                                                                         */
/* FrameWin Events Response Table                                          */
/*                                                                         */
/***************************************************************************/

BEGIN_MESSAGE_MAP(FrameWin, CFrameWnd)
 ON_WM_KEYDOWN()
 ON_WM_SIZE ()
 ON_WM_CREATE () 
 ON_WM_CLOSE ()
 ON_WM_DESTROY ()
 ON_WM_RBUTTONDOWN ()
 ON_MESSAGE(WM_DISPLAYCHANGE,    OnDisplayChange)
 ON_COMMAND(CM_FONTCHANGE,       CmFontChange)
 ON_COMMAND(CM_EXIT,             CmExit)
 ON_COMMAND(CM_FILENEW,          CmFileNew)
 ON_COMMAND(CM_FILEOPEN,         CmFileOpen)
 ON_COMMAND(CM_FILESAVE,         CmFileSave)
 ON_COMMAND(CM_FILESAVEAS,       CmFileSaveAs)
 ON_COMMAND(CM_EDITUNDO,         CmEditUndo)
 ON_COMMAND(CM_EDITCUT,          CmEditCut)
 ON_COMMAND(CM_EDITCOPY,         CmEditCopy)
 ON_COMMAND(CM_EDITPASTE,        CmEditPaste)
 ON_COMMAND(CM_EDITCLEAR,        CmEditClear)
 ON_COMMAND(CM_HELPABOUT,        CmHelpAbout)
 ON_UPDATE_COMMAND_UI(CM_FILESAVE,     CmEnableHaveFile)
 ON_UPDATE_COMMAND_UI(CM_FILESAVEAS,   CmEnableHaveFile)
END_MESSAGE_MAP()

/***************************************************************************/
/*                                                                         */
/* Framewin: Construct the window object                                   */
/*                                                                         */
/***************************************************************************/

          FrameWin::FrameWin (CWnd* ptrparent, const char* title)
                  : CFrameWnd () {

 DWORD style = WS_OVERLAPPEDWINDOW;  // set window styles
 CRect rect (10, 10, 600, 450);      // set init pos and size
 LoadAccelTable ("MAINMENU");        // install keybd accelerators
 ptrlogfont = NULL;                  // set no font loaded
 fontcolor = RGB (0, 0, 0);          // set default font color black
 hfont = 0;                          // set no CEdit's font

 Create ( AfxRegisterWndClass (
               CS_VREDRAW | CS_HREDRAW,       // register window style UINT
               AfxGetApp()->LoadStandardCursor (IDC_ARROW), // use arrow cur
               (HBRUSH) GetStockObject (LTGRAY_BRUSH),      // gray brush
               AfxGetApp()->LoadStandardIcon (IDI_APPLICATION)),// set min icon
          title,               // window caption
          style,               // wndclass DWORD style
          rect,                // set initial window position
          ptrparent,           // the parent window, here none
          "MAINMENU");         // assign the main menu
}

/***************************************************************************/
/*                                                                         */
/* OnCreate: get average character height and width                        */
/*                                                                         */
/***************************************************************************/

int      FrameWin::OnCreate (LPCREATESTRUCT lpCS) {

 int retcd = CFrameWnd::OnCreate (lpCS); // pass along to base class

 CRect rect;
 GetClientRect (&rect);
 
 // allocate a CEdit control as a client window to handle the file editing
 // key factor is style ES_MULTILINE
 ptreditwin = new CEdit;
 ptreditwin->Create (WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_AUTOVSCROLL |
                     WS_VSCROLL | WS_HSCROLL | ES_MULTILINE | ES_WANTRETURN,
                     rect, this, EDITWINDOW);
 return retcd;
}

/***************************************************************************/
/*                                                                         */
/* OnDestroy: remove any menu objects, here none                           */
/*                                                                         */
/***************************************************************************/
  
void      FrameWin::OnDestroy () {

 CFrameWnd::OnDestroy();
 if (ptreditwin) delete ptreditwin; // delete the CEdit control
 if (ptrlogfont) delete ptrlogfont; // delete any user font;
}

/***************************************************************************/
/*                                                                         */
/* CmExit:  determine if the app can be shut down                          */
/*                                                                         */
/***************************************************************************/

void      FrameWin::CmExit () {

 PostMessage (WM_CLOSE);
}

/***************************************************************************/
/*                                                                         */
/* OnClose: determine if the app can be shut down                          */
/*                                                                         */
/***************************************************************************/

void      FrameWin::OnClose () {

 if (ptreditwin->GetModify ()) SaveCheck ();   // save file if needed

 if (DisplayMsg (IDS_MSG_QUERY, IDS_MSG_QUIT, MB_YESNO | MB_ICONQUESTION) ==
    IDYES) CFrameWnd::OnClose ();
}

/***************************************************************************/
/*                                                                         */
/* OnSize: acquire the current dimensions of the client window             */
/*                                                                         */
/***************************************************************************/

void      FrameWin::OnSize (UINT flags, int width, int height) { 

 CFrameWnd::OnSize    (flags, width, height);

 // force the CEdit client to resize itself to our new size
 ptreditwin->MoveWindow (0, 0, width, height, TRUE);
}

/***************************************************************************/
/*                                                                         */
/* OnRButtonDown: popup edit menu as a floating menu                       */
/*                                                                         */
/***************************************************************************/

void      FrameWin::OnRButtonDown (UINT, CPoint point) {

 CMenu *ptrmenu  = GetMenu ();               // point to main menu object
 CMenu *ptrpopup = ptrmenu->GetSubMenu (1);  // point to edit popup menu 
  
 ptrpopup->TrackPopupMenu (0, point.x, point.y, this, 0); // get selection
}

/***************************************************************************/
/*                                                                         */
/* DisplayMsg: displays passed error message and return user response      */
/*                                                                         */
/***************************************************************************/

int       FrameWin::DisplayMsg (int id1, int id2, UINT flags) {

 CString msg1;
 CString msg2;
 msg1.LoadString (id1);
 msg2.LoadString (id2);
 return MessageBox (msg2, msg1, flags);
}

/***************************************************************************/
/*                                                                         */
/* CmFontChange: get users font request and implement it                   */
/*                                                                         */
/***************************************************************************/

void      FrameWin::CmFontChange () {
 
 CFontDialog  *ptrdlg;
 static char   printer[80];
 char         *device, *driver, * output;
 CDC          *ptrprinterDC = new CDC;

 // get access to a printer DC from the ini file installed printer
 GetProfileString ("windows", "device", "...", printer, 80);
 if ((device = strtok (printer, ",")) != NULL &&
     (driver = strtok (NULL,    ",")) != NULL &&
     (output = strtok (NULL,    ",")) != NULL) {
  // a default printer exists, so get a DC for it
  ptrprinterDC->CreateDC (driver, device, output, NULL);
  // if the user has already chosen a font, use that one as the initial font
  if (ptrlogfont) ptrdlg = new CFontDialog (ptrlogfont, CF_EFFECTS | 
                      CF_PRINTERFONTS | CF_FORCEFONTEXIST, ptrprinterDC, this);
  else ptrdlg = new CFontDialog (NULL, CF_EFFECTS |
                      CF_PRINTERFONTS | CF_FORCEFONTEXIST, ptrprinterDC, this);
 }
 else {
  // cannot find the default printer, so use printer only fonts instead, if
  // user has already chosen a font, use it as the initial font in the dialog
  if (ptrlogfont) ptrdlg = new CFontDialog (ptrlogfont, CF_EFFECTS | 
                          CF_PRINTERFONTS | CF_FORCEFONTEXIST, NULL, this);
  else ptrdlg = new CFontDialog (NULL, CF_EFFECTS |
                          CF_PRINTERFONTS | CF_FORCEFONTEXIST, NULL, this);
 }
 
 ptrdlg->m_cf.rgbColors = fontcolor;   // install current color

 if (ptrdlg->DoModal () == IDOK) {     // get user font choice
  if (!ptrlogfont) ptrlogfont = new LOGFONT; // 1st time, create LOGFONT
  memcpy (ptrlogfont, &(ptrdlg->m_lf), sizeof (LOGFONT)); // copy user choice
  fontcolor = ptrdlg->GetColor ();     // save color choice
  hfont = CreateFontIndirect (ptrlogfont);
  // force the CEdit window to use new font
  ptreditwin->SendMessage (WM_SETFONT, (UINT) hfont, 0L);
  Invalidate();                        // force a screen repaint
 }
 delete ptrprinterDC;
 delete ptrdlg;
}

/***************************************************************************/
/*                                                                         */
/* SaveCheck: query user about needed file save                            */
/*                                                                         */
/***************************************************************************/

void      FrameWin::SaveCheck () {

 // based on user request and whether or not file has a name, send save msgs
 if (DisplayMsg (IDS_MSG_QUERY,
                 IDS_MSG_NOTSAVE, MB_YESNO | MB_ICONQUESTION) == IDYES) {
  if (strcmp (filename, "")==0)
      SendMessage (WM_COMMAND, CM_FILESAVEAS, 0L);
  else
      SendMessage (WM_COMMAND, CM_FILESAVE, 0L);
 }
}

/***************************************************************************/
/*                                                                         */
/* UpdateCaption: place new filename into title bar                        */
/*                                                                         */
/***************************************************************************/

void      FrameWin::UpdateCaption () {

 char newtitle[MAX_PATH + 81];        // get main fame title
 LoadString (AfxGetApp()->m_hInstance, IDS_MAINTITLE, newtitle, 81);
 
 if (filename[0] == 0) {              // append filename or untitled
  char untitled[14];
  LoadString (AfxGetApp()->m_hInstance, IDS_UNTITLED, untitled,
              sizeof(untitled));
  strcat (newtitle, untitled);
 }
 else {
  strcat (newtitle, " - ");
  strcat (newtitle, filename);
 }
 SetWindowText (newtitle);            // install new concatenated title
}
 
/***************************************************************************/
/*                                                                         */
/* CmFileNew: open a new file                                              */
/*                                                                         */
/***************************************************************************/

void      FrameWin::CmFileNew () {

 if (ptreditwin->GetModify()) SaveCheck();   // if not saved, ask user & handle
 filename[0] = 0;                            // set no filename
 sfilename[0] = 0;                           // set no filename
 ptreditwin->SetWindowText (NULL);           // send new text to CEdit window
 ptreditwin->SetModify (FALSE);              // set CEdit not modified yet
 ptreditwin->EmptyUndoBuffer ();             // clear CEdit's undo buffer
 UpdateCaption ();                           // insert untitled into caption
}

/***************************************************************************/
/*                                                                         */
/* CmFileOpen: open an existant file                                       */
/*                                                                         */
/***************************************************************************/

void      FrameWin::CmFileOpen () {

 if (ptreditwin->GetModify()) SaveCheck(); // if changed, ask user & handle

 // create new transfer buffer
 CFileDialog filedlg (TRUE,    // use Open dialog
                      "*.CPP", // default extension
                      "*.*",   // current file name
                      OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST | OFN_LONGNAMES,
                      "All Files (*.*)|*.*|CPP Files (*.CPP)|*.CPP|C Files "
                      "(*.C)|*.C|Header Files (*.H*)|*.H*||",
                      this);

 // get user's file choice
 if (filedlg.DoModal () == IDOK) {           // user has chosen a file, so
  strcpy (filename, filedlg.GetPathName ()); // extract its filename

  // attempt to open the file   
  HANDLE hfile = CreateFile (filename, GENERIC_READ, 0, NULL, OPEN_EXISTING,
                             FILE_ATTRIBUTE_NORMAL, NULL);
  if (hfile == INVALID_HANDLE_VALUE) { // file create failed, so display error
   DisplayMsg (IDS_MSG_ERROR, IDS_MSG_FILEOPEN , MB_OK | MB_ICONSTOP);
   filename[0]  = 0;                    // install untitled
   sfilename[0] = 0;                    // install untitled
   return;
  }
  // get file size
  DWORD filesize = SetFilePointer (hfile, 0L, NULL, FILE_END);
  SetFilePointer (hfile, 0L, NULL, FILE_BEGIN); // reset back to start

  // CEdit can handle upto 64K absolute maximum - so we must check filesize
  // however, I get about 55K max
  if (filesize > 55000L) {
   DisplayMsg (IDS_MSG_ERROR, IDS_MSG_FILEBIG, MB_OK);
   CloseHandle (hfile);
   filename[0]  = 0;                    // install untitled
   sfilename[0] = 0;                    // install untitled
   return;
  }  

  // allocate a file input buffer
  HANDLE hbuffer = GlobalAlloc (GMEM_MOVEABLE, filesize+1); // for null terminator
  if (hbuffer==NULL) {  // error, not enough memory for buffer
   DisplayMsg (IDS_MSG_ERROR, IDS_MSG_NOMEM, MB_OK | MB_ICONSTOP);
   CloseHandle (hfile);
   filename[0]  = 0;                    // install untitled
   sfilename[0] = 0;                    // install untitled
   return;
  }
  char *ptrbuf = (char*) GlobalLock (hbuffer);// get locked ptr to global buffer
  
  DWORD actsz;
  ReadFile (hfile, ptrbuf, filesize, &actsz, NULL); // input whole file
  CloseHandle (hfile);                  // close the file
  
  if (actsz != filesize) {              // input read error
   DisplayMsg (IDS_MSG_ERROR, IDS_MSG_FILEREAD, MB_OK | MB_ICONSTOP);
   filename[0]  = 0;                    // install untitled
   sfilename[0] = 0;                    // install untitled
   GlobalUnlock (hbuffer);              // remove the global memory
   GlobalFree   (hbuffer);
   return;
  }
  
  ptrbuf [filesize] = 0;                // insert null terminator for CEdit
  ptreditwin->SetWindowText (ptrbuf);   // set CEdit to new text
  GlobalUnlock (hbuffer);               // unlock file buffer
  GlobalFree   (hbuffer);               // and free global memory
  ptreditwin->SetModify (FALSE);        // set CEdit to unmodified
  ptreditwin->EmptyUndoBuffer ();       // clear CEdit's undo buffer
  UpdateCaption ();                     // install filename in title bar
 }
}

/***************************************************************************/
/*                                                                         */
/* CmFileSave: save an existant file                                       */
/*                                                                         */
/***************************************************************************/

void      FrameWin::CmFileSave () {

 // if no name, use SaveAs otherwise use SaveFile
 if (filename[0]==0)  SendMessage (WM_COMMAND, CM_FILESAVEAS, 0L);
 else SaveFile();
}

/***************************************************************************/
/*                                                                         */
/* SaveFile: write the file                                                */
/*                                                                         */
/***************************************************************************/

void      FrameWin::SaveFile () {

 // allocate a file buffer based upon current size in the CEdit control
 long filesize = ptreditwin->GetWindowTextLength ();
 HANDLE hbuffer = GlobalAlloc (GMEM_MOVEABLE, filesize);
 if (hbuffer==NULL) {   // error, not enough memory for buffer
  DisplayMsg (IDS_MSG_ERROR, IDS_MSG_NOMEM, MB_OK | MB_ICONSTOP);
  return;
 }
 char *ptrbuf = (char*) GlobalLock (hbuffer);  // get locked ptr to glbl buffer

 // transfer the updated text from CEdit control into global memory
 ptreditwin->GetWindowText (ptrbuf, ptreditwin->GetWindowTextLength ());

 // open the file, replacing any existing file
 HANDLE hfile = CreateFile (filename, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,
                            FILE_ATTRIBUTE_NORMAL, NULL);             
 if (hfile == INVALID_HANDLE_VALUE) { // file create failed, so display error
  DisplayMsg (IDS_MSG_ERROR,IDS_MSG_FILEERR , MB_OK | MB_ICONSTOP);
  GlobalUnlock (hbuffer);             // unlock buffer
  GlobalFree (hbuffer);               // and free the global memory
  return;
 }

 DWORD actsz;
 WriteFile (hfile, ptrbuf, filesize, &actsz, NULL); // write whole file
 CloseHandle (hfile);                            // close file and
 GlobalUnlock (hbuffer);                         // unlock buffer
 GlobalFree   (hbuffer);                         // and remove global memory

 if (actsz != (DWORD) filesize)                  // if write fails, show error
  DisplayMsg (IDS_MSG_ERROR, IDS_MSG_FILEWRT, MB_OK | MB_ICONSTOP);
 else ptreditwin->SetModify (FALSE);             // set CEdit to unmodified
}

/***************************************************************************/
/*                                                                         */
/* CmFileSaveAs: Save an existant file with a new name                     */
/*                                                                         */
/***************************************************************************/

void      FrameWin::CmFileSaveAs () {

 // set up transfer buffer
 CFileDialog filedlg (FALSE,   // use SaveAs dialog
                      "", // default extension
                      "*.*",   // current file name
                      OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_LONGNAMES,
                      "All Files (*.*)|*.*|CPP Files (*.CPP)|*.CPP|C Files"
                      " (*.C)|*.C|Header Files (*.H*)|*.H*||",
                      this);
 strcpy (filedlg.m_ofn.lpstrFile, filename); // install current name

 if (filedlg.DoModal () == IDOK) {           // user has chosen a file, so
  strcpy (filename, filedlg.GetPathName ()); // extract its filename
  SaveFile ();                               // save the file
  UpdateCaption ();                          // install new filename in title
 }
}

/***************************************************************************/
/*                                                                         */
/* CmHelpAbout: shows who wrote this app                                   */
/*                                                                         */
/***************************************************************************/

void      FrameWin::CmHelpAbout () {

 // informational modal dialog - create instance of CDialog and execute it
 CDialog aboutdlg ("IDD_ABOUT", this);
 aboutdlg.DoModal ();
}

/***************************************************************************/
/*                                                                         */
/* CmEnableHaveFile: enabler for all menus that require existant file      */
/*                                                                         */
/***************************************************************************/

void      FrameWin::CmEnableHaveFile (CCmdUI *ptrenabler) {

 ptrenabler->Enable (ptreditwin->GetWindowTextLength () > 0 ? 1 : 0);
}

/***************************************************************************/
/*                                                                         */
/* CmEditUndo: undo last change                                            */
/*                                                                         */
/***************************************************************************/

void      FrameWin::CmEditUndo () {

 if (ptreditwin->CanUndo ()) ptreditwin->Undo ();
}

/***************************************************************************/
/*                                                                         */
/* CmEditCut: copy current selection to clipboard                          */
/*                                                                         */
/***************************************************************************/

void      FrameWin::CmEditCut () {

 ptreditwin->Cut ();
}

/***************************************************************************/
/*                                                                         */
/* CmEditCopy: copy current selection to the clipboard                     */
/*                                                                         */
/***************************************************************************/

void      FrameWin::CmEditCopy () {

 ptreditwin->Copy ();
}

/***************************************************************************/
/*                                                                         */
/* CmEditPaste: paste from the clipboard                                   */
/*                                                                         */
/***************************************************************************/

void      FrameWin::CmEditPaste () {

 ptreditwin->Paste ();
}

/***************************************************************************/
/*                                                                         */
/* CmEditClear: clear text                                                 */
/*                                                                         */
/***************************************************************************/

void      FrameWin::CmEditClear () {

 ptreditwin->Clear ();
}
