// 함숫 인자에 변수 주소값 전달해서 변수값 조작하기
#include <stdio.h>

void sum(int a, int b, int* p);

int main() {
	int a = 10, b = 20, res;
	sum(a, b, &res);
	printf("res = %d\n", res);

	return 0;
}

void sum(int a, int b, int* p) {
	*p = a + b;
}