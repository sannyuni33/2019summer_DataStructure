// 구조체 포인터를 인자로 받아 구조체에 접근하는 함수 정의하기
#include <stdio.h>

typedef struct pos {
	int x, y;
}POS;

POS input(POS*);

int main() {
	POS var1;
	POS* p = &var1;

	var1 = input(p);
	printf("결과: x = %d, y = %d\n", var1.x, var1.y);

	return 0;
}

POS input(POS* pp) {
	printf("x값을 입력하삼: ");
	scanf("%d", &pp->x);
	printf("y값을 입력하삼: ");
	scanf("%d", &pp->y);

	return *pp;
}