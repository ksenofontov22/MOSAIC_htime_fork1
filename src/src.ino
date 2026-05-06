#include "ex.h"
#include "user_xbm.h"
#include "rxtx.h"
#include "vector"
#include "map"
#include "algorithm"

GGL ggl;

void form_test()
{
    exForm *form_test = new exForm();

    eTextBox *textbox1 = new eTextBox("I've missed more than 9000 shots in my career. I've lost almost 300 games. 26 times, I've been trusted to take the game winning shot and missed. I've failed over and over and over again in my life. And that is why I succeed.",
                                      BorderStyle::noBorder, 210, 100, 0, 0);

    form_test->title = "Form Test. Output text";
    form_test->eFormShowMode = NORMAL;
    form_test->addElement(textbox1);

    formsStack.push(form_test);
}

std::vector<int> compress(const std::vector<int>& data, int min_out, int max_out) {
    if (data.empty()) return {};
    
    int min_in = *std::min_element(data.begin(), data.end());
    int max_in = *std::max_element(data.begin(), data.end());
    
    if (min_in == max_in) {
        return std::vector<int>(data.size(), (min_out + max_out) / 2);
    }
    
    std::vector<int> result(data.size());
    for (size_t i = 0; i < data.size(); i++) {
        result[i] = min_out + (data[i] - min_in) * (max_out - min_out) / (max_in - min_in);
    }
    return result;
}

int dr_func(int x)
{
    return x*x;
}

void create_func_map(int xG, int yG, int wG, int hG)
{
    int y;
    std::vector<int> xs(100), ys(100), xsc, ysc;
    //std::vector<std::pair<int, int>> dots(101);

    for (int i = -50; i <= 50; i++)
    {
        xs[i+50] = i;
        ys[i+50] = abs(dr_func(i));
    }

    xsc = compress(xs, 200, 250);
    ysc = compress(ys, 10, 140);

    for (int i = 0; i < xsc.size(); i++)
    {
        ggl.gray.drawPixel(xsc[i], ysc[i], ggl.gray.BLACK);
    }
}

void formFuncDraw()
{
    exForm *form_func_draw = new exForm();
    eGraphics *graphics_func_draw = new eGraphics(create_func_map, 0, 0, 256, 147);

    form_func_draw->title = "Graphs";
    form_func_draw->eFormShowMode = FULLSCREEN;
    form_func_draw->addElement(graphics_func_draw);

    formsStack.push(form_func_draw);
}

void setup()
{  
    initializationSystem();
    _TD.addTask({"funcdraw", &formFuncDraw, _ICON.window_graphics, DESKTOP, 0, false});
}

void loop()
{  
    _TD.terminal();
}