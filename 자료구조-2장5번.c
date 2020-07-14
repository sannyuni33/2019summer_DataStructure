// srand() 인자를 입력받고, rand()를 이용해서 만든 난수 맞춰보기
#include <stdio.h>
#include <stdlib.h>

int main() {
	int n, r, guess;
	printf("srand 속 인자 값 입력:");
	scanf("%d", &n);
	srand(n);
	r = rand()%100;
	printf("숫자가 멀까요?: ");
	scanf("%d", &guess);
	if (guess == r)
		printf("정답!\n");
	else
		printf("아닌데! %d인데!\n",r);

	return 0;
}