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
    void SetType(string type) {
        this->type = type;
    }
    string GetType() const {
        return type;
    }
    void SetColor(string color) {
        this->color = color;
    }
    string GetColor() const {
        return color;
    }
    void SetMaker(string maker) {
        this->maker = maker;
    }
    string GetMaker() const {
        return maker;
    }
    void SetModel(string model) {
        this->model = model;
    }
    string GetModel() const {
        return model;
    }
    void SetRGB(bool rgb) {
        RGB = rgb;
    }
    bool GetRGB() const {
        return RGB;
    }
    void SetAdditionalButtons(bool addit_buttons) {
        additional_buttons = addit_buttons;
    }
    bool GetAdditionalButtons() const {
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
    void SetType(string type) {
        this->type = type;
    }
    string GetType() const {
        return type;
    }
    void SetColor(string color) {
        this->color = color;
    }
    string GetColor() const {
        return color;
    }
    void SetPattern(bool pattern) {
        this->pattern = pattern;
    }
    bool GetPattern() const {
        return pattern;
    }
    void SetIsWhole(bool is_whole) {
        this->is_whole = is_whole;
    }
    bool GetIsWhole() const {
        return is_whole;
    }
    void SetIsWet(bool is_wet) {
        this->is_wet = is_wet;
    }
    bool GetIsWet() const {
        return is_wet;
    }
    void SetIsOnTable(bool on_the_table) {
        is_ontable = on_the_table;
    }
    bool GetIsOnTable() const {
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
    unsigned short* blows_count = new unsigned short[100];

public:
    ~machete() {
        if (blows_count != nullptr)
            delete[] blows_count;
    }

    machete(string type, string handle_color, string blade_color, bool machete_teeth, bool is_sharpened, bool is_clean, unsigned short blows_count) {
        SetType(type);
        SetHandleColor(handle_color);
        SetBladeColor(blade_color);
        SetMacheteTeeth(machete_teeth);
        SetIsSharpened(is_sharpened);
        SetIsClean(is_clean);
        SetBlowCounter(blows_count);
    }
    machete() : machete("huge", "black", "silver", false, true, true, 0) {}

    void SetType(string type) {
        this->type = type;
    }
    string GetType() const {
        return type;
    }
    void SetHandleColor(string handle_color) {
        this->handle_color = handle_color;
    }
    string GetHandleColor() const {
        return handle_color;
    }
    void SetBladeColor(string blade_color) {
        this->blade_color = blade_color;
    }
    string GetBladeColor() const {
        return blade_color;
    }
    void SetMacheteTeeth(bool machete_teeth) {
        this->machete_teeth = machete_teeth;
    }
    bool GetMacheteTeeth() const {
        return machete_teeth;
    }
    void SetIsSharpened(bool is_sharpened) {
        this->is_sharpened = is_sharpened;
    }
    bool GetIsSharpened() const {
        return is_sharpened;
    }
    void SetIsClean(bool is_clean) {
        this->is_clean = is_clean;
    }
    bool GetIsClean() const {
        return is_clean;
    }
    void SetBlowCounter(unsigned int count) {
        *blows_count = count;
    }
    unsigned short GetBlowCounter() const {
        return *blows_count;
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
    void state_check(unsigned int count_times) {
        cout << "this machete was using " << count_times << " times after sharpening\n";
    }
};

int main()
{
    comp_mouse m;
    m.SetType("mouse");
    m.SetAdditionalButtons(true);
    m.SetColor("black");
    m.SetMaker("Razer");
    m.SetModel("Basilisk V2");
    m.SetRGB(true);

    machete r;
    r.SetType("machete");
    r.SetBladeColor("gold");
    r.SetHandleColor("black");
    r.SetIsClean(true);
    r.SetIsSharpened(true);
    r.SetMacheteTeeth(false);
    r.SetBlowCounter(34);

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
    r.state_check(17);
}
