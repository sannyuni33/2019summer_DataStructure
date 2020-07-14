//우물 높이 입력하면 달팽이가 탈출하는데 걸린 날짜 나옴
#include <stdio.h>

int main() {
	int height;
	int snail = 0;
	int day = 0;
	printf("우물의 높이를 입력하세여(cm) : ");
	scanf("%d", &height);

	while (1) {
		snail += 30;
		day++;
		if (snail >= height)
			break;
		snail -= 10;
	}
	printf("\n우리의 달팽이가 탈출했어여!\n우물 탈출에 걸린 날짜 : %d일\n", day);

	return 0;
}