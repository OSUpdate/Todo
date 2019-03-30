#include "teamheader.h"

D_Link *goNext(D_Link *node){
	D_Link *temp=node->right;
	if(temp==NULL){
		message("데이터가 존재하지 않습니다.                │∥│");
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
		message("데이터가 존재하지 않습니다.                │∥│");
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
// 문자열 우측 공백문자 삭제 함수
char *rtrim(char* s) {
	char t[4000];
	char *end;

	// Visual C 2003 이하에서는
	// strcpy(t, s);
	// 이렇게 해야 함
	strcpy(t, s); // 이것은 Visual C 2005용
	end = t + strlen(t) - 1;
	while (end != t && *end == ' ') end--;
	*(end + 1) = '\0';
	s = t;

	return s;
}
// 문자열 좌측 공백문자 삭제 함수
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


// 문자열 앞뒤 공백 모두 삭제 함수
char* trim(char *s) {
	return rtrim(ltrim(s));
}
void writefile (D_Link *head){
	D_Link *temp=head;
	FILE *txt;
	txt = fopen("datalist.txt","w");
	if(txt==NULL){
		message("오류가 발생하였습니다.                     │∥│");
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

	// 파일 미존재시 새로 만들어 줍니다.
	FILE *fp = fopen("datalist.txt", "a+");

	// 파일의 끝이 아니라면
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
//리스트 맨 뒤에 삽입
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
			printf("     ┌──＜   ＞──＜   ＞──＜   ＞──＜   ＞──┐\n");
			printf("     │      ---        ---        ---        ---      │＼\n");
			printf("     │                  일        정                  │∥│\n");
			printf("     │ ─────────────────────── │∥│\n");
			printf("     │ 종료일 : %s\n", temp->date);
			printf("     │ ─────────────────────── │∥│\n");
			printf("     │ 일  정 : %s\n", temp->todo);
			printf("     │ ─────────────────────── │∥│\n");
			switch (temp->progress){
			case 0:
				printf("     │ 진행전 입니다.                                 │∥│\n");
				printf("     │ ─────────────────────── │∥│\n");
				printf("     │                                                │∥│\n");
				break;
			case 1:
				printf("     │ 진행중 입니다.                                 │∥│\n");
				printf("     │ ─────────────────────── │∥│\n");
				printf("     │                                                │∥│\n");
				break;
			case 2:
				printf("     │ 완료된 할 일 입니다.                           │∥│\n");
				printf("     │ ─────────────────────── │∥│\n");
				printf("     │                                                │∥│\n");
				break;
			}
			temp = temp->right;
			printf("     │ ─────────────────────── │∥│\n");
			printf("     │                                                │∥│\n");
			printf("     │ ─────────────────────── │∥│\n");
			printf("     │                                                │∥│\n");
			printf("     └────────────────────────┘∥│\n");
			printf("      ＼ 〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓┘│\n");
			printf("         ─────────────────────────┘\n");
		}
	}
	else
	{
		message("파일이 비었습니다.                         │∥│");
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
		message("오류가 발생하였습니다.                     │∥│");
		return;
	}
	else{
		if(head==position){ // 삭제 노드가 헤드 일경우
			if(head->right != NULL){ //노드가 헤드노드 하나가 아닐 경우
				temp=head->right;
				temp->left=head->left;
			}
			free(position);
			return temp;
		}
		else if(position->right==NULL){ // 노드 맨 뒤 삭제
			head->left = position->left;
			position->left->right = NULL;
			temp = head;
		}
		else { // 노드 중간 삭제
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
		if ((strcmp(dest->date, src->date) == 0) && (strcmp(dest->todo, src->todo) == 0)) // 문자열 비교
		{
			if ( src->del == 1) // del = 1이면 같은 값을 가진 노드들 삭제
			{
				dest = Delete(head1, dest);
				src = Delete(head2, src);
				tmp = dest;
			}
			else if (dest->progress != src->progress) // 진행도를 리스트에 적용
			{
				dest->progress = src->progress;
				insert(&tmp, dest->date, dest->todo, dest->progress);
			}
			else if(tmp==NULL){ // 아무 작업하지 않고 그냥 나올시 원래 헤드값으로 초기화
				tmp=head1;
			}
			if(src != NULL)src = src->right;
		}
		if(dest != NULL) dest = dest->right;
	}
	return tmp;
}