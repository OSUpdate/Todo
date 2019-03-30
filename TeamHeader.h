/*	
The MIT License (MIT)

Copyright (c) 2014-05-30 한국산업기술대학교 자료구조 팀 3

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
	설명 : 일정관리를 효율적으로 할 수 있게 도와주는 프로그램 입니다.

	한성진 : Display, goNext, goPrev, Delete, Wirtefile, management
	김연욱 : order_today, Search
	김용식 : main, 메뉴화면 디자인
	이동현 : readfile, insert, create, rtrim, ltrim, trim, cmpcpy
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

// 이중연결 리스트
// date => 종료일(ex 20130513)
// todo => 255자내 할일
// progress => (0 : 진행전 / 1 : 진행중 / 2 : 완료)
// del => 노드 삭제 기준
typedef struct D_Link{
	char date[9];
	int del;
	int progress;
	char todo[255];
	
	struct D_Link *left, *right;
}D_Link;

//노드 생성
D_Link *create(char date[8], char todo[255], int prc);

//삽입
void insert(D_Link **head,char date[8], char todo[255], int prc);

//날짜 기준으로 노드 검색 함수
D_Link *order_today(D_Link *head);

//전체 출력 함수
void Display(D_Link *head);

//노드 오른쪽 이동
D_Link *goNext(D_Link *node);

//노드 왼쪽 이동
D_Link *goPrev(D_Link *node);

//노드 삭제
D_Link *Delete(D_Link *head,D_Link *position);

// datalist.txt 사용
//파일 쓰기 함수
void writefile(D_Link *head);

//파일 읽기 함수
void readfile(D_Link **list);

//현재 시각
char *now_date();

//문자열 비교후 찾아주는 함수
D_Link *cmpcpy(D_Link *dest, D_Link *src);

// 문자열 우측 공백문자 삭제 함수
char* rtrim(char* s);

// 문자열 좌측 공백문자 삭제 함수
char* ltrim(char *s);

// 문자열 앞뒤 공백 모두 삭제 함수
char* trim(char *s);

//키보드 입력 받은후 처리 해주는 함수
void management(D_Link *list);

// 메인 메뉴 출력
void MainMenu ();

// 팀원 소개
void Makers ();

//메시지 출력 함수
void message(char msg[255]);

//노드값 출력 함수
void showData(int prc, char date[8], char todo[255]);