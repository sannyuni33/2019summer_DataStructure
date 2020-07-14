// 7번문제의 중첩구조체 초기화 시켜주고, 과목별 평균과 고득점자 출력하기
#include <stdio.h>
#include <string.h>

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
	STUDENT s[3] = { {"박정민", 2010123456, 4,100,90},
					{ "이정민", 2011789456, 3,100, 95 },
					{ "노정민", 2012811523, 2,80,100 } };
	int total_max = 0, sum_m = 0, sum_e = 0;
	double avg_m, avg_e;
	char top[20];
	
	for (int i = 0; i < 3; i++) {
		sum_m += s[i].grd.math;
		sum_e += s[i].grd.eng;
		if (s[i].grd.eng + s[i].grd.math > total_max) {
			total_max = s[i].grd.eng + s[i].grd.math;
			strcpy(top, s[i].m.name);
		}
	}
	avg_m = (double)sum_m / 3;
	avg_e = (double)sum_e / 3;
	printf("전체 수학 점수 평균: %.2lf\n전체 영어 점수 평균: %.2lf\n",avg_m, avg_e);
	printf("총점이 가장 높은 넘은 %s입니다.(총점:%d)\n", top, total_max);
	return 0;
}