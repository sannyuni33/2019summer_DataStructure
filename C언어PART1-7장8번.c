//학생 수 입력받고, 걔네들 점수 입력받아서 평균구하기
#include <stdio.h>

int main() {
	int std_num;
	double score;
	double sum=0;
	printf("학생 수를 입력하슈 : ");
	scanf("%d", &std_num);

	for (int i = 0; i < std_num; i++) {
		printf("학생 %d의 성적을 입력하슈 : ", i+1);
		scanf("%lf", &score);
		sum += score;
	}

	printf("학생들의 점수 평균은 %.2lf입니데이\n", sum/std_num);

	return 0;
}