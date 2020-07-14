/* 실수를 입력받아 배열에 저장하고, 문자 입력시 배열을 모두 출력하기
20.07.06 리뷰: 배열의 크기를 MAX_SIZE라는 상수로 선언했는데,
동적할당을 사용했다면 메모리를 더 효율적을 사용할 수 있었을 것임.
(진도상으로는 아직 동적할당 단계는 아니긴했음)
*/

#include <stdio.h>
#define MAX_SIZE 100

int main() {
	double array1[MAX_SIZE];
	int count_input = 0;
	for(int i = 0 ; i < MAX_SIZE ; i++) {
		if (scanf("%lf", &array1[i]) != 0) {
			printf("%.2lf\n", array1[i]);
			count_input++;
		}
		else {
			for (int j = 0; j < count_input; j++)
				printf("array1[%d] = %.2lf\n", j, array1[j]);
			return 0;
		}
	}
}