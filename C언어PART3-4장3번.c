// 입력받은 문자열의 a를 ?로 바꿔서 출력
#include <stdio.h>
#include <string.h>

int main() {
	char arr[12];
	char* cp = arr;
	int length, i;
	printf("문자열 입력(공백 불가...마 사우나): ");
	scanf("%s", arr);
	getchar();
	length = strlen(arr);

	printf("문자열 출력: ");
	for (i = 0; i < length; i++) {
		printf("%c", *(cp + i));
		if (*(cp + i) == 'a')
			*(cp + i) = '?';
	}

	printf("\n\n문자 변경(a->?): ");
	for (i = 0; i < length; i++)
		printf("%c", *(cp + i));
	puts("");
	return 0;
}