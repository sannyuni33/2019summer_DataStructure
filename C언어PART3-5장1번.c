// 배열을 초기화 안하면 쓰레기값이 저장되있다는걸 보여주는...코드
#include <stdio.h>

void init(int* p, int num);

int main() {
	int arr[3];
	int i;
	
	printf("배열의 초기화 전: ");
	for (i = 0; i < 3; i++)
		printf("arr[%d] = %d  ", i+1, arr[i]);

	init(arr, sizeof(arr) / sizeof(int));

	printf("\n\n배열의 초기화: ");
	for (i = 0; i < 3; i++)
		printf("arr[%d] = %d  ", i + 1, arr[i]);
	puts("");
	return 0;
}

void init(int* p, int num) {
	for (int i = 0; i < num; i++)
		p[i] = 0;
}