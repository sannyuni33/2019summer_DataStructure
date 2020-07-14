// 2차원 포인터 사용법 익히기
#include <stdio.h>

int main() {
	int a[3] = { 0,0,0 };
	int* p = NULL;
	int **pp = NULL;

	pp = &p;
	p = a;
	for (int i = 0; i < 3; i++) 
		*(*pp + i) = 10 * (i + 1);
	printf("a[0]=%d, a[1]=%d, a[2]=%d\n", *(*pp + 0), *(*pp + 1), *(*pp + 2));

	return 0;
}