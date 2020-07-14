// 파일에서 데이터 읽고, 콘솔에 출력하기 
#include <stdio.h>

int main() {
	FILE* stream = fopen("warning.txt", "r");
	char buffer[100];

	// 07.12 리뷰 : 어떤 메커니즘으로 돌아가는건지 다시 복습!
	while (!feof(stream)) {
		fgets(buffer,sizeof(buffer),stream);
		fputs(buffer, stdout);
	}
	puts("");
	fclose(stream);
	return 0;
}