/* 배열 초기화 먼저 해주고 배열의 요소 입력받아서 출력하는 코드인데...
왜 요소 입력은 한 번만 되게 해놨는지 궁금하네
*/

#include <stdio.h>

void init(int* p, int num);
void change(int* p, int index, int num);

int main() {
	int arr[3];
	int i, id, n;

	init(arr, sizeof(arr) / sizeof(int));

	printf("1. 배열의 초기화: ");
	for (i = 0; i < 3; i++)
		printf("arr[%d] = %d  ", i + 1, arr[i]);
	
	printf("\n2. 배열의 값 입력\n배열의 인덱스: ");
	scanf("%d", &id);
	printf("배열의 값: ");
	scanf("%d", &n);
	change(arr, id, n);

	printf("3. 결과 출력: ");
	for(i=0;i<3;i++)
		printf("arr[%d] = %d  ", i + 1, arr[i]);
	puts("");

	return 0;
}

void init(int* p, int num) {
	for (int i = 0; i < num; i++)
		p[i] = 0;
}

void change(int* p, int index, int num) {
	p[index] = num;
}