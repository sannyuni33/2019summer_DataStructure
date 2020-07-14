//string.h 의 함수들을 이용해 메뉴 입력받고 메시지 출력하기
#include <stdio.h>
#include <string.h>

int main() {
	char menu[5];
	int imenu;
	while (1) {
		puts("");
		puts("============ MENU ============");
		printf("1. 두 수의 덧셈.\n2. 두 수의 곱셈.\n메뉴 번호를 입력하세요: ");
		gets(menu);
		if (strcmp(menu, "exit") == 0) {
			puts("종료띠");
			return 0;
		}

		imenu = atoi(menu);
		switch (imenu)
		{
		case 1:
			puts("두 수의 덧셈을 수행할려다가 마는 메뉴입니다.");
			break;
		case 2:
			puts("두 수의 곱셈을 수행하기 싫어하는 메뉴입니다.");
			break;
		default:
			puts("다시 입력하시라요 동무");
			break;
		}
	}
}