#include <stdio.h>
#include <stdlib.h>
//굳이 동적할당 필요없는데..라고 1년전에 생각했겠지만 얘는 free를 해준다.
typedef struct score {
	int math;
	int eng;
}SCORE;

int main() {
	int n, msum = 0, esum = 0;
	double mavg, eavg;
	printf("응시자 수: ");
	scanf("%d", &n);
	SCORE* p = (SCORE*)malloc(sizeof(SCORE)*n);
	
	for (int i = 0; i < n; i++) {
		printf("영어 성적, 수학 성적(예: 10 10): ");
		scanf("%d %d", &(p[i].eng), &(p[i].math)); 
		esum += p[i].eng;
		msum += p[i].math;
	}

	eavg = (double)esum / n;
	mavg = (double)msum / n;
	
	printf("\n[%d명 학생의 성적 평균]\n영어: %.2lf,수학: %.2lf\n",n, eavg, mavg);
	free(p);
	return 0;
}