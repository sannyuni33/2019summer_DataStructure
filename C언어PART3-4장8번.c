/* 메뉴선택 메시지 출력, 메뉴 입력, 입력에 따른 메시지 출력 무한반복하는 프로그램
20.07.07 리뷰: 역시나 메뉴입력할때 숫자말고 딴거쓰면 맛탱이감.
입력의 형식이 정해져 있는 코드는 무조건 scanf() != 0 이 놈이 필요함.
*/
#include <stdio.h>

void printMenu(char* menu, int size);

int main() {
	int num;
	char menu[][50] = { "========== MENU ==========\n","1. 1번 메뉴입니당.\n",
	"2. 2번 메뉴입니다람쥐.\n","0. 프로그램 종료\n\n" };
	int size = sizeof(menu) / sizeof(menu[0]);

	while (1) {
		printMenu(menu, size);
		printf("메뉴 번호를 입력하앍: ");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			printf("\n1번 메뉴를 실행하려다가 말았습니다.\n\n");
			break;
		case 2:
			printf("\n2번 메뉴를 실행하려면 0을 입력해보셈\n\n");
			break;
		case 0:
			printf("\n끄지삼\n\n");
			return 0;
		default:
			printf("\n뭐하삼\n\n");
			break;
		}
	}
}

void printMenu(char* menu, int size) {
	char(*cp)[50] = menu;
	for (int i = 0; i < size; i++)
		printf("%s", cp[i]);
}