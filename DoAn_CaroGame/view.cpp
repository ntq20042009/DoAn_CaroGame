﻿#include"Function_C.h"
#include "view.h"
void FullScreen() {
    ::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}
void setColor(int m) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m);
}
void FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}
void GotoXY(int x, int y) { //tọa độ
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
void DrawBoard() { //vẽ bảng
    setColor(3);
    for (int i = 2; i <= 44; i++) //vẽ ô bên trong
    {
        
        for (int j = 0; j <= 24; j++)
        {
            if (i < 4) printf(" ");
            else if (j < 3) printf(" ");
            else if (i % 2 == 0 && j > 4 && j < 23)  printf("%c%c%c%c", 197, 196, 196, 196);
            else if (i % 2 == 1 && j > 4 && j < 23) printf("%c   ", 179);
            else if (i % 2 == 0 && j == 23) printf("%c", 197);
            else if (i % 2 == 1 && j == 23) printf("%c", 179);
        }
        printf("\n");
    }
    for (int i = 2; i < 43; i++) {  //39->54 vẽ khung bên ngoài
        GotoXY(3, i); printf("%c", 186);
    }
    for (int i = 2; i < 43; i++) {
        GotoXY(75, i); printf("%c", 186);
    }
    for (int i = 3; i < 76; i++) {
        GotoXY(i, 2); printf("%c", 205);
    }
    for (int i = 3; i < 76; i++) {
        GotoXY(i, 42); printf("%c", 205);
    }
    GotoXY(3, 2); printf("%c", 201);
    GotoXY(3, 42); printf("%c", 200);
    GotoXY(75, 2); printf("%c", 187);
    GotoXY(75, 42); printf("%c", 188);
    //nối liền nét đứt giữa ô trong và viền ngoài
    {
        int x = 7;
        for (int i = 7; i < 76; i++)
            if (i % x == 0 && i != 3 && i != 75) {
                GotoXY(i, 2);
                printf("%c", 209);
                x += 4;
            }
        x = 7;
        for (int i = 7; i < 76; i++)
            if (i % x == 0 && i != 3 && i != 75) {
                GotoXY(i, 42);
                printf("%c", 207);
                x += 4;
            }
        for (int i = 4; i < 43; i++)
            if (i % 2 == 0 && i != 42) {
                GotoXY(3, i);
                printf("%c", 199);
            }
        for (int i = 4; i < 43; i++)
            if (i % 2 == 0 && i != 42) {
                GotoXY(75, i);
                printf("%c", 182);
            }
    }
}