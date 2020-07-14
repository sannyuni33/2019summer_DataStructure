//문자열의 일부분만 출력
#include <stdio.h>
#include <string.h>

int main() {
	char str[100] = { "strawberry" };
	char* sp = str;
	int s_len = strlen(str);
	for (int i = 5; i < s_len; i++) // 07.12 리뷰 :printf("%s\n",sp+5)하세요 그냥
		printf("%c", *(sp + i));
	puts("");
	return 0;
}