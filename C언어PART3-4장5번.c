// time 헤더와 rand를 이용해서 난수 생성하기
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ranInputAry(int* ary, int n);

int main() {
	srand((unsigned)time(NULL));
	
	int ary[5];
	int* ip = ary;
	int n = sizeof(ary) / sizeof(int);

	ranInputAry(ip, n);

	printf("랜덤 생성된 배열의 요소 : ");
	for (int i = 0; i < 5; i++)
		printf(" %3d", ary[i]);
	puts("");
	return 0;
}

void ranInputAry(int* ary, int n) {
	for (int i = 0; i < n; i++)
		*(ary + i) = rand() % 101;
}