#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/fl_draw.H>

#include "./request.cpp"

Fl_Input* input;
Fl_Box* initialText;

int width = 800;
int height = 600;
int wButton = 78;
int hButton = 42;

void renderHtml(std::vector<std::vector<std::string>> htmlToRender){
    Fl_Window* windowRef = Fl::first_window();

    int top = hButton + 24;

    for(int y = 0; y < htmlToRender.size(); y++){
        if(htmlToRender[y][0] == "h1"){
            const char *txt = htmlToRender[y][1].c_str();
            int localW, localH;
            
            fl_font(FL_HELVETICA_BOLD, 24);
            fl_measure(txt, localW, localH);

            Fl_Box* box = new Fl_Box(12, top, localW, localH, txt);
            box->labelsize(24);
            box->labelfont(FL_HELVETICA_BOLD);
            box->labelcolor(FL_BLACK);

            windowRef->add(box);

            top = top + 12 + localH;
        }

        if(htmlToRender[y][0] == "p"){
            const char *txt = htmlToRender[y][1].c_str();
            int localW, localH;

            fl_font(FL_HELVETICA, 16);
            fl_measure(txt, localW, localH);

            Fl_Box* box = new Fl_Box(12, top, localW, localH, txt);
            box->labelsize(16);
            box->labelfont(FL_HELVETICA);
            box->labelcolor(FL_BLACK);

            windowRef->add(box);

            top = top + 12 + localH;
        }
    }

    windowRef->redraw();
}

void buttonCallback(Fl_Widget* w, void*){
    const char* value = input->value();
    
    if(initialText != nullptr){
        initialText->parent()->remove(initialText);
        delete initialText;
        initialText = nullptr;
    }

    std::vector<std::vector<std::string>> htmlToRender = request(value);
    renderHtml(htmlToRender);
}

int main(){
    Fl_Window* window = new Fl_Window(width, height, "Navegador");

    input = new Fl_Input(12, 12, width - 38 - wButton, hButton, "");

    Fl_Button* button = new Fl_Button(width - 12 - wButton, 12, wButton, hButton, "Pesquisar");
    button->callback(buttonCallback);

    initialText = new Fl_Box(width/2 - 360/2, height/2 - 40/2, 360, 40, "Olá, digite uma URL para começar!");
    initialText->labelsize(16);
    initialText->labelfont(FL_HELVETICA_BOLD);
    initialText->labelcolor(FL_BLACK);

    window->color(FL_WHITE);
    int centerX = (Fl::w() - width) / 2;
    int centerY = (Fl::h() - height) / 2;
    window->position(centerX, centerY);

    window->end();
    window->show();

    return Fl::run();
}