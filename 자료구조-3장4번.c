// 파일에 출력하기
#include <stdio.h>

int main() {
	FILE* stream = fopen("hello.txt", "w");

	fprintf(stream, "Hello World!\n");

	fclose(stream);
	system("notepad.exe hello.txt");
	return 0;
}