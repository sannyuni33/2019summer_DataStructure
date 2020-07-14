// 문자열 입력받고, 문자열 안의 대문자 소문자 개수 카운팅해서 출력하기
// ctype.h 의 isupper(), islower() 사용.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	char* str = (char*)malloc(200);
	int slength;
	int cnt_upper = 0, cnt_lower = 0;
	printf("문자열 입려쿠 : ");
	gets(str);
	slength = strlen(str);
	printf("입력한 문자열 : %s\n", str);
	
	for (int i = 0; i < slength; i++) {
		if (isupper(str[i]) != 0)
			cnt_upper++;
		else if (islower(str[i]) != 0)
			cnt_lower++;
		else
			continue;
	}

	printf("대문자의 개수: %d\n소문자의 개수: %d\n", cnt_upper, cnt_lower);

	free(str);
	return 0;
}