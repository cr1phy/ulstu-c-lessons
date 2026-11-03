#include <Windows.h>
#include "functions.h"

#define FIGURE_COLOR RGB(0, 0, 255)
#define PEN_WIDTH 2

void TraceLabel(HDC hdc, int x, int y, int callNumber) {
	char buf[16];
	int len = wsprintfA(buf, "%d", callNumber);
	SetBkMode(hdc, TRANSPARENT);
	TextOutA(hdc, x, y, buf, len);
}

void Image1(HDC hdc, int cx, int cy, int size) {
	HPEN pen = CreatePen(PS_SOLID, PEN_WIDTH, FIGURE_COLOR);
	HPEN oldpen = (HPEN)SelectObject(hdc, pen);

	MoveToEx(hdc, cx - size, cy - size, NULL);   // левый верхний
	LineTo(hdc, cx + size, cy - size);           // правый верхний
	LineTo(hdc, cx, cy + size);                  // нижняя вершина
	LineTo(hdc, cx - size, cy - size);           // замкнули

	SelectObject(hdc, oldpen);
	DeleteObject(pen);
}

void RecursiveImage1_1(HDC hdc, int cx, int cy, int size) {
	Image1(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage1_1(hdc, cx - size, cy - size, size / 2);
}

void RecursiveImage1_2(HDC hdc, int cx, int cy, int size) {
	Image1(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage1_2(hdc, cx - size, cy - size, size / 2);
	RecursiveImage1_2(hdc, cx + size, cy - size, size / 2);
}

void RecursiveImage1_3(HDC hdc, int cx, int cy, int size) {
	Image1(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage1_3(hdc, cx - size, cy - size, size / 2);
	RecursiveImage1_3(hdc, cx, cy + size, size / 2);
}

void RecursiveImage1_4(HDC hdc, int cx, int cy, int size) {
	Image1(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage1_4(hdc, cx - size, cy - size, size / 2);
	RecursiveImage1_4(hdc, cx + size, cy - size, size / 2);
	RecursiveImage1_4(hdc, cx, cy + size, size / 2);
}

void RecursiveImage1_5(HDC hdc, int cx, int cy, int size) {
	Image1(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage1_5(hdc, cx, cy - size, size / 2);
}

void RecursiveImage1_6(HDC hdc, int cx, int cy, int size) {
	Image1(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage1_6(hdc, cx + size, cy, size / 2);
}

void RecursiveImage1_7(HDC hdc, int cx, int cy, int size) {
	Image1(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage1_7(hdc, cx - size, cy, size / 2);
}

void RecursiveImage1_8(HDC hdc, int cx, int cy, int size) {
	Image1(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage1_8(hdc, cx - size, cy, size / 2);
	RecursiveImage1_8(hdc, cx + size, cy, size / 2);
	RecursiveImage1_8(hdc, cx, cy - size, size / 2);
}

void Image2(HDC hdc, int cx, int cy, int size) {
	HPEN pen = CreatePen(PS_SOLID, PEN_WIDTH, FIGURE_COLOR);
	HPEN oldpen = (HPEN)SelectObject(hdc, pen);

	MoveToEx(hdc, cx - size / 2, cy - size, NULL);   // левый верхний
	LineTo(hdc, cx + size / 2, cy - size);           // правый верхний
	LineTo(hdc, cx - size, cy + size);               // левый нижний
	LineTo(hdc, cx + size, cy + size);               // правый нижний
	LineTo(hdc, cx - size / 2, cy - size);           // замкнули

	SelectObject(hdc, oldpen);
	DeleteObject(pen);
}

void RecursiveImage2_1(HDC hdc, int cx, int cy, int size) {
	Image2(hdc, cx, cy, size);
	if (size < 5)
		return;
	RecursiveImage2_1(hdc, cx - size, cy + size, size / 2);
}

void RecursiveImage2_2(HDC hdc, int cx, int cy, int size) {
	Image2(hdc, cx, cy, size);
	if (size < 5)
		return;
	RecursiveImage2_2(hdc, cx - (size / 2), cy - size, size / 2);
}

void RecursiveImage2_3(HDC hdc, int cx, int cy, int size) {
	Image2(hdc, cx, cy, size);
	if (size < 5)
		return;
	RecursiveImage2_3(hdc, cx - (size / 2), cy - size, size / 2);
	RecursiveImage2_3(hdc, cx + (size / 2), cy - size, size / 2);
}

void RecursiveImage2_4(HDC hdc, int cx, int cy, int size) {
	Image2(hdc, cx, cy, size);
	if (size < 5)
		return;
	RecursiveImage2_4(hdc, cx - (size / 2), cy - size, size / 2);
	RecursiveImage2_4(hdc, cx + (size / 2), cy - size, size / 2);
	RecursiveImage2_4(hdc, cx + size, cy + size, size / 2);
	RecursiveImage2_4(hdc, cx - size, cy + size, size / 2);
}

void RecursiveImage2_5(HDC hdc, int cx, int cy, int size) {
	Image2(hdc, cx, cy, size);
	if (size < 5)
		return;
	RecursiveImage2_5(hdc, cx - size, cy, size / 2);
}

void RecursiveImage2_6(HDC hdc, int cx, int cy, int size) {
	Image2(hdc, cx, cy, size);
	if (size < 5)
		return;
	RecursiveImage2_6(hdc, cx + size, cy, size / 2);
}

void RecursiveImage2_7(HDC hdc, int cx, int cy, int size) {
	Image2(hdc, cx, cy, size);
	if (size < 5)
		return;
	RecursiveImage2_7(hdc, cx - size, cy, size / 2);
	RecursiveImage2_7(hdc, cx + size, cy, size / 2);
}

void RecursiveImage2_8(HDC hdc, int cx, int cy, int size) {
	Image2(hdc, cx, cy, size);
	if (size < 5)
		return;
	RecursiveImage2_8(hdc, cx - size, cy + size, size / 2);
	RecursiveImage2_8(hdc, cx + size, cy + size, size / 2);
}

void Image3(HDC hdc, int cx, int cy, int size) {
	HPEN hPen = CreatePen(PS_SOLID, 4, FIGURE_COLOR);
	HPEN hOld = (HPEN)SelectObject(hdc, hPen);

	MoveToEx(hdc, cx, cy - size, NULL);   // верх
	LineTo(hdc, cx + size, cy);           // право
	LineTo(hdc, cx, cy + size);           // низ
	LineTo(hdc, cx - size, cy);           // лево
	LineTo(hdc, cx, cy - size);           // замкнули

	SelectObject(hdc, hOld);
	DeleteObject(hPen);
}

void RecursiveImage3_1(HDC hdc, int cx, int cy, int size) {
	Image3(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage3_1(hdc, cx + size, cy, size / 2);
}

void RecursiveImage3_2(HDC hdc, int cx, int cy, int size) {
	Image3(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage3_2(hdc, cx - size, cy, size / 2);
	RecursiveImage3_2(hdc, cx + size, cy, size / 2);
}

void RecursiveImage3_3(HDC hdc, int cx, int cy, int size) {
	Image3(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage3_3(hdc, cx - size, cy, size / 2);
	RecursiveImage3_3(hdc, cx + size, cy, size / 2);
	RecursiveImage3_3(hdc, cx, cy + size, size / 2);
}

void RecursiveImage3_4(HDC hdc, int cx, int cy, int size) {
	Image3(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage3_4(hdc, cx - size, cy, size / 2);
	RecursiveImage3_4(hdc, cx + size, cy, size / 2);
	RecursiveImage3_4(hdc, cx, cy - size, size / 2);
}

void RecursiveImage3_5(HDC hdc, int cx, int cy, int size) {
	Image3(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage3_5(hdc, cx - size, cy, size / 2);
	RecursiveImage3_5(hdc, cx + size, cy, size / 2);
	RecursiveImage3_5(hdc, cx, cy - size, size / 2);
	RecursiveImage3_5(hdc, cx, cy + size, size / 2);
}

void RecursiveImage3_6(HDC hdc, int cx, int cy, int size) {
	Image3(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage3_6(hdc, cx - size / 2, cy - size / 2, size / 2);
	RecursiveImage3_6(hdc, cx + size / 2, cy + size / 2, size / 2);
}

void RecursiveImage3_7(HDC hdc, int cx, int cy, int size) {
	Image3(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage3_7(hdc, cx - size, cy - size, size / 2);
	RecursiveImage3_7(hdc, cx + size, cy + size, size / 2);
	RecursiveImage3_7(hdc, cx + size, cy - size, size / 2);
	RecursiveImage3_7(hdc, cx - size, cy + size, size / 2);
}

void RecursiveImage3_8(HDC hdc, int cx, int cy, int size) {
	Image3(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage3_8(hdc, cx - size / 2, cy - size, size / 2);
	RecursiveImage3_8(hdc, cx + size / 2, cy + size, size / 2);
}

void RecursiveImage3_9(HDC hdc, int cx, int cy, int size) {
	Image3(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage3_9(hdc, cx, cy - size, size / 2);
	RecursiveImage3_9(hdc, cx, cy + size, size / 2);
}

void Image4(HDC hdc, int cx, int cy, int size) {
	HPEN hPen = CreatePen(PS_SOLID, PEN_WIDTH, FIGURE_COLOR);
	HPEN hOld = (HPEN)SelectObject(hdc, hPen);

	MoveToEx(hdc, cx, cy - size, NULL);           // верхний луч
	LineTo(hdc, cx + size / 4, cy - size / 4);
	LineTo(hdc, cx + size, cy);                   // правый луч
	LineTo(hdc, cx + size / 4, cy + size / 4);
	LineTo(hdc, cx, cy + size);                   // нижний луч
	LineTo(hdc, cx - size / 4, cy + size / 4);
	LineTo(hdc, cx - size, cy);                   // левый луч
	LineTo(hdc, cx - size / 4, cy - size / 4);
	LineTo(hdc, cx, cy - size);                   // замкнули

	SelectObject(hdc, hOld);
	DeleteObject(hPen);
}

void RecursiveImage4_1(HDC hdc, int cx, int cy, int size) {
	Image4(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage4_1(hdc, cx + size, cy, size / 2);
}

void RecursiveImage4_2(HDC hdc, int cx, int cy, int size) {
	Image4(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage4_2(hdc, cx + size, cy, size / 2);
	RecursiveImage4_2(hdc, cx - size, cy, size / 2);
}

void RecursiveImage4_3(HDC hdc, int cx, int cy, int size) {
	Image4(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage4_3(hdc, cx, cy + size, size / 2);
	RecursiveImage4_3(hdc, cx, cy - size, size / 2);
}

void RecursiveImage4_4(HDC hdc, int cx, int cy, int size) {
	Image4(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage4_4(hdc, cx, cy + size, size / 2);
	RecursiveImage4_4(hdc, cx, cy - size, size / 2);
	RecursiveImage4_4(hdc, cx - size, cy, size / 2);
}

void RecursiveImage4_5(HDC hdc, int cx, int cy, int size) {
	Image4(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage4_5(hdc, cx, cy + size, size / 2);
	RecursiveImage4_5(hdc, cx, cy - size, size / 2);
	RecursiveImage4_5(hdc, cx - size, cy, size / 2);
	RecursiveImage4_5(hdc, cx + size, cy, size / 2);
}

void RecursiveImage4_6(HDC hdc, int cx, int cy, int size) {
	Image4(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage4_6(hdc, cx + size / 2, cy + size / 2, size / 2);
	RecursiveImage4_6(hdc, cx - size / 2, cy - size / 2, size / 2);
}

void RecursiveImage4_7(HDC hdc, int cx, int cy, int size) {
	Image4(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage4_7(hdc, cx + size / 2, cy - size / 2, size / 2);
	RecursiveImage4_7(hdc, cx - size / 2, cy + size / 2, size / 2);
}

void RecursiveImage4_8(HDC hdc, int cx, int cy, int size) {
	Image4(hdc, cx, cy, size);
	if (size < 20)
		return;
	RecursiveImage4_8(hdc, cx + size / 2, cy + size / 2, size / 2);
	RecursiveImage4_8(hdc, cx - size / 2, cy - size / 2, size / 2);
	RecursiveImage4_8(hdc, cx + size / 2, cy - size / 2, size / 2);
	RecursiveImage4_8(hdc, cx - size / 2, cy + size / 2, size / 2);
}

void VariantImage(HDC hdc, int cx, int cy, int size) {
	HPEN hPen = CreatePen(PS_SOLID, PEN_WIDTH, FIGURE_COLOR);
	HPEN hOld = (HPEN)SelectObject(hdc, hPen);

	MoveToEx(hdc, cx - size, cy - size, NULL);   // левый верхний
	LineTo(hdc, cx + size, cy - size);           // правый верхний
	LineTo(hdc, cx + size / 2, cy);              // правый вырез
	LineTo(hdc, cx + size, cy + size);           // правый нижний
	LineTo(hdc, cx - size, cy + size);           // левый нижний
	LineTo(hdc, cx - size / 2, cy);              // левый вырез
	LineTo(hdc, cx - size, cy - size);           // замкнули

	SelectObject(hdc, hOld);
	DeleteObject(hPen);
}

void RecursiveVariant(HDC hdc, int cx, int cy, int size, int minSize) {
	VariantImage(hdc, cx, cy, size);
	if (size < minSize) return;
	RecursiveVariant(hdc, cx - size, cy - size, size / 2, minSize);
	RecursiveVariant(hdc, cx + size, cy - size, size / 2, minSize);
	RecursiveVariant(hdc, cx - size, cy + size, size / 2, minSize);
	RecursiveVariant(hdc, cx + size, cy + size, size / 2, minSize);
}

void RecursiveVariantTraced(HDC hdc, int cx, int cy, int size, int depth, int* callCounter) {
	(*callCounter)++;
	VariantImage(hdc, cx, cy, size);
	TraceLabel(hdc, cx - 4, cy - 8, *callCounter);
	if (depth <= 1) {
		return;
	}
	RecursiveVariantTraced(hdc, cx - size, cy - size, size / 2, depth - 1, callCounter);
	RecursiveVariantTraced(hdc, cx + size, cy - size, size / 2, depth - 1, callCounter);
	RecursiveVariantTraced(hdc, cx - size, cy + size, size / 2, depth - 1, callCounter);
	RecursiveVariantTraced(hdc, cx + size, cy + size, size / 2, depth - 1, callCounter);
}

void ExtraImage1(HDC hdc, int cx, int cy, int size) {
	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	HPEN hOld = (HPEN)SelectObject(hdc, hPen);

	MoveToEx(hdc, cx - size / 2, cy, NULL);   // вырез слева
	LineTo(hdc, cx - size, cy - size);        // левый верхний
	LineTo(hdc, cx, cy - size);               // правый верхний
	LineTo(hdc, cx + size / 2, cy);           // острие справа
	LineTo(hdc, cx, cy + size);               // правый нижний
	LineTo(hdc, cx - size, cy + size);        // левый нижний
	LineTo(hdc, cx - size / 2, cy);           // замкнули

	SelectObject(hdc, hOld);
	DeleteObject(hPen);
}

void RecursiveExtra1(HDC hdc, int cx, int cy, int size, int minSize) {
	ExtraImage1(hdc, cx, cy, size);
	if (size < minSize) {
		return;
	}
	RecursiveExtra1(hdc, cx + 3 * size / 4, cy, size / 2, minSize);
	RecursiveExtra1(hdc, cx - 3 * size / 4, cy, size / 2, minSize);
}

void ExtraImage2(HDC hdc, int cx, int cy, int size) {
	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	HPEN hOld = (HPEN)SelectObject(hdc, hPen);

	MoveToEx(hdc, cx - size / 2, cy - size / 2, NULL);   // левый верхний
	LineTo(hdc, cx + size, cy - size / 2);               // правый верхний
	LineTo(hdc, cx + size / 2, cy + size / 2);           // правый нижний
	LineTo(hdc, cx - size, cy + size / 2);               // левый нижний
	LineTo(hdc, cx - size / 2, cy - size / 2);           // замкнули

	SelectObject(hdc, hOld);
	DeleteObject(hPen);
}

void RecursiveExtra2(HDC hdc, int cx, int cy, int size, int minSize) {
	ExtraImage2(hdc, cx, cy, size);
	if (size < minSize) {
		return;
	}
	RecursiveExtra2(hdc, cx - size / 2, cy - size / 2, size / 2, minSize);   // левый верхний
	RecursiveExtra2(hdc, cx + size, cy - size / 2, size / 2, minSize);       // правый верхний
	RecursiveExtra2(hdc, cx + size / 2, cy + size / 2, size / 2, minSize);   // правый нижний
	RecursiveExtra2(hdc, cx - size, cy + size / 2, size / 2, minSize);       // левый нижний
}

void OwnImage1(HDC hdc, int cx, int cy, int size) {
	int h = size * 866 / 1000;

	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	HPEN hOld = (HPEN)SelectObject(hdc, hPen);

	// треугольник вершиной вверх
	MoveToEx(hdc, cx, cy - size, NULL);       // верх
	LineTo(hdc, cx + h, cy + size / 2);       // правый нижний
	LineTo(hdc, cx - h, cy + size / 2);       // левый нижний
	LineTo(hdc, cx, cy - size);               // замкнули

	// треугольник вершиной вниз
	MoveToEx(hdc, cx, cy + size, NULL);       // низ
	LineTo(hdc, cx + h, cy - size / 2);       // правый верхний
	LineTo(hdc, cx - h, cy - size / 2);       // левый верхний
	LineTo(hdc, cx, cy + size);               // замкнули

	SelectObject(hdc, hOld);
	DeleteObject(hPen);
}

void RecursiveOwn1(HDC hdc, int cx, int cy, int size, int minSize) {
	int h = size * 866 / 1000;

	OwnImage1(hdc, cx, cy, size);
	if (size < minSize) {
		return;
	}
	RecursiveOwn1(hdc, cx, cy - size, size / 3, minSize);          // верх
	RecursiveOwn1(hdc, cx + h, cy - size / 2, size / 3, minSize);  // правый верхний
	RecursiveOwn1(hdc, cx + h, cy + size / 2, size / 3, minSize);  // правый нижний
	RecursiveOwn1(hdc, cx, cy + size, size / 3, minSize);          // низ
	RecursiveOwn1(hdc, cx - h, cy + size / 2, size / 3, minSize);  // левый нижний
	RecursiveOwn1(hdc, cx - h, cy - size / 2, size / 3, minSize);  // левый верхний
}

void OwnImage2(HDC hdc, int cx, int cy, int size) {
	HPEN hPen = CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	HPEN hOld = (HPEN)SelectObject(hdc, hPen);

	MoveToEx(hdc, cx, cy - size, NULL);                                // верх
	LineTo(hdc, cx + size * 588 / 1000, cy + size * 809 / 1000);       // правый нижний
	LineTo(hdc, cx - size * 951 / 1000, cy - size * 309 / 1000);       // левый верхний
	LineTo(hdc, cx + size * 951 / 1000, cy - size * 309 / 1000);       // правый верхний
	LineTo(hdc, cx - size * 588 / 1000, cy + size * 809 / 1000);       // левый нижний
	LineTo(hdc, cx, cy - size);                                        // замкнули

	SelectObject(hdc, hOld);
	DeleteObject(hPen);
}

void RecursiveOwn2(HDC hdc, int cx, int cy, int size, int minSize) {
	OwnImage2(hdc, cx, cy, size);
	if (size < minSize) {
		return;
	}
	RecursiveOwn2(hdc, cx, cy - size, size * 2 / 5, minSize);                                     // верх
	RecursiveOwn2(hdc, cx + size * 951 / 1000, cy - size * 309 / 1000, size * 2 / 5, minSize);  // правый верхний
	RecursiveOwn2(hdc, cx + size * 588 / 1000, cy + size * 809 / 1000, size * 2 / 5, minSize);  // правый нижний
	RecursiveOwn2(hdc, cx - size * 588 / 1000, cy + size * 809 / 1000, size * 2 / 5, minSize);  // левый нижний
	RecursiveOwn2(hdc, cx - size * 951 / 1000, cy - size * 309 / 1000, size * 2 / 5, minSize);  // левый верхний
}