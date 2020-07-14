// 입력받는 함수, 출력하는 함수 정의하기
#include <stdio.h>

void inputAry(int* ary, int n);
void printAry(int* ary, int n);

int main() {
	int ary[3];

	inputAry(ary, sizeof(ary) / sizeof(ary[0]));
	printAry(ary, sizeof(ary) / sizeof(ary[0]));

	return 0;
}

void inputAry(int* ary, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d 번째 요소를 입력하세요요요용: ",i);
		scanf("%d", &ary[i]);
	}
}

void printAry(int* ary, int n) {
	printf("\n\n입력받은 수: ");
	for (int i = 0; i < n; i++)
		printf("%d ",ary[i]);
}
