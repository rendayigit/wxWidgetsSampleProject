#include <wx/wx.h>

class MyApp : public wxApp {
public:
  bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp); // NOLINT(cppcoreguidelines-pro-type-static-cast-downcast)

class MyFrame : public wxFrame {
public:
  MyFrame();

private:
  void onHello(wxCommandEvent &event);
  void onExit(wxCommandEvent &event);
  void onAbout(wxCommandEvent &event);
};

enum { ID_HELLO = 1 };

bool MyApp::OnInit()
{
    auto *frame = new MyFrame();
    frame->Show(true);
    return true;
}

MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Hello World")
{
    auto *menuFile = new wxMenu;
    menuFile->Append(ID_HELLO, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
 
    auto *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
 
    auto *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
 
    SetMenuBar( menuBar );
 
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
 
    Bind(wxEVT_MENU, &MyFrame::onHello, this, ID_HELLO);
    Bind(wxEVT_MENU, &MyFrame::onAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MyFrame::onExit, this, wxID_EXIT);
}

void MyFrame::onExit(wxCommandEvent & /*event*/) { Close(true); }

void MyFrame::onAbout(wxCommandEvent & /*event*/) {
  wxMessageBox("This is a wxWidgets Hello World example", "About Hello World", wxOK | wxICON_INFORMATION);
}

void MyFrame::onHello(wxCommandEvent & /*event*/) { wxLogMessage("Hello world from wxWidgets!"); }
