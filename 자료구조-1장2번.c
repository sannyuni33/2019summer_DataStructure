//구조체의 멤버변수 직접 입력하기
#include <stdio.h>

typedef struct student {
	char stdno[11];
	char stdname[30];
	char birth[5];
}STUDENT;

int main() {
	STUDENT unknown;
	printf("학번을 입력하슈: ");
	scanf("%s",unknown.stdno);
	printf("영어이름이 뭐유: ");
	scanf("%s",unknown.stdname);
	printf("몇년생이슈: ");
	scanf("%s",unknown.birth);

	printf("%s년생 %s의 학번은 %s입니다.\n", unknown.birth, unknown.stdname, unknown.stdno);

	return 0;
}