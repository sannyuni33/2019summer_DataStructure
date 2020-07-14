// 입력한 문자열을 그대로 출력
// string 헤더파일을 사용, 포인터를 사용해 문자열 요소에 접근
#include <stdio.h>
#include <string.h>

int main() {
	char arr[12];
	char* cp = arr;
	int length;
	printf("문자열 입력(공백 불가...마 사우나): ");
	scanf("%s", arr);
	getchar();
	length = strlen(arr);

	for (int i = 0; i < length; i++) // 07.12 리뷰 : 이 넘도 %s하면 끝.. 아니 걍 puts(arr)을 하셈 
		printf("%c", *(cp+i));
	puts("");

	return 0;
}