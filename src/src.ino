#include "ex.h"
#include "rxtx.h"
#include "ggl.h"
#include <vector>

#define elif else if

Graphics gfx;
TaskDispatcher dispatcher; Icon icons;
GRAY gray;
Timer tim;
Joystick moveset;

std::vector<std::vector<short>> a(10, std::vector<short>(18, 0));

void draw_level(int xG, int yG, int wG, int hG)
{
    gray.drawTriangle(60, 52, 70, 70, 50, 90, gray.BLACK, gray.LIGHT_GRAY);
}

void SokoForm()
{
    exForm *form_sokoban = new exForm;
    eGraphics *SokoGraphics = new eGraphics(draw_level, 0, 0, 256, 147);

    form_sokoban->title = "PushBox";
    form_sokoban->eFormShowMode = MAXIMIZED;
    form_sokoban->addElement(SokoGraphics); 

    formsStack.push(form_sokoban);
}

void setup()
{  
    initializationSystem();
    dispatcher.addTask({"Triangle", SokoForm, icons.processor, DESKTOP, 0, false});
}

void loop()
{  
    dispatcher.terminal();
}

/*short int points_num;
vector<pair<int, int> points;

void calc_parabola()
{
    
}

void draw_parabola()
{

}*/



/*void ParabolaForm()
{
    exForm *form_parabola = new exForm;
    eGraphics *ParabolaGraphics = new eGraphics(random_triangle, 0, 0, 256, 147);

    form_parabola->title = "Some Triangle";
    form_parabola->eFormShowMode = MAXIMIZED;
    form_parabola->addElement(TriangleGraphics); 

    formsStack.push(form_parabola);
}

void setup()
{  
    gfx.initializationSystem();
    dispatcher.addTask({"Parabola", ParabolaForm, icons.processor, DESKTOP, 0, false});
}

void loop()
{  
    dispatcher.terminal3();
}*/

/*short x01 = 128, x02 = 64, x03 = 192;
short y01 = 30, y02 = 100, y03 = 100;
short radius = 10;

short x1Tri = x01 + random(-1*radius, radius), y1Tri = y01 + random(-1*radius, radius);
short x2Tri = x02 + random(-1*radius, radius), y2Tri = y02 + random(-1*radius, radius);
short x3Tri = x03 + random(-1*radius, radius), y3Tri = y03 + random(-1*radius, radius);

void genPoints1()
{
    x1Tri = x01 + random(-1*radius, radius); y1Tri = y01 + random(-1*radius, radius);
}

void genPoints2()
{
    x2Tri = x02 + random(-1*radius, radius); y2Tri = y02 + random(-1*radius, radius);
}

void genPoints3()
{
    x3Tri = x03 + random(-1*radius, radius); y3Tri = y03 + random(-1*radius, radius);
}

void gen3RandPoints()
{
    x1Tri = x01 + random(-1*radius, radius); y1Tri = y01 + random(-1*radius, radius);
    x2Tri = x02 + random(-1*radius, radius); y2Tri = y02 + random(-1*radius, radius);
    x3Tri = x03 + random(-1*radius, radius); y3Tri = y03 + random(-1*radius, radius);
}

Timer timer1, timer2, timer3;
void random_triangle(int xG, int yG, int wG, int hG)
{
    //timer_0.timer(gen3RandPoints, 3000);
    std::vector<std::function<void()>> fs = {genPoints1, genPoints2, genPoints3};
    std::vector<int> intervals = {1000, 1000, 1000};
    //timer1.timer(fs, intervals);

    Serial.print(x1Tri);
    Serial.print(' ');
    Serial.print(y1Tri);
    Serial.println();
    Serial.print(x2Tri);
    Serial.print(' ');
    Serial.print(y2Tri);
    Serial.println();
    Serial.print(x3Tri);
    Serial.print(' ');
    Serial.print(y3Tri);
    Serial.print("\n\n\n");
    
    gray.drawLine(x1Tri, y1Tri, x2Tri, y2Tri, gray.BLACK);
    gray.drawLine(x2Tri, y2Tri, x3Tri, y3Tri, gray.BLACK);
    gray.drawLine(x3Tri, y3Tri, x1Tri, y1Tri, gray.BLACK);
}

void TriangleForm()
{
    exForm *form_triangle = new exForm;
    eGraphics *TriangleGraphics = new eGraphics(random_triangle, 0, 0, 256, 147);

    form_triangle->title = "Some Triangle";
    form_triangle->eFormShowMode = MAXIMIZED;
    form_triangle->addElement(TriangleGraphics); 

    formsStack.push(form_triangle);
}

void setup()
{  
    gfx.initializationSystem();
    dispatcher.addTask({"TriangleForm", TriangleForm, icons.processor, DESKTOP, 0, false});
    //dispatcher.addTask({"airplane", airplane, icons.processor, DESKTOP, 0, false});
}

void loop()
{  
    dispatcher.terminal3();
}*/

/*struct Air
{
    short time_0, time_1;
    bool state_air;
    char name_air[20];
};

Air air_tx, air_rx;
short t_0, t_1;

void airplane()
{
    exForm *form_airplane = new exForm();

    eButton *btn0 = new eButton("-", [](){}, 5, 5);
    eButton *btn1 = new eButton("+", [](){}, 41, 5);

    eButton *btn2 = new eButton("-", [](){}, 5, 23);
    eButton *btn3 = new eButton("+", [](){}, 41, 23);
    
    eButton *btn4 = new eButton("RUN", [](){}, 5, 41);

    eLabel *label0 = new eLabel("000", 21, 7);
    eLabel *label1 = new eLabel("111", 21, 25);
    //eLabel *label2 = new eLabel();
    //eLabel *label3 = new eLabel();

    eTextBox *txtBox0 = new eTextBox("Test", BorderStyle::noBorder, 80, 50, 26, 39);

    form_airplane->addElement(btn0); form_airplane->addElement(btn1); form_airplane->addElement(btn2);
    form_airplane->addElement(btn3); form_airplane->addElement(btn4);
    form_airplane->addElement(label0); form_airplane->addElement(label1);
    form_airplane->addElement(txtBox0);

    form_airplane->eFormShowMode = NORMAL;
    form_airplane->title = "Airplane v.1";
    
    formsStack.push(form_airplane);
}

struct RxTxData
{
    short a; short b;
};

RxTxData rtd;

void readDataPort()
{
    exForm *form0 = new exForm();
    form0->eFormShowMode = NORMAL;
    form0->title = "Read Data port";

    eFunction *func0 = new eFunction([](){
        DATARX r;
        if (r.receive(rtd, 0))
        {
            String text = "Done!\n" + (String)rtd.a + "\n" + (String)rtd.b;
            InstantMessage mess0(text, 2000); mess0.show();
        }
    });

    form0->addElement(func0);

    formsStack.push(form0);
}

void setup()
{  
    gfx.initializationSystem();
    dispatcher.addTask({"airplane", airplane, icons.processor, DESKTOP, 0, false});
    dispatcher.addTask({"Read dataPort", readDataPort, icons.processor, DESKTOP, 0, false});
}

void loop()
{  
    dispatcher.terminal3();
}*/

