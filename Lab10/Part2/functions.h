#pragma once

#include <windows.h>

// Подпись номера вызова в точке (x, y) для графической трассировки (10.2.5).
void TraceLabel(HDC hdc, int x, int y, int callNumber);


void Image1(HDC hdc, int cx, int cy, int size);
void Image2(HDC hdc, int cx, int cy, int size);
void Image3(HDC hdc, int cx, int cy, int size);
void Image4(HDC hdc, int cx, int cy, int size);


void RecursiveImage1_1(HDC hdc, int cx, int cy, int size);

// 10.2.1.1
void RecursiveImage1_2(HDC hdc, int cx, int cy, int size);
void RecursiveImage1_3(HDC hdc, int cx, int cy, int size);
void RecursiveImage1_4(HDC hdc, int cx, int cy, int size);

// 10.2.1.2*
void RecursiveImage1_5(HDC hdc, int cx, int cy, int size);
void RecursiveImage1_6(HDC hdc, int cx, int cy, int size);
void RecursiveImage1_7(HDC hdc, int cx, int cy, int size);
void RecursiveImage1_8(HDC hdc, int cx, int cy, int size);


void RecursiveImage2_1(HDC hdc, int cx, int cy, int size);

// 10.2.2.1
void RecursiveImage2_2(HDC hdc, int cx, int cy, int size);
void RecursiveImage2_3(HDC hdc, int cx, int cy, int size);
void RecursiveImage2_4(HDC hdc, int cx, int cy, int size);

// 10.2.2.2*
void RecursiveImage2_5(HDC hdc, int cx, int cy, int size);
void RecursiveImage2_6(HDC hdc, int cx, int cy, int size);
void RecursiveImage2_7(HDC hdc, int cx, int cy, int size);
void RecursiveImage2_8(HDC hdc, int cx, int cy, int size);



void RecursiveImage3_1(HDC hdc, int cx, int cy, int size);

// 10.2.3.1
void RecursiveImage3_2(HDC hdc, int cx, int cy, int size);
void RecursiveImage3_3(HDC hdc, int cx, int cy, int size);
void RecursiveImage3_4(HDC hdc, int cx, int cy, int size);
void RecursiveImage3_5(HDC hdc, int cx, int cy, int size);

// 10.2.3.2*
void RecursiveImage3_6(HDC hdc, int cx, int cy, int size);
void RecursiveImage3_7(HDC hdc, int cx, int cy, int size);
void RecursiveImage3_8(HDC hdc, int cx, int cy, int size);
void RecursiveImage3_9(HDC hdc, int cx, int cy, int size);



void RecursiveImage4_1(HDC hdc, int cx, int cy, int size);

// 10.2.4.1
void RecursiveImage4_2(HDC hdc, int cx, int cy, int size);
void RecursiveImage4_3(HDC hdc, int cx, int cy, int size);
void RecursiveImage4_4(HDC hdc, int cx, int cy, int size);

// 10.2.4.2*
void RecursiveImage4_5(HDC hdc, int cx, int cy, int size);
void RecursiveImage4_6(HDC hdc, int cx, int cy, int size);
void RecursiveImage4_7(HDC hdc, int cx, int cy, int size);
void RecursiveImage4_8(HDC hdc, int cx, int cy, int size);



void VariantImage(HDC hdc, int cx, int cy, int size);
void RecursiveVariant(HDC hdc, int cx, int cy, int size, int minSize);
void RecursiveVariantTraced(HDC hdc, int cx, int cy, int size, int depth, int* callCounter);



void ExtraImage1(HDC hdc, int cx, int cy, int size);
void RecursiveExtra1(HDC hdc, int cx, int cy, int size, int minSize);

void ExtraImage2(HDC hdc, int cx, int cy, int size);
void RecursiveExtra2(HDC hdc, int cx, int cy, int size, int minSize);


// 10.2.7**
void OwnImage1(HDC hdc, int cx, int cy, int size);
void RecursiveOwn1(HDC hdc, int cx, int cy, int size, int minSize);
void OwnImage2(HDC hdc, int cx, int cy, int size);
void RecursiveOwn2(HDC hdc, int cx, int cy, int size, int minSize);


// 10.2.8 — переключение рисунков по клавишам
int  ImageCount(void);                   // сколько всего рисунков
void DrawImage(HDC hdc, int index);      // нарисовать рисунок с номером index (switch внутри)