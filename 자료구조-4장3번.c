// 입력횟수 정하고, 입력된 수들의 총합과 평균구하기
#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, n, sum = 0;
	int* arr;
	double avg;
	printf("정수를 입력하세기: ");
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	
	for (i = 0; i < n; i++) {
		printf("숫자 입력쿠: ");
		scanf("%d", arr + i);
		sum += *(arr + i);
	}
	printf("입력한 숫자:");
	for (i = 0; i < n; i++)
		printf(" %d ", *(arr + i));
	avg = (double)sum / n;
	printf("\n총합: %d, 평균: %.1lf\n", sum, avg);
	free(arr);
	return 0;
}