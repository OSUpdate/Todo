#include "teamheader.h"

D_Link *goNext(D_Link *node){
	D_Link *temp=node->right;
	if(temp==NULL){
		message("�����Ͱ� �������� �ʽ��ϴ�.                ������");
		temp = goPrev(node);
	}
	else{
		showData(temp->progress, temp->date, temp->todo);
	}
	return temp;
}
D_Link *goPrev(D_Link *node){
	D_Link *temp=node->left;
	if(temp==NULL){
		message("�����Ͱ� �������� �ʽ��ϴ�.                ������");
		temp = goNext(node);
	}
	else{
		showData(temp->progress, temp->date, temp->todo);
	}
	return temp;
}


D_Link *create(char date[8], char todo[255], int prc)
{
	D_Link *new_node = (D_Link*)malloc(sizeof(D_Link));
	strcpy(	new_node->date, date);
	strcpy(	new_node->todo, todo);
	new_node->progress = prc == 0? 0 : prc;
	new_node->left = new_node->right = NULL;
	new_node->del=0;

	return new_node;
}
// ���ڿ� ���� ���鹮�� ���� �Լ�
char *rtrim(char* s) {
	char t[4000];
	char *end;

	// Visual C 2003 ���Ͽ�����
	// strcpy(t, s);
	// �̷��� �ؾ� ��
	strcpy(t, s); // �̰��� Visual C 2005��
	end = t + strlen(t) - 1;
	while (end != t && *end == ' ') end--;
	*(end + 1) = '\0';
	s = t;

	return s;
}
// ���ڿ� ���� ���鹮�� ���� �Լ�
char* ltrim(char *s) {
	char* begin;
	begin = s;

	while (*begin != '\0') {
		if (*begin == ' ')
			begin++;
		else {
			s = begin;
			break;
		}
	}

	return s;
}


// ���ڿ� �յ� ���� ��� ���� �Լ�
char* trim(char *s) {
	return rtrim(ltrim(s));
}
void writefile (D_Link *head){
	D_Link *temp=head;
	FILE *txt;
	txt = fopen("datalist.txt","w");
	if(txt==NULL){
		message("������ �߻��Ͽ����ϴ�.                     ������");
		return;
	}
	while(temp != NULL){
		fprintf(txt,"%s | %s | %d",temp->date,temp->todo,temp->progress);
		temp=temp->right;
		if(temp != NULL) fprintf(txt,"\n");
		else break;
	}
	fclose(txt);
}
void readfile(D_Link **list)
{
	char line[300] = "";
	char *ptr;
	int i;
	D_Link data;

	// ���� ������� ���� ����� �ݴϴ�.
	FILE *fp = fopen("datalist.txt", "a+");

	// ������ ���� �ƴ϶��
	while(!feof(fp))
	{
		i=0;
		fgets(line, 300,fp);
		//printf("%s",line);
		ptr = strtok(line, "|");
		if(ptr == NULL || ptr == "\n") break;
		while (ptr != NULL)
		{
			switch (i)
			{
			case 0:
				strcpy(data.date, trim(ptr));
				break;
			case 1:
				strcpy(data.todo, trim(ptr));
				break;
			case 2:
				data.progress = atoi(ptr);
				break;
			}
			ptr = strtok(NULL, "|");
			i++;
		}
		insert(list, data.date, data.todo, data.progress);
	}

	fclose(fp);
}
//����Ʈ �� �ڿ� ����
void insert(D_Link **head,char date[8], char todo[255], int prc) 
{
	D_Link *new_node = create(date, todo, prc);

	if(*head == NULL)
	{
		(*head) = new_node;
		(*head)->left = new_node;
		(*head)->right = NULL;
	}
	else
	{
		(*head)->left->right = new_node;
		new_node->left = (*head)->left;
		(*head)->left = new_node;
		new_node->right = NULL;
	}
}
void Display(D_Link *head){
	D_Link *temp=head;
	if (head != NULL)
	{
		system("cls");
		while (temp != NULL){
			printf("             ___        ___        ___        ___\n");
			printf("     ��������   ��������   ��������   ��������   ��������\n");
			printf("     ��      ---        ---        ---        ---      ����\n");
			printf("     ��                  ��        ��                  ������\n");
			printf("     �� ���������������������������������������������� ������\n");
			printf("     �� ������ : %s\n", temp->date);
			printf("     �� ���������������������������������������������� ������\n");
			printf("     �� ��  �� : %s\n", temp->todo);
			printf("     �� ���������������������������������������������� ������\n");
			switch (temp->progress){
			case 0:
				printf("     �� ������ �Դϴ�.                                 ������\n");
				printf("     �� ���������������������������������������������� ������\n");
				printf("     ��                                                ������\n");
				break;
			case 1:
				printf("     �� ������ �Դϴ�.                                 ������\n");
				printf("     �� ���������������������������������������������� ������\n");
				printf("     ��                                                ������\n");
				break;
			case 2:
				printf("     �� �Ϸ�� �� �� �Դϴ�.                           ������\n");
				printf("     �� ���������������������������������������������� ������\n");
				printf("     ��                                                ������\n");
				break;
			}
			temp = temp->right;
			printf("     �� ���������������������������������������������� ������\n");
			printf("     ��                                                ������\n");
			printf("     �� ���������������������������������������������� ������\n");
			printf("     ��                                                ������\n");
			printf("     ��������������������������������������������������������\n");
			printf("      �� ������������������������릥��\n");
			printf("         ����������������������������������������������������\n");
		}
	}
	else
	{
		message("������ ������ϴ�.                         ������");
		return;
	}
	printf("Press any key to quit...");
	while (1)
	{
		getch();
		return;
	}
}
D_Link *Delete(D_Link *head,D_Link *position){
	D_Link *temp=NULL;
	if(position==NULL){
		message("������ �߻��Ͽ����ϴ�.                     ������");
		return;
	}
	else{
		if(head==position){ // ���� ��尡 ��� �ϰ��
			if(head->right != NULL){ //��尡 ����� �ϳ��� �ƴ� ���
				temp=head->right;
				temp->left=head->left;
			}
			free(position);
			return temp;
		}
		else if(position->right==NULL){ // ��� �� �� ����
			head->left = position->left;
			position->left->right = NULL;
			temp = head;
		}
		else { // ��� �߰� ����
			position->right->left=position->left;
			position->left->right=position->right;
			temp=head;
		}
		free(position);
	}
	return temp;
}
D_Link *cmpcpy(D_Link *dest, D_Link *src)
{
	int del;
	D_Link *head1 = dest, *head2 = src;
	D_Link *tmp=NULL;
	while (dest != NULL && src != NULL)
	{
		if ((strcmp(dest->date, src->date) == 0) && (strcmp(dest->todo, src->todo) == 0)) // ���ڿ� ��
		{
			if ( src->del == 1) // del = 1�̸� ���� ���� ���� ���� ����
			{
				dest = Delete(head1, dest);
				src = Delete(head2, src);
				tmp = dest;
			}
			else if (dest->progress != src->progress) // ���൵�� ����Ʈ�� ����
			{
				dest->progress = src->progress;
				insert(&tmp, dest->date, dest->todo, dest->progress);
			}
			else if(tmp==NULL){ // �ƹ� �۾����� �ʰ� �׳� ���ý� ���� ��尪���� �ʱ�ȭ
				tmp=head1;
			}
			if(src != NULL)src = src->right;
		}
		if(dest != NULL) dest = dest->right;
	}
	return tmp;
}