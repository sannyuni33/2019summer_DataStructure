// 숫자 입력 횟수를 직접 정하고 입력 받은 수들의 합 구하기
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, sum = 0;
	int* arr;
	printf("원하는 입력 개수: ");
	scanf("%d", &n);
	arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++) {
		printf("%d번째 숫자: ",i+1);
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	printf("입력 값의 총합: %d\n", sum);
	free(arr);
	return 0;
}