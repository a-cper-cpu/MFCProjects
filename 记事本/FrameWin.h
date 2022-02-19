#ifndef FRAMEWIN
#define FRAMEWIN

/***************************************************************************/
/*                                                                         */
/* FrameWin Class Definition                                               */
/*                                                                         */
/***************************************************************************/

class FrameWin : public CFrameWnd {

 /***************************************************************************/
 /*                                                                         */
 /* Class Data Members                                                      */
 /*                                                                         */
 /***************************************************************************/

protected:

CEdit*    ptreditwin;       // pointer to our CEdit main window

char      filename[MAX_PATH]; // full path file spec
char      sfilename[14];      // filename.extension

LOGFONT*   ptrlogfont;      // user selected font for printing
COLORREF   fontcolor;       // the font's color for display
HFONT      hfont;           // font for the CEdit window

 /***************************************************************************/
 /*                                                                         */
 /* Class Functions:                                                        */
 /*                                                                         */
 /***************************************************************************/

public:
              FrameWin (CWnd*, const char*); // constructor

protected:

afx_msg int   OnCreate (LPCREATESTRUCT);     // construct window, avg char dims
afx_msg void  OnPaint ();                    // paint the window - WM_PAINT
afx_msg void  OnClose ();                    // determines if app can quit yet
afx_msg void  OnSize (UINT, int, int);       // process window resize
afx_msg void  OnDestroy ();                  // remove allocated menus
afx_msg void  OnRButtonDown (UINT, CPoint);  // popup edit menu

// utility functions
void          SaveCheck ();                  // query user about saving file
void          SaveFile ();                   // save the file
void          UpdateCaption ();              // put filename into title bar
int           DisplayMsg (int, int, UINT);   // displays a message box

// command processors
afx_msg void  CmExit ();
afx_msg void  CmFontChange ();               // get new font
afx_msg void  CmFileNew ();                  // start a new file
afx_msg void  CmFileOpen ();                 // open existing file
afx_msg void  CmFileSave ();                 // save the file with same name
afx_msg void  CmFileSaveAs ();               // save with new name
afx_msg void  CmEditUndo ();                 // undo last change
afx_msg void  CmEditCut ();                  // cut to clipboard
afx_msg void  CmEditCopy ();                 // copy to clipboard
afx_msg void  CmEditPaste ();                // paste from the clipboard
afx_msg void  CmEditClear ();                // clear text
afx_msg void  CmHelpAbout ();                // help about our app
afx_msg void  CmEnableHaveFile (CCmdUI*);    // common menu enabler

DECLARE_MESSAGE_MAP()
};
#endif
