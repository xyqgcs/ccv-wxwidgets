/////////////////////////////////////////////////////////////////////////////
// Name:        src/main.cpp
// Purpose:     Provide the entrance of the application
// Author:      Jimbo Zhang
// Copyright:   (c) 2011 NUI Group
/////////////////////////////////////////////////////////////////////////////
 
#include <wx/wx.h>
#include "CCVMainFrame.h"
#include "CCVMiniFrame.h"

//
// CCVApp is the class that provides the main application.
//
class CCVApp : public wxApp
{
    virtual bool OnInit();
    int FilterEvent(wxEvent& event);
    
private:
    bool use_Mainframe;
    CCVMainFrame *mainframe;
    CCVMiniFrame *miniframe;
};

IMPLEMENT_APP(CCVApp)

/**
    The entrance of the application. Set mainframe and miniframe.
*/
bool CCVApp::OnInit()
{
    mainframe = new CCVMainFrame();
    if (mainframe==NULL)
        return false;
        
    miniframe = new CCVMiniFrame(mainframe);
    if (miniframe==NULL)
        return false;
        
    use_Mainframe = true;
    mainframe->Show(use_Mainframe);
    miniframe->Show(!use_Mainframe);
    
    return true;
}

/**
    Switch between mainframe and miniframe when the spacebar was pressed.
*/
int CCVApp::FilterEvent(wxEvent& event)
{
    if ( event.GetEventType()==wxEVT_KEY_DOWN && ((wxKeyEvent&)event).GetKeyCode()==WXK_SPACE)
    {
        use_Mainframe = !use_Mainframe;
        mainframe->Show(use_Mainframe);
        miniframe->Show(!use_Mainframe);
        return 0;
    }
 
    return -1;
}