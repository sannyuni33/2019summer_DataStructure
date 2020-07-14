// 포인터로 구조체배열 접근하기
#include <stdio.h>

typedef struct city {
	int num;
	char station[10];
	struct city* link;
}CITY;

int main() {
	CITY line[4] = { {01,"Seoul",line+1},{ 02,"Daejeon",line + 2 },
				{ 03,"Daegu",line + 3 },{ 04,"Busan",NULL } };
	CITY* p = line;

	for (int i = 0; i < 4; i++)
		printf("%d번째 역: %s -> ",i+1,(p+i)->station);

	return 0;
}