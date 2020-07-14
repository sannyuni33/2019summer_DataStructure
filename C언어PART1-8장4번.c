// 점수(+)를 입력하면 최고점수를 100점으로 한 환산점수 출력
// 20.07.06 리뷰: 음수입력하면 다시 입력하게끔 하는 코드가 필요해보임.
#include <stdio.h>

int main() {
	int temp;
	int top = 0;
	double scores[5];

	for (int i = 0; i < 5; i++) {
		printf("점수를 입력하셈(양의 정수): ");
		scanf("%d", &temp);
		if (temp > top)
			top = temp;
		scores[i] = temp; // 19.07.12 리뷰 : 이 넘이 if(temp > top)보다 위에있든 여기있든 상관없지만
		                  // 위에 있는게 보기에 더 편-안할듯
	}
	printf("환산 점수는 ");
	for (int j = 0; j < 5; j++) {
		scores[j] = (scores[j] / (double)top) * 100;
		printf("%d,",(int)scores[j]);
	}
	printf(" 입니다.\n");

	return 0;
}