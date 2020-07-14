// fprintf, fscanf 쓸거지만 일단은 stdout, stdin 인자로 줘서 콘솔 입출력 먼저해보기
#include <stdio.h>

int main() {
	char name[20];
	int stdnum;
	fprintf(stdout, "오마에오 나마에와: ");
	fscanf(stdin, "%s", name);
	fprintf(stdout, "오마에오 학번와: ");
	fscanf(stdin, "%d", &stdnum);

	fprintf(stdout,"이름: %s, 학번: %d\n", name, stdnum);
	return 0;
}