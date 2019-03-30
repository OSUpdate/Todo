#include "teamheader.h"

char *now_date()
{
	time_t now;
	struct tm t;
	char buff[100];

	// ���� ǥ�� �ð�(UTC)�� ��ȯ
	time(&now);
	// UTC�� �����ð����� ��ȯ
	t = *localtime(&now);

	// 1970�� 1�� 1�� 0�ø� ����
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
	printf("     ��������   ��������   ��������   ��������   ��������\n");
	printf("     ��      ---        ---        ---        ---      ����\n");
	printf("     ��                                                ������\n");
	printf("     �� ���������������������������������������������� ������\n");
	printf("     �� �˻��� ��¥�� �Է��ϼ���(ex 20140115)          ������\n");
	printf("     �� ���������������������������������������������� ������\n");
	printf("     �� ���� ��¥�� ���ϸ� : 1                         ������\n");
	printf("     �� ���������������������������������������������� ������\n");
	printf("     �� >> ");
	scanf("%s", date);
	printf("     �� ���������������������������������������������� ������\n");
	printf("     ��                                                ������\n");
	printf("     ��������������������������������������������������������\n");
	printf("      �� ������������������������릥��\n");
	printf("         ����������������������������������������������������\n");
	if (strcmp(date, "1") == 0) strcpy(date, now_date());
	while (tmp != NULL)
	{
		if (strcmp(tmp->date, date) == 0)// ��¥�� �Է°��� ��ġ�� ��尡 ������ ��¥�� ���� ����� ����Ʈ ����
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
