/* 배열 이름을 포인터변수에 저장하고 
함수에 인자로 전달해주기
*/
#include <stdio.h>

void ftn(int(*p)[3], int rows, int cols);

int main() {
	int arr[][3] = { 1,2,3,4,5,6 };
	int(*p)[3] = arr;
	ftn(p, 2, 3);
	return 0;
}

void ftn(int(*p)[3], int rows, int cols) {
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++)
			printf("arr[%d][%d] = %d ", i, j, p[i][j]);
		puts("");
	}
}