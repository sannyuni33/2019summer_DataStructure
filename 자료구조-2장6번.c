// 입력받은 문자열 그대로 출력...... 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char* sentence = (char*)malloc(200);
	printf("문장 입력: ");
	gets(sentence);
	printf("입력한 문장: ");
	puts(sentence);

	free(sentence);
	return 0;
}