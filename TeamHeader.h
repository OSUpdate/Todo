/*	
The MIT License (MIT)

Copyright (c) 2014-05-30 �ѱ����������б� �ڷᱸ�� �� 3

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.

	Project Name : To do List
	���� : ���������� ȿ�������� �� �� �ְ� �����ִ� ���α׷� �Դϴ�.

	�Ѽ��� : Display, goNext, goPrev, Delete, Wirtefile, management
	�迬�� : order_today, Search
	���� : main, �޴�ȭ�� ������
	�̵��� : readfile, insert, create, rtrim, ltrim, trim, cmpcpy
*/

#include <string.h>
#include <malloc.h>
#include <ctype.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT 75	
#define RIGHT 77
#define ESC 27
#define DELETE 100
#define CHANGE 99

// ���߿��� ����Ʈ
// date => ������(ex 20130513)
// todo => 255�ڳ� ����
// progress => (0 : ������ / 1 : ������ / 2 : �Ϸ�)
// del => ��� ���� ����
typedef struct D_Link{
	char date[9];
	int del;
	int progress;
	char todo[255];
	
	struct D_Link *left, *right;
}D_Link;

//��� ����
D_Link *create(char date[8], char todo[255], int prc);

//����
void insert(D_Link **head,char date[8], char todo[255], int prc);

//��¥ �������� ��� �˻� �Լ�
D_Link *order_today(D_Link *head);

//��ü ��� �Լ�
void Display(D_Link *head);

//��� ������ �̵�
D_Link *goNext(D_Link *node);

//��� ���� �̵�
D_Link *goPrev(D_Link *node);

//��� ����
D_Link *Delete(D_Link *head,D_Link *position);

// datalist.txt ���
//���� ���� �Լ�
void writefile(D_Link *head);

//���� �б� �Լ�
void readfile(D_Link **list);

//���� �ð�
char *now_date();

//���ڿ� ���� ã���ִ� �Լ�
D_Link *cmpcpy(D_Link *dest, D_Link *src);

// ���ڿ� ���� ���鹮�� ���� �Լ�
char* rtrim(char* s);

// ���ڿ� ���� ���鹮�� ���� �Լ�
char* ltrim(char *s);

// ���ڿ� �յ� ���� ��� ���� �Լ�
char* trim(char *s);

//Ű���� �Է� ������ ó�� ���ִ� �Լ�
void management(D_Link *list);

// ���� �޴� ���
void MainMenu ();

// ���� �Ұ�
void Makers ();

//�޽��� ��� �Լ�
void message(char msg[255]);

//��尪 ��� �Լ�
void showData(int prc, char date[8], char todo[255]);