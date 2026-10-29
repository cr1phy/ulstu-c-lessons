#include <Windows.h>
#include "L93.h"

void StClausAuto(HDC hdc, int x, int y) {
    MoveToEx(hdc, 20 + x, 0 + y, NULL);
    LineTo(hdc, 30 + x, 20 + y);
    LineTo(hdc, 10 + x, 20 + y);
    LineTo(hdc, 20 + x, 0 + y);

    MoveToEx(hdc, 20 + x, 10 + y, NULL);
    LineTo(hdc, 30 + x, 40 + y);
    LineTo(hdc, 10 + x, 40 + y);
    LineTo(hdc, 20 + x, 10 + y);

    MoveToEx(hdc, 20 + x, 30 + y, NULL);
    LineTo(hdc, 40 + x, 80 + y);
    LineTo(hdc, 0 + x, 80 + y);
    LineTo(hdc, 20 + x, 30 + y);
}

void drawStClaus_1_1(HDC hdc) {
    StClausAuto(hdc, 0, 0);
    StClausAuto(hdc, 200, 200);
    StClausAuto(hdc, 100, 100);
    StClausAuto(hdc, 0, 200);
    StClausAuto(hdc, 200, 0);
}

void drawStClaus_1_2(HDC hdc) {
    int x = 0;
    do {
        StClausAuto(hdc, x, 0);
        x += 50;
    } while (x < 400);
}

void drawStClaus_1_3(HDC hdc) {
    int y = 0;
    do {
        StClausAuto(hdc, 0, y);
        y += 90;
    } while (y <= 300);
}

void drawStClaus_1_4(HDC hdc) {
    int y = 0, x = 0;
    do {
        StClausAuto(hdc, x, y);
        y += 90;
        x += 50;
    } while (y <= 300);
}

void drawTruck(HDC hdc, int x, int y) {
    HPEN bodyPen = CreatePen(PS_SOLID, 3, RGB(0, 0, 200));
    HPEN wheelPen = CreatePen(PS_SOLID, 3, RGB(100, 0, 0));
    if (!bodyPen || !wheelPen) {
        if (bodyPen) DeleteObject(bodyPen);
        if (wheelPen) DeleteObject(wheelPen);
        return;
    }

    HPEN oldPen = (HPEN)SelectObject(hdc, bodyPen);
    Rectangle(hdc, 0 + x, 30 + y, 40 + x, 50 + y);
    Rectangle(hdc, 10 + x, 10 + y, 40 + x, 30 + y);
    Rectangle(hdc, 40 + x, 0 + y, 100 + x, 50 + y);

    SelectObject(hdc, wheelPen);
    Ellipse(hdc, 10 + x, 40 + y, 30 + x, 60 + y);
    Ellipse(hdc, 70 + x, 40 + y, 90 + x, 60 + y);

    SelectObject(hdc, oldPen);
    DeleteObject(bodyPen);
    DeleteObject(wheelPen);
}

void drawTrucks1(HDC hdc) {
    drawTruck(hdc, 10, 10);
    drawTruck(hdc, 10, 310);
    drawTruck(hdc, 310, 10);
    drawTruck(hdc, 310, 310);
    drawTruck(hdc, 160, 160);
}

void drawTrucks2(HDC hdc) {
    int x = 0;
    do {
        drawTruck(hdc, x, 0);
        x += 110;
    } while (x <= 650);
}

void drawTrucks3(HDC hdc) {
    int y = 0;
    do {
        drawTruck(hdc, 0, y);
        y += 70;
    } while (y < 420);
}

void drawTrucks4(HDC hdc) {
    int x = 0, y = 0;
    do {
        drawTruck(hdc, x, y);
        x += 110;
        y += 70;
    } while (y < 420);
}

void SnowWoman(HDC hdc, int x, int y) {
    HPEN hPen = CreatePen(PS_SOLID, 3, RGB(0, 200, 0));
    HPEN oldPen = (HPEN)SelectObject(hdc, hPen);

    Ellipse(hdc, 20 + x, 0 + y, 40 + x, 20 + y);
    Ellipse(hdc, 10 + x, 20 + y, 50 + x, 60 + y);
    Ellipse(hdc, 0 + x, 60 + y, 60 + x, 120 + y);

    MoveToEx(hdc, 0 + x, 40 + y, NULL);
    LineTo(hdc, 15 + x, 30 + y);

    MoveToEx(hdc, 60 + x, 40 + y, NULL);
    LineTo(hdc, 45 + x, 30 + y);

    MoveToEx(hdc, 40 + x, 120 + y, NULL);
    LineTo(hdc, 70 + x, 0 + y);

    MoveToEx(hdc, 65 + x, 20 + y, NULL);
    LineTo(hdc, 62 + x, 0 + y);

    MoveToEx(hdc, 65 + x, 20 + y, NULL);
    LineTo(hdc, 75 + x, 0 + y);

    SelectObject(hdc, oldPen);
    DeleteObject(hPen);
}

void drawSnowWomen1(HDC hdc) {
    SnowWoman(hdc, 10, 10);
    SnowWoman(hdc, 310, 10);
    SnowWoman(hdc, 160, 160);
    SnowWoman(hdc, 10, 310);
    SnowWoman(hdc, 310, 310);
}

void drawSnowWomen2(HDC hdc) {
    int x = 0;
    do {
        SnowWoman(hdc, x, 10);
        x += 110;
    } while (x <= 550);
}

void drawSnowWomen3(HDC hdc) {
    int y = 0;
    do {
        SnowWoman(hdc, 0, y);
        y += 130;
    } while (y <= 390);
}

void drawSnowWomen4(HDC hdc) {
    int x = 0, y = 0;
    do {
        SnowWoman(hdc, x, y);
        x += 110;
        y += 130;
    } while (y <= 390);
}

void Logo(HDC hdc, int x, int y) {
    HPEN pen = CreatePen(PS_SOLID, 4, RGB(160, 160, 160));
    if (!pen) return;

    HPEN oldPen = (HPEN)SelectObject(hdc, pen);
    HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, GetStockObject(NULL_BRUSH));

    Ellipse(hdc, x + 0, y + 20, x + 40, y + 60);
    Ellipse(hdc, x + 30, y + 20, x + 70, y + 60);
    Ellipse(hdc, x + 60, y + 20, x + 100, y + 60);
    Ellipse(hdc, x + 90, y + 20, x + 130, y + 60);

    SelectObject(hdc, oldBrush);
    SelectObject(hdc, oldPen);
    DeleteObject(pen);
}

void drawLogos_5_1(HDC hdc) {
    Logo(hdc, 10, 10);
    Logo(hdc, 10, 310);
    Logo(hdc, 310, 10);
    Logo(hdc, 310, 310);
    Logo(hdc, 160, 160);
}

void drawLogos_5_2(HDC hdc) {
    int x = 0;
    do {
        Logo(hdc, x, 10);
        x += 150;
    } while (x <= 1050);
}

void drawLogos_5_3(HDC hdc) {
    int y = 0;
    do {
        Logo(hdc, 10, y);
        y += 90;
    } while (y < 360);
}

void drawLogos_5_4(HDC hdc) {
    int x = 0, y = 0;
    do {
        Logo(hdc, x, y);
        x += 150;
        y += 90;
    } while (y <= 270);
}
