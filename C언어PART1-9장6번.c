// 초기 미생물 수 입력받으면 나중엔 몇 마리 되는지 계산
#include <stdio.h>

int divideCell(int mcb, int mon);

int main() {
	int microbe, result;
	int mon = 1;
	printf("초기 미생물의 개체 수를 입력하시라요: ");
	scanf("%d", &microbe);

	result = divideCell(microbe,mon);

	printf("최초: %d마리, 최종: %d마리\n", microbe, result);

	return 0;
}

int divideCell(int mcb, int mon) {
	int divided = mcb;
	if (mon > 11)
		return divided;
	divided *= 2;
	divideCell(divided,mon+1);
}