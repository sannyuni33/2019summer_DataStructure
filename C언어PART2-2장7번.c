// 두 개의 문자열이 같은지 비교하기
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myStrcmp(char* w1, char* w2);

int main() {
	char* word1 = (char*)malloc(100);
	char* word2 = (char*)malloc(100);
	printf("문자열을 입력하슈: ");
	scanf("%s", word1);
	printf("문자열을 또 입력하슈: ");
	scanf("%s", word2);

	if (myStrcmp(word1, word2) == 0)
		printf("두 문자열은 같은 문자열입니다람쥐\n");
	else
		printf("두 문자열은 다른 문자열입니다람쥐\n");

	free(word1);
	free(word2);
	return 0;
}

// 07.12 리뷰 : 그냥 return strcmp(w1, w2); 해두 되겠따
int myStrcmp(char* w1, char* w2) {
	if (strcmp(w1, w2) == 0) 
		return 0;
	else
		return -1;
}