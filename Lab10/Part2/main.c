#include "framework.h"
#include "Part2.h"
#include "functions.h"

#define MAX_LOADSTRING 100
#define IMAGE_COUNT 42

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

static int index = 0;

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PART2, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PART2));

    MSG msg;

    // Цикл основного сообщения:
    while (GetMessage(&msg, NULL, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PART2));
    wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PART2);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            switch (index) {
                // 10.2.1 — треугольник
            case 0:  RecursiveImage1_1(hdc, 200, 160, 80); break;
            case 1:  RecursiveImage1_2(hdc, 200, 160, 80); break;
            case 2:  RecursiveImage1_3(hdc, 200, 160, 80); break;
            case 3:  RecursiveImage1_4(hdc, 200, 160, 80); break;
            case 4:  RecursiveImage1_5(hdc, 200, 160, 80); break;
            case 5:  RecursiveImage1_6(hdc, 200, 160, 80); break;
            case 6:  RecursiveImage1_7(hdc, 200, 160, 80); break;
            case 7:  RecursiveImage1_8(hdc, 200, 160, 80); break;

                // 10.2.2 — песочные часы
            case 8:  RecursiveImage2_1(hdc, 200, 200, 100); break;
            case 9:  RecursiveImage2_2(hdc, 200, 200, 100); break;
            case 10: RecursiveImage2_3(hdc, 200, 200, 100); break;
            case 11: RecursiveImage2_4(hdc, 200, 200, 100); break;
            case 12: RecursiveImage2_5(hdc, 200, 200, 100); break;
            case 13: RecursiveImage2_6(hdc, 200, 200, 100); break;
            case 14: RecursiveImage2_7(hdc, 200, 200, 100); break;
            case 15: RecursiveImage2_8(hdc, 200, 200, 100); break;

                // 10.2.3 — ромб
            case 16: RecursiveImage3_1(hdc, 200, 200, 100); break;
            case 17: RecursiveImage3_2(hdc, 200, 200, 100); break;
            case 18: RecursiveImage3_3(hdc, 200, 200, 100); break;
            case 19: RecursiveImage3_4(hdc, 200, 200, 100); break;
            case 20: RecursiveImage3_5(hdc, 200, 200, 100); break;
            case 21: RecursiveImage3_6(hdc, 200, 200, 100); break;
            case 22: RecursiveImage3_7(hdc, 200, 200, 100); break;
            case 23: RecursiveImage3_8(hdc, 200, 200, 100); break;
            case 24: RecursiveImage3_9(hdc, 200, 200, 100); break;

            // 10.2.4 — звезда
            case 25: RecursiveImage4_1(hdc, 200, 200, 100); break;
            case 26: RecursiveImage4_2(hdc, 200, 200, 100); break;
            case 27: RecursiveImage4_3(hdc, 200, 200, 100); break;
            case 28: RecursiveImage4_4(hdc, 200, 200, 100); break;
            case 29: RecursiveImage4_5(hdc, 200, 200, 100); break;
            case 30: RecursiveImage4_6(hdc, 200, 200, 100); break;
            case 31: RecursiveImage4_7(hdc, 200, 200, 100); break;
            case 32: RecursiveImage4_8(hdc, 200, 200, 100); break;

            // 10.2.5 — вариант + трассировка
            case 33: RecursiveVariant(hdc, 200, 200, 100, 50); break;
            case 34: RecursiveVariant(hdc, 200, 200, 100, 10); break;
            case 35: {
                int counter = 0;
                RecursiveVariantTraced(hdc, 200, 200, 100, 4, &counter);
                break;
            }

            // 10.2.6* — ещё 2 фигуры
            case 36: RecursiveExtra1(hdc, 300, 300, 100, 80); break;
            case 37: RecursiveExtra1(hdc, 300, 300, 100, 10); break;
            case 38: RecursiveExtra2(hdc, 300, 300, 100, 80); break;
            case 39: RecursiveExtra2(hdc, 300, 300, 100, 20); break;

            // 10.2.7** — свои
            case 40: RecursiveOwn1(hdc, 300, 250, 120, 10); break;
            case 41: RecursiveOwn2(hdc, 300, 260, 120, 10); break;
            }

            char text[32];
            int len = wsprintfA(text, "%d / %d", index + 1, IMAGE_COUNT);
            TextOutA(hdc, 10, 10, text, len);

            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_KEYDOWN:
        switch (wParam) {
        case VK_LEFT:
            index = (index - 1 + IMAGE_COUNT) % IMAGE_COUNT;
            break;
        case VK_RIGHT:
            index = (index + 1) % IMAGE_COUNT;
            break;
        }
        InvalidateRect(hWnd, NULL, TRUE);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
