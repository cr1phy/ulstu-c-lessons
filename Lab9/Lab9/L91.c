#include <Windows.h>
#include "L91.h"

const int SCALE = 25;

void drawHouse_1(HDC hdc) {
    MoveToEx(hdc, 5 * SCALE, 28 * SCALE, NULL);
    LineTo(hdc, 8 * SCALE, 25 * SCALE);
    LineTo(hdc, 11 * SCALE, 28 * SCALE);
    LineTo(hdc, 5 * SCALE, 28 * SCALE);
    LineTo(hdc, 5 * SCALE, 34 * SCALE);
    LineTo(hdc, 11 * SCALE, 34 * SCALE);
    LineTo(hdc, 11 * SCALE, 28 * SCALE);

    MoveToEx(hdc, 7 * SCALE, 30 * SCALE, NULL);
    LineTo(hdc, 9 * SCALE, 30 * SCALE);
    LineTo(hdc, 9 * SCALE, 32 * SCALE);
    LineTo(hdc, 7 * SCALE, 32 * SCALE);
    LineTo(hdc, 7 * SCALE, 30 * SCALE);

    MoveToEx(hdc, 7 * SCALE, 31 * SCALE, NULL);
    LineTo(hdc, 8 * SCALE, 31 * SCALE);

    MoveToEx(hdc, 8 * SCALE, 30 * SCALE, NULL);
    LineTo(hdc, 8 * SCALE, 32 * SCALE);
}

void drawPineTree_2(HDC hdc) {
    MoveToEx(hdc, 375, 700, NULL);
    LineTo(hdc, 400, 650);
    LineTo(hdc, 425, 700);
    LineTo(hdc, 375, 700);

    MoveToEx(hdc, 350, 775, NULL);
    LineTo(hdc, 400, 700);
    LineTo(hdc, 450, 775);
    LineTo(hdc, 350, 775);

    MoveToEx(hdc, 325, 850, NULL);
    LineTo(hdc, 400, 775);
    LineTo(hdc, 475, 850);
    LineTo(hdc, 325, 850);
}

void drawCar_3(HDC hdc) {
    int saved = SaveDC(hdc);
    if (saved == 0) return;

    HBRUSH bodyBrush = CreateSolidBrush(RGB(0, 90, 220));
    HBRUSH roofBrush = CreateSolidBrush(RGB(100, 210, 255));
    HBRUSH wheelsBrush = CreateSolidBrush(RGB(35, 35, 35));
    HPEN roofPen = CreatePen(PS_SOLID, 3, RGB(180, 40, 40));

    SelectObject(hdc, bodyBrush);
    Rectangle(hdc, 525, 725, 800, 775);

    SelectObject(hdc, roofBrush);
    SelectObject(hdc, roofPen);

    POINT roof[] = {
        {575, 725},
        {600, 675},
        {700, 675},
        {750, 725}
    };

    Polygon(hdc, roof, 4);

    SelectObject(hdc, GetStockObject(BLACK_PEN));
    SelectObject(hdc, wheelsBrush);

    Ellipse(hdc, 575, 750, 625, 800);
    Ellipse(hdc, 725, 750, 775, 800);

    RestoreDC(hdc, saved);

    DeleteObject(bodyBrush);
    DeleteObject(roofBrush);
    DeleteObject(wheelsBrush);
    DeleteObject(roofPen);
}

void drawSnowman_4(HDC hdc) {
    int saved = SaveDC(hdc);
    if (saved == 0) return;

    HBRUSH headBrush = CreateSolidBrush(RGB(235, 245, 255));
    HBRUSH middleBrush = CreateSolidBrush(RGB(190, 225, 255));
    HBRUSH bottomBrush = CreateSolidBrush(RGB(145, 195, 240));

    SelectObject(hdc, headBrush);
    Ellipse(hdc, 575, 400, 625, 450);

    SelectObject(hdc, middleBrush);
    Ellipse(hdc, 550, 450, 650, 500);

    SelectObject(hdc, bottomBrush);
    Ellipse(hdc, 525, 500, 675, 550);

    RestoreDC(hdc, saved);

    DeleteObject(headBrush);
    DeleteObject(middleBrush);
    DeleteObject(bottomBrush);
}

void drawTree_5(HDC hdc) {
    int saved = SaveDC(hdc);
    if (saved == 0) return;

    HPEN trunkPen = CreatePen(PS_SOLID, 6, RGB(125, 70, 30));
    HPEN leavesPen = CreatePen(PS_SOLID, 3, RGB(25, 135, 45));
    HPEN leavesPen2 = CreatePen(PS_SOLID, 2, RGB(90, 180, 65));

    SelectObject(hdc, GetStockObject(NULL_BRUSH));

    SelectObject(hdc, trunkPen);

    MoveToEx(hdc, 55, 725, NULL);
    LineTo(hdc, 55, 850);
    LineTo(hdc, 85, 850);
    LineTo(hdc, 85, 725);

    SelectObject(hdc, leavesPen);

    Ellipse(hdc, 55, 600, 85, 650);
    Ellipse(hdc, 40, 625, 70, 675);
    Ellipse(hdc, 70, 625, 100, 675);
    Ellipse(hdc, 25, 650, 55, 700);
    Ellipse(hdc, 55, 650, 85, 700);
    Ellipse(hdc, 85, 650, 115, 700);

    SelectObject(hdc, leavesPen2);

    Ellipse(hdc, 25, 675, 55, 725);
    Ellipse(hdc, 55, 675, 85, 725);
    Ellipse(hdc, 85, 675, 115, 725);
    Ellipse(hdc, 40, 700, 70, 750);
    Ellipse(hdc, 70, 700, 100, 750);

    RestoreDC(hdc, saved);

    DeleteObject(trunkPen);
    DeleteObject(leavesPen);
    DeleteObject(leavesPen2);
}

