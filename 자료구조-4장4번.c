/* 2차원 포인터 변수와 동적할당을 활용해서 2차원배열(행렬)을 동적할당하고,
요소를 출력해준다음 메모리 해제까지 하기. dg의 용도는 대각선요소 저장임.
얘를 따로 선언해준 이유는... 행렬을 구성하는 과정에서 대각선요소도 같이 찾아내려구 한거
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, i, j, cnt=1;
	int** matrix;
	int* dg;

	printf("배열의 크기를 입력하세기! : ");
	scanf("%d", &n);
	matrix = (int**)malloc(sizeof(int*)*n);
	dg = (int*)malloc(sizeof(int)*n);

	for (i = 0; i < n; i++){
		matrix[i] = (int*)malloc(sizeof(int)*n);
		for (j = 0; j < n; j++) {
			matrix[i][j] = cnt;
			if (i == j)
				dg[i] = cnt;
			cnt++;
		}
	}

	printf("\n-배열의요소-\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%2d  ", matrix[i][j]);
		puts("");
	}

	printf("\n배열의 대각선 요소:");
	for (i = 0; i < n; i++)
		printf("%2d  ", dg[i]);
	puts("");

	for (j = 0; j < n; j++)
		free(matrix[j]);
	free(matrix);
	free(dg);
	
	return 0;
}