// 문자열에서 단어 검색, 시작하는 주소부터 출력하기
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char* script = {"Just a young gun with a quick fuse I was uptight wanna let loose I was dreaming of bigger things And wanna leave my own life behind Not a yes sir not a follower Fit the box fit the mold Have a seat in the foyer take a number I was lightning before the thunder"};
	char input[20];
	char* res;
	printf("검색 단어 입력:");
	gets(input);
	res = strstr(script, input);


	if ( res != NULL) {
		printf("문자열의 시작 위치: %#p\n", res);
		puts(res);
	}
	else
		puts("없어. 안돼. 돌아가");

	return 0;
}