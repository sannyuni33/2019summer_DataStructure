// 2차원 배열 주소, 포인터 이용하기
#include <stdio.h>

int main() {
	int arr[4];
	int* p = arr;
	int** pp = &p;
	int i;

	puts("[1. 주소 비교]");
	printf("배열의 주소 : ");
	for (i = 0; i < 4; i++)
		printf("&arr[%d] = %#p   ", i, &arr[i]);
	printf("\n1차원 포인터의 주소 : &p = %#p, 값 : *&p = %#p", &p, p);
	printf("\n2차원 포인터의 주소 : &pp = %#p, 값 : *&pp = %#p\n\n", &pp, pp);

	puts("[2. 1차원 포인터를 이용한 배열의 값 저장]");
	for (i = 0; i < 4; i++) {
		*(p + i) = i * 10;
		printf("&arr[%d] = %d   ", i, *(p+i));
	}
	printf("\n\n");
		
	puts("[3. 2차원 포인터를 이용한 배열의 값 출력]");
	for (i = 0; i < 4; i++)
		printf("&arr[%d] = %d   ", i, *(*pp+i));
	return 0;
}