void drawBuilding_6(HDC hdc) {
    int saved = SaveDC(hdc);
    if (saved == 0) return;

    HPEN wallPen = CreatePen(PS_SOLID, 3, RGB(110, 75, 45));
    HPEN roofPen = CreatePen(PS_SOLID, 4, RGB(155, 65, 25));
    HPEN windowPen = CreatePen(PS_SOLID, 2, RGB(0, 135, 210));
    HPEN doorPen = CreatePen(PS_SOLID, 3, RGB(135, 75, 35));

    HBRUSH roofBrush = CreateSolidBrush(RGB(230, 155, 75));

    SelectObject(hdc, GetStockObject(NULL_BRUSH));
    SelectObject(hdc, wallPen);

    MoveToEx(hdc, 75, 350, NULL);
    LineTo(hdc, 75, 500);
    LineTo(hdc, 350, 500);
    LineTo(hdc, 350, 350);
    LineTo(hdc, 75, 350);

    SelectObject(hdc, roofPen);
    SelectObject(hdc, roofBrush);

    POINT roof[] = {
        {50, 350},
        {75, 300},
        {350, 300},
        {375, 350}
    };

    Polygon(hdc, roof, 4);

    SelectObject(hdc, GetStockObject(NULL_BRUSH));
    SelectObject(hdc, windowPen);

    Rectangle(hdc, 100, 400, 150, 450);

    MoveToEx(hdc, 125, 400, NULL);
    LineTo(hdc, 125, 450);

    MoveToEx(hdc, 100, 425, NULL);
    LineTo(hdc, 150, 425);

    Rectangle(hdc, 275, 400, 325, 450);

    MoveToEx(hdc, 275, 425, NULL);
    LineTo(hdc, 325, 425);

    MoveToEx(hdc, 300, 400, NULL);
    LineTo(hdc, 300, 450);

    SelectObject(hdc, doorPen);
    Rectangle(hdc, 175, 400, 250, 500);

    MoveToEx(hdc, 194, 400, NULL);
    LineTo(hdc, 194, 500);

    MoveToEx(hdc, 213, 400, NULL);
    LineTo(hdc, 213, 500);

    MoveToEx(hdc, 231, 400, NULL);
    LineTo(hdc, 231, 500);

    RestoreDC(hdc, saved);

    DeleteObject(wallPen);
    DeleteObject(roofPen);
    DeleteObject(windowPen);
    DeleteObject(doorPen);
    DeleteObject(roofBrush);
}

void drawLines_7(HDC hdc) {
    int saved = SaveDC(hdc);
    if (saved == 0) return;

    HPEN trunkPen = CreatePen(PS_SOLID, 5, RGB(120, 70, 35));
    HPEN branchPen1 = CreatePen(PS_SOLID, 3, RGB(20, 120, 45));
    HPEN branchPen2 = CreatePen(PS_SOLID, 2, RGB(80, 180, 60));

    SelectObject(hdc, trunkPen);

    MoveToEx(hdc, 875, 650, NULL);
    LineTo(hdc, 875, 850);

    SelectObject(hdc, branchPen1);

    MoveToEx(hdc, 825, 650, NULL);
    LineTo(hdc, 875, 675);
    LineTo(hdc, 925, 650);

    MoveToEx(hdc, 825, 675, NULL);
    LineTo(hdc, 875, 700);
    LineTo(hdc, 925, 675);

    MoveToEx(hdc, 825, 700, NULL);
    LineTo(hdc, 875, 725);
    LineTo(hdc, 925, 700);

    SelectObject(hdc, branchPen2);

    MoveToEx(hdc, 825, 725, NULL);
    LineTo(hdc, 875, 750);
    LineTo(hdc, 925, 725);

    MoveToEx(hdc, 825, 750, NULL);
    LineTo(hdc, 875, 775);
    LineTo(hdc, 925, 750);

    MoveToEx(hdc, 825, 775, NULL);
    LineTo(hdc, 875, 800);
    LineTo(hdc, 925, 775);

    RestoreDC(hdc, saved);

    DeleteObject(trunkPen);
    DeleteObject(branchPen1);
    DeleteObject(branchPen2);
}

