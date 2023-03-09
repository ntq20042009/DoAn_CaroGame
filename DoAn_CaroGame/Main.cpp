
#include"Function_C.h" //hàm cơ bản của c++ trong đây
#include"view.h"
#include"Control.h"

void main() {
    FixConsoleWindow();
    bool validEnter = true;
    while (1) {
        ResetData();
        DrawBoard();
        test();
    }

}