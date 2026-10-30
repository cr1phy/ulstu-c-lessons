#include <Windows.h>
#include "L92.h"

void drawBush_1(HDC hdc, int count) {
    if (count <= 0) return;

    HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
    if (pen == NULL) return;

    HPEN oldPen = (HPEN)SelectObject(hdc, pen);

    int i = 0;
    int x_from = 400, x_to = 600;
    int y_to = 150;

    do {
        int x = count == 1
            ? 500
            : x_from + (x_to - x_from) * i / (count - 1);

        MoveToEx(hdc, 500, 250, NULL);
        LineTo(hdc, x, y_to);

        i++;
    } while (i < count);

    SelectObject(hdc, oldPen);
    DeleteObject(pen);
}

void drawSecondBush_2(HDC hdc, int count) {
    if (count <= 0) return;

    HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 180, 0));
    if (pen == NULL) return;

    HPEN oldPen = (HPEN)SelectObject(hdc, pen);

    int i = 0;
    int x_from = 0, x_to = 200;

    do {
        int x = count == 1
            ? 100
            : x_from + (x_to - x_from) * i / (count - 1);

        int distance = x - 100;
        if (distance < 0) distance = -distance;

        int y = 50 + 2 * distance;

        MoveToEx(hdc, 100, 250, NULL);
        LineTo(hdc, x, y);

        i++;
    } while (i < count);

    SelectObject(hdc, oldPen);
    DeleteObject(pen);
}

void drawFence_4(HDC hdc, int count) {
    if (count <= 0) return;

    HPEN pen = CreatePen(PS_SOLID, 3, RGB(128, 128, 16));
    if (!pen) return;

    HPEN oldPen = (HPEN)SelectObject(hdc, pen);

    int x_from = 150, x_to = 450;
    int width = 100;
    int i = 0;

    do {
        int x = count == 1
            ? x_from
            : x_from + (x_to - x_from) * i / (count - 1);
        MoveToEx(hdc, x, 0, NULL);
        LineTo(hdc, x, width);
        i++;
    } while (i < count);

    SelectObject(hdc, oldPen);
    DeleteObject(pen);
}

void drawLinePatterns_5(HDC hdc) {
    HPEN grassPen = CreatePen(PS_SOLID, 2, RGB(0, 170, 0));
    HPEN ladderPen = CreatePen(PS_SOLID, 3, RGB(150, 80, 20));

    if (!grassPen || !ladderPen) {
        if (grassPen) DeleteObject(grassPen);
        if (ladderPen) DeleteObject(ladderPen);
        return;
    }

    HPEN oldPen = (HPEN)SelectObject(hdc, grassPen);

    int i = 0;
    int x = 140;
    do {
        MoveToEx(hdc, x, 540, NULL);
        LineTo(hdc, x - 8, 525);

        MoveToEx(hdc, x, 540, NULL);
        LineTo(hdc, x, 520);

        MoveToEx(hdc, x, 540, NULL);
        LineTo(hdc, x + 8, 525);

        x += 15;
        i++;
    } while (i < 18);

    SelectObject(hdc, ladderPen);

    MoveToEx(hdc, 650, 360, NULL);
    LineTo(hdc, 650, 520);

    MoveToEx(hdc, 710, 360, NULL);
    LineTo(hdc, 710, 520);

    i = 0;
    int y = 380;
    do {
        MoveToEx(hdc, 650, y, NULL);
        LineTo(hdc, 710, y);
        y += 20;
        i++;
    } while (i < 7);

    SelectObject(hdc, oldPen);
    DeleteObject(grassPen);
    DeleteObject(ladderPen);
}

void graph1(HDC hdc) {
    int x_from = 150, x_to = 300;
    int y_top = 100, y_bottom = 200;
    int offset = 3, count = 16;

    int i = 0;
    double x = x_from;
    double step = (double)(x_to - x_from) / (count - 1);

    do {
        MoveToEx(hdc, (int)x, y_top, NULL);
        LineTo(hdc, (int)x, y_bottom);

        x += step;
        y_top -= offset;
        y_bottom += offset;

        i++;
    } while (i < count);
}

void graph2(HDC hdc) {
    int i = 0;
    int count = 13;
    int center = 5;

    do {
        int x = 350 + i * 10;
        int distance = i - center;

        if (distance < 0)
            distance = -distance;

        int y_top = 160 - distance * 9;
        int y_bottom = 161 + distance * 7;

        MoveToEx(hdc, x, y_top, NULL);
        LineTo(hdc, x, y_bottom);

        i++;
    } while (i < count);
}

void graph3(HDC hdc) {
    int i = 0;
    int count = 16;

    do {
        int x = 550 + i * 10;
        int y = 150 + i * 10;

        MoveToEx(hdc, x, 300, NULL);
        LineTo(hdc, 700, y);

        i++;
    } while (i < count);
}

void graph4(HDC hdc) {
    int i = 0;
    int count = 16;

    do {
        int x = 750 + i * 10;
        int y = 100 + i * 10;

        MoveToEx(hdc, 750, y, NULL);
        LineTo(hdc, x, 250);

        i++;
    } while (i < count);
}

void drawFourPatterns_6(HDC hdc) {
    HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 0));
    if (!pen) return;

    HPEN oldPen = (HPEN)SelectObject(hdc, pen);

    graph1(hdc);
    graph2(hdc);
    graph3(hdc);
    graph4(hdc);

    SelectObject(hdc, oldPen);
    DeleteObject(pen);
}

void drawPart2House(HDC hdc) {
    HPEN pen = CreatePen(PS_SOLID, 3, RGB(255, 0, 255));
    if (!pen) return;

    HPEN oldPen = (HPEN)SelectObject(hdc, pen);

    MoveToEx(hdc, 150, 350, NULL);
    LineTo(hdc, 275, 250);
    LineTo(hdc, 400, 350);
    LineTo(hdc, 150, 350);

    MoveToEx(hdc, 150, 350, NULL);
    LineTo(hdc, 150, 525);
    LineTo(hdc, 400, 525);
    LineTo(hdc, 400, 350);

    MoveToEx(hdc, 225, 400, NULL);
    LineTo(hdc, 325, 400);
    LineTo(hdc, 325, 475);
    LineTo(hdc, 225, 475);
    LineTo(hdc, 225, 400);

    MoveToEx(hdc, 275, 400, NULL);
    LineTo(hdc, 275, 475);

    MoveToEx(hdc, 225, 437, NULL);
    LineTo(hdc, 325, 437);

    SelectObject(hdc, oldPen);
    DeleteObject(pen);
}

void drawPart2PineTree(HDC hdc) {
    HPEN pen = CreatePen(PS_SOLID, 3, RGB(0, 170, 0));
    if (!pen) return;

    HPEN oldPen = (HPEN)SelectObject(hdc, pen);

    MoveToEx(hdc, 500, 400, NULL);
    LineTo(hdc, 525, 375);
    LineTo(hdc, 550, 400);
    LineTo(hdc, 500, 400);

    MoveToEx(hdc, 475, 450, NULL);
    LineTo(hdc, 525, 400);
    LineTo(hdc, 575, 450);
    LineTo(hdc, 475, 450);

    MoveToEx(hdc, 450, 525, NULL);
    LineTo(hdc, 525, 450);
    LineTo(hdc, 600, 525);
    LineTo(hdc, 450, 525);

    SelectObject(hdc, oldPen);
    DeleteObject(pen);
}
