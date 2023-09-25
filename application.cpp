#include <wx/wx.h>

class MyFrame : public wxFrame {
public:
    MyFrame() : wxFrame(NULL, wxID_ANY, "SerialApp", wxDefaultPosition, wxSize(400, 300)) {
        wxPanel *panel = new wxPanel(this, wxID_ANY);

        wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
        wxButton *connectButton = new wxButton(panel, wxID_ANY, "Connecter", wxDefaultPosition, wxSize(150, 50));
        vbox->Add(connectButton, 0, wxALL, 10);

        wxTextCtrl *commandEntry = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(350, 30));
        vbox->Add(commandEntry, 0, wxALL, 10);

        wxButton *sendButton = new wxButton(panel, wxID_ANY, "Envoyer", wxDefaultPosition, wxSize(150, 50));
        vbox->Add(sendButton, 0, wxALL, 10);

        wxTextCtrl *responseText = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxSize(350, 150), wxTE_MULTILINE);
        vbox->Add(responseText, 0, wxALL, 10);

        wxButton *disconnectButton = new wxButton(panel, wxID_ANY, "Déconnecter", wxDefaultPosition, wxSize(150, 50));
        vbox->Add(disconnectButton, 0, wxALL, 10);

        panel->SetSizerAndFit(vbox);
    }
};

class MyApp : public wxApp {
public:
    virtual bool OnInit() {
        MyFrame *frame = new MyFrame();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);