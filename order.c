#include "teamheader.h"

char *now_date()
{
	time_t now;
	struct tm t;
	char buff[100];

	// 세계 표준 시간(UTC)로 반환
	time(&now);
	// UTC를 국가시간으로 변환
	t = *localtime(&now);

	// 1970년 1월 1일 0시를 기준
	sprintf(buff, "%d%02d%02d", t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);
	puts(buff);

	return buff;
}

D_Link *order_today(D_Link *head)
{
	D_Link *tmp = head, *output=NULL;
	char date[9];

	system("cls");
	printf("             ___        ___        ___        ___\n");
	printf("     ┌──＜   ＞──＜   ＞──＜   ＞──＜   ＞──┐\n");
	printf("     │      ---        ---        ---        ---      │＼\n");
	printf("     │                                                │∥│\n");
	printf("     │ ─────────────────────── │∥│\n");
	printf("     │ 검색할 날짜를 입력하세요(ex 20140115)          │∥│\n");
	printf("     │ ─────────────────────── │∥│\n");
	printf("     │ 오늘 날짜를 원하면 : 1                         │∥│\n");
	printf("     │ ─────────────────────── │∥│\n");
	printf("     │ >> ");
	scanf("%s", date);
	printf("     │ ─────────────────────── │∥│\n");
	printf("     │                                                │∥│\n");
	printf("     └────────────────────────┘∥│\n");
	printf("      ＼ 〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓┘│\n");
	printf("         ─────────────────────────┘\n");
	if (strcmp(date, "1") == 0) strcpy(date, now_date());
	while (tmp != NULL)
	{
		if (strcmp(tmp->date, date) == 0)// 날짜가 입력값과 일치한 노드가 있으면 날짜가 같은 노드들로 리스트 생성
		{
			insert(&output, tmp->date, tmp->todo, tmp->progress); 
		}
		tmp = tmp->right;
	}
	management(output);
	tmp = cmpcpy(head, output);
	writefile(tmp);
	return tmp;
}
