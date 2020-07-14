/* 숫자 5개만 입력받은뒤, 최솟값 최댓값 구하기 
19.07.12 리뷰
사용자가 입력할 숫자의 범위가 정해져있지 않고, 
최댓값과 최솟값을 모두 구해야하기 때문에 max와 min을 0으로 초기화하면 안됨.
5번 입력받고 첫번째 요소를 max, min에 저장해야 온전하게 비교가 가능.
*/
#include <stdio.h>

int main() {
	int array1[5];
	int max, min;
	
	for (int i = 0; i < 5; i++) {
		printf("숫자를 입력하셈: ");
		scanf("%d", &array1[i]);
	}
	max = array1[0];
	min = array1[0];
	for (int j = 1; j < 5; j++) {
		if (array1[j] > max)
			max = array1[j];
		else if (array1[j] < min)
			min = array1[j];
		else
			continue;
	}
	printf("입력한 수들의 최솟값은 %d, 최댓값은 %d입니다.\n", min, max);
	return 0;
}