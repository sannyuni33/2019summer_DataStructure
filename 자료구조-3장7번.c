// 파일에서 문자열 읽고, 기준에 따라 분류해서 각각 다른 파일에 출력하기
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	FILE* stream = fopen("fruitList.txt", "r");
	FILE* fp1 = fopen("berry.txt", "w");
	FILE* fp2 = fopen("noneberry.txt", "w");
	char fruit[15] = { NULL };
	int flen, esc = 0;

	while (!feof(stream)) {
		fscanf(stream, "%s", fruit);
		flen = strlen(fruit);
		for (int i = 0; i < flen ; i++) {
			if (strcmp(fruit + i, "berry") == 0) { // 07.12 리뷰 : 이 지랄 떨지말고 걍 strstr하면 끝.
				fprintf(fp1, "%s\n", fruit);
				esc = 1;
				break; //berry라는 글자가 포함되면 berry.txt에 출력하고 반복문 탈출
			}
			else
				esc = 0;
		}
		if (esc != 1) {
			fprintf(fp2, "%s\n", fruit);
			esc = 0;
		}
	}

	fclose(stream);
	fclose(fp1);
	fclose(fp2);
	system("notepad.exe berry.txt");
	system("notepad.exe noneberry.txt");
	return 0;
}