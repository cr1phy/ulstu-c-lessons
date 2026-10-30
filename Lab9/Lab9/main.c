#include "framework.h"
#include "L91.h"
#include "L92.h"
#include "L93.h"
#include "Lab9.h"

#define MAX_LOADSTRING 100
#define NO_PICTURE (-1)
#define STATUS_HEIGHT 22

HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

static void drawPart1(HDC hdc) {
    drawHouse_1(hdc);
    drawPineTree_2(hdc);
    drawCar_3(hdc);
    drawSnowman_4(hdc);
    drawTree_5(hdc);
    drawBuilding_6(hdc);
    drawLines_7(hdc);
    drawVehicle_8(hdc);
    drawRectangles_9(hdc);
    drawEllipses_10(hdc);
    drawArcs_11(hdc);
}

static void drawPart2(HDC hdc) {
    drawPart2House(hdc);
    drawPart2PineTree(hdc);
    drawBush_1(hdc, 48);
    drawSecondBush_2(hdc, 48);
    drawFence_4(hdc, 48);
    drawLinePatterns_5(hdc);
}

typedef struct {
    void (*draw)(HDC hdc);
    const WCHAR *name;
} Picture;

static const Picture pictures[] = {
    { drawPart1,          L"Часть 1: рисунки 1–11" },
    { drawPart2,          L"Часть 2: дом, ёлка, кусты, забор, трава, лестница" },
    { drawFourPatterns_6, L"Часть 2: четыре узора из линий" },
    { drawStClaus_1_1,    L"Дед Мороз: схема 1" },
    { drawStClaus_1_2,    L"Дед Мороз: схема 2" },
    { drawStClaus_1_3,    L"Дед Мороз: схема 3" },
    { drawStClaus_1_4,    L"Дед Мороз: схема 4" },
    { drawTrucks1,        L"Грузовики: схема 1" },
    { drawTrucks2,        L"Грузовики: схема 2" },
    { drawTrucks3,        L"Грузовики: схема 3" },
    { drawTrucks4,        L"Грузовики: схема 4" },
    { drawSnowWomen1,     L"Снеговики: схема 1" },
    { drawSnowWomen2,     L"Снеговики: схема 2" },
    { drawSnowWomen3,     L"Снеговики: схема 3" },
    { drawSnowWomen4,     L"Снеговики: схема 4" },
    { drawLogos_5_1,      L"Логотипы: схема 1" },
    { drawLogos_5_2,      L"Логотипы: схема 2" },
    { drawLogos_5_3,      L"Логотипы: схема 3" },
    { drawLogos_5_4,      L"Логотипы: схема 4" },
};

#define PICTURE_COUNT ((int)ARRAYSIZE(pictures))
#define PART1_FIRST 0
#define PART2_FIRST 1

static int currentPicture = PART1_FIRST;

static void ShowPicture(HWND hWnd, int index) {
    currentPicture = index;
    InvalidateRect(hWnd, NULL, TRUE);
}

static void DrawStatus(HDC hdc, const RECT *client) {
    WCHAR text[256];
    RECT bar = *client;
    bar.top = bar.bottom - STATUS_HEIGHT;

    if (currentPicture == NO_PICTURE)
        lstrcpynW(text, L"  Экран чист. Любая клавиша — следующий рисунок",
                  ARRAYSIZE(text));
    else
        wsprintfW(text, L"  %d / %d   %s        ← → или любая клавиша — листать",
                  currentPicture + 1, PICTURE_COUNT, pictures[currentPicture].name);

    FillRect(hdc, &bar, GetSysColorBrush(COLOR_BTNFACE));

    HGDIOBJ oldFont = SelectObject(hdc, GetStockObject(DEFAULT_GUI_FONT));
    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, GetSysColor(COLOR_BTNTEXT));
    DrawTextW(hdc, text, -1, &bar, DT_SINGLELINE | DT_VCENTER | DT_LEFT);
    SelectObject(hdc, oldFont);
}

static HMENU CreateMainMenu(void) {
    HMENU menu  = CreateMenu();
    HMENU file  = CreatePopupMenu();
    HMENU tasks = CreatePopupMenu();

    AppendMenuW(file, MF_STRING, IDM_EXIT, L"Вы&ход");

    AppendMenuW(tasks, MF_STRING, IDM_PART1, L"Часть &1");
    AppendMenuW(tasks, MF_STRING, IDM_PART2, L"Часть &2");

    AppendMenuW(menu, MF_POPUP,  (UINT_PTR)file,  L"&Файл");
    AppendMenuW(menu, MF_POPUP,  (UINT_PTR)tasks, L"&Задания");
    AppendMenuW(menu, MF_STRING, IDM_CLEAR,       L"Очистить &экран");

    return menu;
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                      _In_opt_ HINSTANCE hPrevInstance,
                      _In_ LPWSTR    lpCmdLine,
                      _In_ int       nCmdShow) {
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB9, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance(hInstance, nCmdShow))
        return FALSE;

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance) {
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB9));
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName   = NULL;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow) {
    hInst = hInstance;

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, CreateMainMenu(), hInstance, NULL);

    if (!hWnd)
        return FALSE;

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
    case WM_COMMAND:
        switch (LOWORD(wParam)) {
        case IDM_PART1: ShowPicture(hWnd, PART1_FIRST); break;
        case IDM_PART2: ShowPicture(hWnd, PART2_FIRST); break;
        case IDM_CLEAR: ShowPicture(hWnd, NO_PICTURE);  break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
        break;

    case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            RECT client;
            GetClientRect(hWnd, &client);

            if (currentPicture != NO_PICTURE)
                pictures[currentPicture].draw(hdc);

            DrawStatus(hdc, &client);
            EndPaint(hWnd, &ps);
        }
        break;

    case WM_KEYDOWN:
        if (wParam == VK_LEFT)
            ShowPicture(hWnd, currentPicture <= 0 ? PICTURE_COUNT - 1
                                                  : currentPicture - 1);
        else
            ShowPicture(hWnd, (currentPicture + 1) % PICTURE_COUNT);
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
