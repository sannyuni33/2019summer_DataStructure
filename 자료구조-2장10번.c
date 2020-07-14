// 문자열 입력받아서 대문자는 소문자로, 소문자는 대문자로 변환해서 출력하기 
/* 20.07.07 리뷰: isupper, islower가 알파벳이 아닌 문자를 인자로 받으면
런타임 에러가 떠버림. 이 함수를 호출하기 전에 알파벳인지 아닌지의 여부체크 필요.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	char* str = (char*)malloc(200);
	int slength;
	printf("문자열 입려꾸~~~ : ");
	gets(str);
	slength = strlen(str);

	for (int i = 0; i < slength; i++) {
		if (isupper(str[i]) != 0)
			str[i] = tolower(str[i]);
		else if (islower(str[i]) != 0)
			str[i] = toupper(str[i]);
		else
			continue;
	}
	printf("변환된 문자열: %s\n", str);
	free(str);
	return 0;
}