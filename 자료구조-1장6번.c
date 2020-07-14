// 구조체 선언 후 멤버변수 입력받아서 저장하기
#include <stdio.h>

typedef struct me {
	char name[20];
	int stdnum;
	int jjam;
}ME;

int main() {
	ME m;
	printf("이름 : ");
	scanf("%s", &m.name);
	printf("학번 : ");
	scanf("%d", &m.stdnum);
	printf("학년 : ");
	scanf("%d", &m.jjam);

	printf("%d %s %d학년.\n", m.stdnum, m.name, m.jjam);
	return 0;
}
