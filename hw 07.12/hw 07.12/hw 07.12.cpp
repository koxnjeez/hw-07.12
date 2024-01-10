#include "settings.h"

class comp_mouse;
class mousepad;
class machete;

class comp_mouse {
private:
    string type;
    string color;
    string maker;
    string model;
    bool RGB;
    bool additional_buttons;

public:
    void SetType(string t) {
        type = t;
    }
    string GetType() {
        return type;
    }
    void SetColor(string c) {
        color = c;
    }
    string GetColor() {
        return color;
    }
    void SetMaker(string m) {
        maker = m;
    }
    string GetMaker() {
        return maker;
    }
    void SetModel(string m) {
        model = m;
    }
    string GetModel() {
        return model;
    }
    void SetRGB(bool r) {
        RGB = r;
    }
    bool GetRGB() {
        return RGB;
    }
    void SetAdditionalButtons(bool a) {
        additional_buttons = a;
    }
    bool GetAdditionalButtons() {
        return additional_buttons;
    }
    void scroll() {
        cout << "mouse wheel is scrolling\n";
    }
    void RGB_on() {
        cout << "backlight on\n";
    }
    void RGB_off() {
        cout << "backlight off\n";
    }
    void slide() {
        cout << "mouse is sliding\n";
    }
    void not_slide() {
        cout << "mouse isn't sliding\n";
    }
    void pc_connected() {
        cout << "the mouse is connected to the computer\n";
    }
    void pc_unconnected() {
        cout << "the mouse isn't connected to the computer\n";
    }
};

class mousepad {
private:
    string type;
    string color;
    bool pattern;
    bool is_whole;
    bool is_wet;
    bool is_ontable;

public:
    void SetType(string t) {
        type = t;
    }
    string GetType() {
        return type;
    }
    void SetColor(string c) {
        color = c;
    }
    string GetColor() {
        return color;
    }
    void SetPattern(bool p) {
        pattern = p;
    }
    bool GetPattern() {
        return pattern;
    }
    void SetIsWhole(bool w) {
        is_whole = w;
    }
    bool GetIsWhole() {
        return is_whole;
    }
    void SetIsWet(bool w) {
        is_wet = w;
    }
    bool GetIsWet() {
        return is_wet;
    }
    void SetIsOnTable(bool t) {
        is_ontable = t;
    }
    bool GetIsOnTable() {
        return is_ontable;
    }
    void on_table() {
        if (is_ontable) {
            cout << "the mouse pad is on the table\n";
        }
        else {
            cout << "the mouse pad isn't on the table\n";
        }
    }
    void in_wash() {
        cout << "the mouse pad in the wash\n";
    }
    void whole() {
        cout << "the mouse pad is whole\n";
    }
    void torn() {
        cout << "the mouse pad is torn\n";
    }
    void actual_condition() {
        if (is_whole == false) {
            cout << "the mouse pad has reached the end of its useful life, it's time to buy a new one\n";
        }
        else {
            cout << "the mouse pad is still useful\n";
        }
    }
};

class machete {
private:
    string type;
    string handle_color;
    string blade_color;
    bool machete_teeth;
    bool is_sharpened;
    bool is_clean;

public:
    void SetType(string t) {
        type = t;
    }
    string GetType() {
        return type;
    }
    void SetHandleColor(string c) {
        handle_color = c;
    }
    string GetHandleColor() {
        return handle_color;
    }
    void SetBladeColor(string c) {
        blade_color = c;
    }
    string GetBladeColor() {
        return blade_color;
    }
    void SetMacheteTeeth(bool t) {
        machete_teeth = t;
    }
    bool GetMacheteTeeth() {
        return machete_teeth;
    }
    void SetIsSharpened(bool s) {
        is_sharpened = s;
    }
    bool GetIsSharpened() {
        return is_sharpened;
    }
    void SetIsClean(bool c) {
        is_clean = c;
    }
    bool GetIsClean() {
        return is_clean;
    }
    void chop(mousepad& k) {
        cout << "machete chops the " << k.GetType() << "\n";
        k.SetIsWhole(false);
    }
    void cut(comp_mouse m) {
        cout << "machete cuts the " << m.GetType() << "\n";
    }
    void blunt() {
        cout << "the blade is blunt\n";
    }
    void sharpened() {
        cout << "the blade is sharpened\n";
    }
    void stuck() {
        cout << "the machete is stuck\n";
    }
};

int main()
{
    comp_mouse m;
    m.SetType("mouse");
    m.SetAdditionalButtons(true);
    m.SetColor("black");
    m.SetMaker("Razer");
    m.SetModel("Bacilisk V2");
    m.SetRGB(true);

    machete r;
    r.SetType("machete");
    r.SetBladeColor("gold");
    r.SetHandleColor("black");
    r.SetIsClean(true);
    r.SetIsSharpened(true);
    r.SetMacheteTeeth(false);

    mousepad k;
    k.SetType("mouse pad");
    k.SetColor("black");
    k.SetIsOnTable(true);
    k.SetIsWet(false);
    k.SetIsWhole(true);
    k.SetPattern(true);

    k.actual_condition();
    r.chop(k);
    k.actual_condition();
    r.cut(m);
    m.pc_unconnected();
    Sleep(INFINITE);
}