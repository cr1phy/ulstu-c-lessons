#pragma once

int strlen_L7211(char s[]);
int strlen_L7212(char* s);

int strcmp_L7221(char s1[], char s2[]);
int strcmp_L7222(char* s1, char* s2);

void strcpy_L723(char s1[], char s2[]);
void strcat_L724(char* s1, char* s2);

char* strchr_L7251(char source[], char value);
char* strchr_L7252(char* source, char value);

char* CreateNewString_L7261(char s1[]);
char* CreateNewStringP(char* s1);

void demo_L7261(void);
void demo_L7262(void);

void test_strlen(void);
void test_strcmp(void);
void test_strcpy(void);
void test_strcat(void);
void test_strchr(void);
void test_newstring(void);
void test_all(void);
