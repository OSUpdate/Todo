#include "teamheader.h"

void message(char msg[255])
{
	system("cls");
	printf("             ___        ___        ___        ___\n");
	printf("     忙式式ˉ   ˇ式式ˉ   ˇ式式ˉ   ˇ式式ˉ   ˇ式式忖\n");
	printf("     弛      ---        ---        ---        ---      弛′\n");
	printf("     弛                                                弛‵弛\n");
	printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
	printf("     弛     %s\n",msg);
	printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
	printf("     弛                                                弛‵弛\n");
	printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
	printf("     弛                                                弛‵弛\n");
	printf("     戌式式式式式式式式式式式式式式式式式式式式式式式式戎‵弛\n");
	printf("      ′ ㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑戎弛\n");
	printf("         式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf("Press any key to quit...");
	while (1)
	{
		getch();
		break;
	}
}

void showData(int prc, char date[8], char todo[255])
{
	system("cls");
	printf("             ___        ___        ___        ___\n");
	printf("     忙式式ˉ   ˇ式式ˉ   ˇ式式ˉ   ˇ式式ˉ   ˇ式式忖\n");
	printf("     弛      ---        ---        ---        ---      弛′\n");
	printf("     弛                                                弛‵弛\n");
	printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
	printf("     弛 謙猿橾 : %s\n", date);
	printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
	printf("     弛 橾  薑 : %s\n", todo);
	printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
	switch (prc){
	case 0:
		printf("     弛 霞ч瞪 殮棲棻.                                 弛‵弛\n");
		printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
		printf("     弛                                                弛‵弛\n");
		printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
		printf("     弛                                                弛‵弛\n");
		printf("     戌式式式式式式式式式式式式式式式式式式式式式式式式戎‵弛\n");
		printf("      ′ ㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑戎弛\n");
		printf("         式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		break;
	case 1:
		printf("     弛 霞ч醞 殮棲棻.                                 弛‵弛\n");
		printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
		printf("     弛                                                弛‵弛\n");
		printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
		printf("     弛                                                弛‵弛\n");
		printf("     戌式式式式式式式式式式式式式式式式式式式式式式式式戎‵弛\n");
		printf("      ′ ㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑戎弛\n");
		printf("         式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		break;
	case 2:
		printf("     弛 諫猿脹 й 橾 殮棲棻.                           弛‵弛\n");
		printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
		printf("     弛                                                弛‵弛\n");
		printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
		printf("     弛                                                弛‵弛\n");
		printf("     戌式式式式式式式式式式式式式式式式式式式式式式式式戎‵弛\n");
		printf("      ′ ㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑戎弛\n");
		printf("         式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		break;
	}

	printf("\n   ⊥ : Next / ∠ : Prev / d : Delete / c : Change Progress / esc : Quit\n");
}



void management(D_Link *head){
	int progress=0;
	unsigned int input;
	D_Link *temp1=head;
	D_Link *temp2;
	if(head==NULL){
		message("臢蝶お だ橾檜 綠歷蝗棲棻.                  弛‵弛");
	} 
	else{
		// 酈殮溘擊 嫡嬴 ч翕 霞ч
		while (1){
			showData(temp1->progress, temp1->date, temp1->todo);
			input=getch();

			switch(input){
			case LEFT: // 豭薹 寞щ酈 殮溘衛
				temp2 = goPrev(temp1);
				temp1=temp2;
				break;
			case RIGHT: //螃艇褶 寞щ酈 殮溘衛
				temp2=goNext(temp1);
				temp1=temp2;
				break;
			case DELETE: //d 幗が 殮溘衛
				temp1->del=1;
				if(temp1==NULL){
					message("п渡 橾薑擎 餉薯й熱 橈蝗棲棻.             弛‵弛");
					break;
				}
				else{
					message("п渡 橾薑檜 餉薯腎歷蝗棲棻.                弛‵弛");
					goto go;
					break;
				}			
				break;
			case ESC: // esc 幗が 殮溘衛
				goto go;
				break;
			case CHANGE: // c 幗が 殮溘衛
				printf("\n   橾曖 霞ч紫蒂 熱薑 м棲棻. \n");
				printf("   1 : 霞ч瞪 / 2 : 霞ч醞 / 3 : 諫猿\n");
				printf("   >> ");
				scanf("%d",&progress);
				switch(progress){
					case 1:
						temp1->progress=0;
						break;
					case 2:
						temp1->progress=1;
						break;
					case 3:
						temp1->progress=2;
						break;
					default:
						message("澀跤脹 高檜 殮溘腎歷蝗棲棻.                弛‵弛");
						break;
				}
				break;
			}
		}
	}
	go:;
}
void MainMenu()
{
	printf("             ___        ___        ___        ___\n");
	printf("     忙式式ˉ   ˇ式式ˉ   ˇ式式ˉ   ˇ式式ˉ   ˇ式式忖\n");
	printf("     弛      ---        ---        ---        ---      弛′\n");
	printf("     弛                                                弛‵弛\n");
	printf("     弛      濠猿掘褻 撲啗Щ煎薛お ˉ03ぜˇ            弛‵弛\n");
	printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
	printf("     弛      橾薑 婦葬 Щ煎斜極                        弛‵弛\n");
	printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
	printf("     弛      1. 橾薑 婦葬                              弛‵弛\n");
	printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
	printf("     弛      2. 橾薑 蹺陛                              弛‵弛\n");
	printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
	printf("     弛      3. 瞪羹 橾薑                              弛‵弛\n");
	printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
	printf("     弛      4. ぜ錳 模偃                              弛‵弛\n");
	printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
	printf("     弛      5. Щ煎斜極 謙猿                          弛‵弛\n");
	printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
	printf("     弛                                                弛‵弛\n");
	printf("     戌式式式式式式式式式式式式式式式式式式式式式式式式戎‵弛\n");
	printf("      ′ ㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑戎弛\n");
	printf("         式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
}
void Makers ()
{
		printf("             ___        ___        ___        ___\n");
		printf("     忙式式ˉ   ˇ式式ˉ   ˇ式式ˉ   ˇ式式ˉ   ˇ式式忖\n");
		printf("     弛      ---        ---        ---        ---      弛′\n");
		printf("     弛                                                弛‵弛\n");
		printf("     弛      濠猿掘褻 撲啗Щ煎薛お ˉ03ぜˇ            弛‵弛\n");
		printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
		printf("     弛      ぜ濰 : и撩霞  2013150041                 弛‵弛\n");
		printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
		printf("     弛      ぜ錳 : 梯翱遵  2013150004                 弛‵弛\n");
		printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
		printf("     弛             檜翕⑷  2013152025                 弛‵弛\n");
		printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
		printf("     弛             梯辨衝  2013150005                 弛‵弛\n");
		printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
		printf("     弛                                                弛‵弛\n");
		printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛‵弛\n");
		printf("     弛                                                弛‵弛\n");
		printf("     戌式式式式式式式式式式式式式式式式式式式式式式式式戎‵弛\n");
		printf("      ′ ㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑㏑戎弛\n");
		printf("         式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		printf("Press any key to quit...");
		while (1)
		{
			getch();
			break;
		}
}

void main()
{
	int i;
	char date[8];
	char todo[255];
	D_Link *list = NULL;
	readfile(&list);

	while(1){
		system("cls");
		MainMenu();
		printf("     錳ж衛朝 詭景曖 廓�ㄧ� 殮溘п 輿撮蹂 ˇˇˇ ");
		scanf("%d",&i);
		switch(i){
		case 1:
			system("cls");
			list = order_today(list);
			break;
		case 2:
			system("cls");
			fflush(stdin);
			printf("             ___        ___        ___        ___\n");
			printf("     忙式式ˉ   ˇ式式ˉ   ˇ式式ˉ   ˇ式式ˉ   ˇ式式忖\n");
			printf("     弛      ---        ---        ---        ---      弛\n");
			printf("     弛                                                弛\n");
			puts("     弛     謙猿橾擊 殮溘п輿撮蹂.                     弛");
			printf("     弛     ");
			gets(date);
			fflush(stdin);
			printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛\n");
			puts("     弛     й 橾擊 殮溘п輿撮蹂.                      弛");
			printf("     弛     ");
			gets(todo);
			fflush(stdin);
			printf("     弛 式式式式式式式式式式式式式式式式式式式式式式式 弛\n");
			printf("     弛                                                弛\n");
			printf("     戌式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
			insert(&list,date,todo,0);
			break;
		case 3:
			Display(list);
			break;
		case 4:
			system("cls");
			Makers();
			break;
		case 5:
			writefile(list);
			exit(1);
			break;
		}
	}
}