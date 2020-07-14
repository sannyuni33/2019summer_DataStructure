// 9개 요소를 입력받아 3*3 행렬형태로 출력하기
#include <stdio.h>

int main() {
	int arr[3][3];
	int i, j;
	int(*ip)[3] = arr;

	printf("정수 입력 : ");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			scanf("%d", &arr[i][j]);
	}

	printf("\n출력\n");
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++)
			printf("%3d", ip[i][j]);
		puts("");
	}

	return 0;
}