//문자열 입력받아서 거꾸로 출력하기
//띄어쓰기 들어간 문장은 불가
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char* word = (char*)malloc(255);
	printf("문자열을 입력해보슈: ");
	scanf("%s", word);
	printf("뒤집은 문자열: ");
	for (int i = strlen(word); i >= 0; i--) {
		printf("%c", word[i]);
	}
	puts("");
	free(word);
	return 0;
}