void drawVehicle_8(HDC hdc) {
    int saved = SaveDC(hdc);
    if (saved == 0) return;

    SelectObject(hdc, GetStockObject(BLACK_PEN));
    SelectObject(hdc, GetStockObject(NULL_BRUSH));

    Rectangle(hdc, 50, 100, 250, 200);

    MoveToEx(hdc, 250, 125, NULL);
    LineTo(hdc, 300, 125);
    LineTo(hdc, 350, 175);
    LineTo(hdc, 350, 200);
    LineTo(hdc, 250, 200);
    LineTo(hdc, 250, 125);

    MoveToEx(hdc, 275, 150, NULL);
    LineTo(hdc, 300, 150);
    LineTo(hdc, 325, 175);
    LineTo(hdc, 275, 175);
    LineTo(hdc, 275, 150);

    HBRUSH wheelsBrush =
        CreateHatchBrush(HS_BDIAGONAL, RGB(0, 0, 0));

    SetBkMode(hdc, OPAQUE);
    SetBkColor(hdc, RGB(255, 255, 255));

    SelectObject(hdc, wheelsBrush);

    Ellipse(hdc, 75, 175, 125, 225);
    Ellipse(hdc, 275, 175, 325, 225);

    RestoreDC(hdc, saved);

    DeleteObject(wheelsBrush);
}

void drawRectangles_9(HDC hdc) {
    int saved = SaveDC(hdc);
    if (saved == 0) return;

    HPEN wallPen = CreatePen(PS_SOLID, 4, RGB(40, 60, 130));
    HPEN windowPen = CreatePen(PS_SOLID, 2, RGB(30, 100, 150));
    HPEN doorPen = CreatePen(PS_SOLID, 3, RGB(130, 45, 115));

    HBRUSH brush1 = CreateSolidBrush(RGB(255, 210, 65));
    HBRUSH brush2 = CreateSolidBrush(RGB(80, 205, 220));
    HBRUSH brush3 = CreateSolidBrush(RGB(240, 110, 90));
    HBRUSH brush4 = CreateSolidBrush(RGB(110, 195, 100));
    HBRUSH brush5 = CreateHatchBrush(
        HS_DIAGCROSS, RGB(145, 65, 180)
    );

    SelectObject(hdc, wallPen);
    SelectObject(hdc, GetStockObject(NULL_BRUSH));
    Rectangle(hdc, 450, 75, 600, 250);

    SelectObject(hdc, windowPen);

    SelectObject(hdc, brush1);
    Rectangle(hdc, 475, 100, 500, 125);

    SelectObject(hdc, brush2);
    Rectangle(hdc, 550, 100, 575, 125);

    SelectObject(hdc, brush3);
    Rectangle(hdc, 475, 150, 500, 175);

    SelectObject(hdc, brush4);
    Rectangle(hdc, 550, 150, 575, 175);

    SelectObject(hdc, doorPen);
    SelectObject(hdc, brush5);

    SetBkColor(hdc, RGB(245, 225, 250));
    SetBkMode(hdc, OPAQUE);

    Rectangle(hdc, 500, 200, 550, 250);

    RestoreDC(hdc, saved);

    DeleteObject(wallPen);
    DeleteObject(windowPen);
    DeleteObject(doorPen);

    DeleteObject(brush1);
    DeleteObject(brush2);
    DeleteObject(brush3);
    DeleteObject(brush4);
    DeleteObject(brush5);
}

void drawEllipses_10(HDC hdc) {
    int saved = SaveDC(hdc);
    if (saved == 0) return;

    SelectObject(hdc, GetStockObject(BLACK_PEN));
    SelectObject(hdc, GetStockObject(NULL_BRUSH));

    Ellipse(hdc, 825, 50, 875, 150);
    Ellipse(hdc, 825, 150, 875, 250);
    Ellipse(hdc, 750, 125, 850, 175);
    Ellipse(hdc, 850, 125, 950, 175);

    HBRUSH centerBrush =
        CreateHatchBrush(HS_BDIAGONAL, RGB(0, 0, 0));

    SetBkMode(hdc, OPAQUE);
    SetBkColor(hdc, RGB(255, 255, 255));
    SelectObject(hdc, centerBrush);

    Ellipse(hdc, 825, 125, 875, 175);

    RestoreDC(hdc, saved);

    DeleteObject(centerBrush);
}

void drawArcs_11(HDC hdc) {
    int saved = SaveDC(hdc);
    if (saved == 0) return;

    SelectObject(hdc, GetStockObject(BLACK_PEN));
    SetArcDirection(hdc, AD_COUNTERCLOCKWISE);

    Arc(hdc,
        1000, 350, 1200, 500,
        1200, 425,
        1000, 425);

    Arc(hdc,
        1000, 400, 1050, 450,
        1050, 425,
        1000, 425);

    Arc(hdc,
        1050, 400, 1100, 450,
        1100, 425,
        1050, 425);

    Arc(hdc,
        1100, 400, 1150, 450,
        1150, 425,
        1100, 425);

    Arc(hdc,
        1150, 400, 1200, 450,
        1200, 425,
        1150, 425);

    MoveToEx(hdc, 1100, 425, NULL);
    LineTo(hdc, 1100, 500);

    Arc(hdc,
        1050, 475, 1100, 525,
        1050, 500,
        1100, 500);

    RestoreDC(hdc, saved);
}
