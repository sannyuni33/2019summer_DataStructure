/* 길이 4짜리 배열 두 개에 값 입력받고, 교집합과 합집합 구하기
20.07.06 리뷰: 합집합 출력하기 전에 배열1 배열2를 비교해서 
겹치는 원소가 있으면 배열2의 해당 인덱스를 NULL로 바꾸고
배열 2 출력할때 NULL이면 continue 하는 식으로 짰는데,
합집합 배열을 따로 선언해주는게 나았을려나..
합집합에 원소가 몇개나 들어올지 모르는 상황에서(최대 8개긴 함)
동적할당을 할 수도 있긴한데..
메모리 효율도 지금 이렇게 하는게 나을것 같긴 함
*/
#include <stdio.h>

int main() {
	int array1[4];
	int array2[4];
	int i, j;
	printf("배열 1의 숫자 4개를 입력하앍 : ");
	for (i = 0; i < 4; i++) {
		scanf("%d", &array1[i]);
	}
	printf("배열 2의 숫자 4개를 입력하앍 : ");
	for (j = 0; j < 4; j++) {
		scanf("%d", &array2[j]);
	}

	printf("배열 1과 2의 교집합\n[ ");
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (array1[i] == array2[j])
				printf("%d ", array1[i]);
		}
	}
	puts("]");

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (array1[i] == array2[j])
				array2[j] = NULL;
		}
	}

	printf("배열 1과 2의 합집합\n[ ");
	for (i = 0; i < 4; i++)
		printf("%d ", array1[i]);
	for (j = 0; j < 4; j++) {
		if (array2[j] == NULL)
			continue;
		else
			printf("%d ", array2[j]);
	}
	puts("]");

	return 0;
}