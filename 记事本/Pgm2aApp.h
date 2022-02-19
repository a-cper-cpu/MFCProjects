#ifndef PGM2AAPP
#define PGM2AAPP

/***************************************************************************/
/*                                                                         */
/* Pgm02AApp: Class Definition - Illustrates CEdit and Choose Fonts        */
/*                                                                         */
/***************************************************************************/

class Pgm02AApp : public CWinApp {

 /***************************************************************************/
 /*                                                                         */
 /* Class Functions:                                                        */
 /*                                                                         */
 /***************************************************************************/

public:

      Pgm02AApp () : CWinApp () {}       // constructor - no actions required
BOOL  InitInstance ();                   // constructs instances of frame wnd
};
#endif
