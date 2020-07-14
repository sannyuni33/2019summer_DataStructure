// 중첩구조체 만들기.....
#include <stdio.h>

typedef struct me {
	char name[20];
	int stdnum;
	int jjam;
}ME;

typedef struct grade {
	int math;
	int eng;
}GRADE;

typedef struct student {
	ME m;
	GRADE grd;
}STUDENT;

int main() {
	STUDENT s;
	printf("이름 : ");
	scanf("%s", &s.m.name);
	printf("학번 : ");
	scanf("%d", &s.m.stdnum);
	printf("학년 : ");
	scanf("%d", &s.m.jjam);
	printf("수학점수: ");
	scanf("%d", &s.grd.math);
	printf("영어점수: ");
	scanf("%d", &s.grd.eng);
	printf("%d %s %d학년.\n수학: %d   영어 : %d\n", s.m.stdnum, s.m.name, s.m.jjam, s.grd.math, s.grd.eng);
	return 0;
}