// 2차원 포인터
#include <stdio.h>

int main() {
	int num1 = 10;
	int* ip = &num1;
	int** ipp = &ip;

	printf("%d\n", **ipp);

	return 0;
}