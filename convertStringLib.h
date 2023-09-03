#ifndef GAMMACONVERTSTRING_H
#define GAMMACONVERTSTRING_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZESTRING	30

/*
������� �������������� ������, �������� "1" � �������� ������� ������
� ������������ ������� �� ������� �������. ��������� ����������� ������
�� ����� ��� ������������ ������ ����������� �������������.
���������
scr - ������� ������ ��������
dst - �������� ��������������� ������
size - ������ �������� ������, ������ ���� �� ������ 30 ����
����������� ��������
0 - ������� ��������� ��������� ������, � dst - �������� ���������
-1 - ������������ ������� ������
-2 - ���������� ������ ��� �������� ������
-3 - � ���������� ������� ������ ������������ �������
-4 - ������������ �������� ������
*/
__declspec(dllexport) int convertID(const char*, char*, size_t);

#endif
