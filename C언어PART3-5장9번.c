// 문자열을 저장한 void형 포인터를 전달받아 출력하는 함수 정의하기
#include <stdio.h>

void voidPrint(void* vp);

int main() {
	void* vpoint = "Hello World!";
	voidPrint(vpoint);
	return 0;
}

void voidPrint(void* vp) {
	printf("%s\n", (char*)vp);
}