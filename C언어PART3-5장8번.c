// 사용자가 찾으려는 배열 요소의 주소를 반환하는 함수 정의하기
#include <stdio.h>

int* findAry(int* ary, int size, int num);

int main() {
	int num, ary[5] = { 1,2,3,4,5 };
	int* ip;
	printf("찾을 숫자를 입력하앍: ");
	scanf("%d", &num);

	ip = findAry(ary, 5, num);

	if (ip == NULL)
		printf("그런 숫자는 없습니다 찡긋\n");
	else
		printf("%d\n", *ip);

	return 0;
}

int* findAry(int* ary, int size, int num) {
	for (int i = 0; i < size; i++) {
		if (ary[i] == num)
			return &ary[i];
	}
	return NULL;
}