//gets로 문자열 입력받고, strlen 만큼 반복 출력하기
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char* name = (char*)malloc(30);
	int nlength;
	printf("이름 입력: ");
	gets(name);
	nlength = strlen(name);

	puts("한 글자씩 출력:");
	for (int i = 0; i < nlength; i++)
		printf("%c\n", name[i]);

	free(name);
	return 0;
}