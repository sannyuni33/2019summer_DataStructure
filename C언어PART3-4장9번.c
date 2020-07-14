/* 암호문을 입력하면 카이사르 암호법으로 해독하는 프로그램
20.07.07 리뷰: 이제서야 공백포함 문자열 입력받는 코드가 첫 등장..
scanf("%[^\n]s", 변수명) 과 같이 입력받으면, 개행문자를 제외한 모든 문자를
변수명 공간에 저장해뻐림
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char* secret=(char*)malloc(255);
	int scrlen;
	printf("암호문을 입력하ㅅ\n->");
	scanf("%[^\n]s", secret); // 요놈이 노다지임
	scrlen = strlen(secret);

	printf("\n해독된 암호문\n->");
	for (int i = 0; i < scrlen; i++) {
		if (secret[i] > 64 && secret[i] < 68)
			printf("%c", secret[i] + 23);
		else if (secret[i] == ' ')
			printf(" ");
		else
			printf("%c", secret[i] - 3);
	}
	puts("");
	free(secret);
	return 0;
}