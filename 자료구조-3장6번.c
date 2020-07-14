// 파일에서 읽어온 수만큼 파일에서 읽어온 문자열 출력하기
#include <stdio.h>

int main() {
	FILE* stream = fopen("animal.txt", "r");
	int repeat;
	char anim[10];
	while (!feof(stream)) {
		fscanf(stream, "%d", &repeat);
		fscanf(stream, "%s", anim);
		for (int i = 0; i < repeat; i++)
			printf("%s ", anim);
		puts("");
	}
	fclose(stream);
	return 0;
}