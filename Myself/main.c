#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "contact.h"
void menu()
{
	printf("******************************************\n");
	printf("******  1.add          2.del        ******\n");
	printf("******  3.search       4.modify     ******\n");
	printf("******  5.sort         6.show       ******\n");
	printf("******  7.clear        0.exit       ******\n");
	printf("******************************************\n");

}
int main()
{
	int input = 0;
	Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("ÇëÑ¡Ôñ:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			AddContact(&con);
			break;
		case 2:
			DeleteContact(&con);
			break;
		case 3:
			Searchcontact(&con);
			break;
		case 4:
			Modifycontact(&con);
			break;
		case 5:
			SortByName(&con);
			break;
		case 6:
			ShowContact(&con);
			break;
		case 7:
			ClearContact(&con);
			break;
		case 0:
			SaveContact(&con);
			DestoryContact(&con);
			printf("ÍË³ö\n");
			break;
		default:
			printf("Ñ¡Ôñ´íÎó\n");
			break;
		}
	} while (input);
	return 0;
}
