//1~100 이 저장된 10*10 행렬과, 대각선 요소 출력하기
#include <stdio.h>

int main() {
	int arr[10][10];
	int cols = sizeof(arr) / sizeof(arr[0]);
	int cnt = 1;

	puts("-배열의 요소-");
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = cnt++;
			printf("%3d", arr[i][j]);
		}
		puts("");
	}
	
	printf("\n배열의 대각선 요소: ");
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < cols; j++) {
			if(i == j)
				printf("%-3d", arr[i][j]);
		}
	}
	printf("\n\n");

	return 0;
}