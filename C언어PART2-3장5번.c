//포인터 사용법
#include <stdio.h>

void change(int* ip);

int main() {
	int num = 10;
	int* ip = &num;
	change(ip);

	return 0;
}

void change(int* ip) {
	*ip = 20;
	printf("%d\n", *ip);
}