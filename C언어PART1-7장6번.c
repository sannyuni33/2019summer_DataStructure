//n단부터 9단까지 이쁘게 출력
#include <stdio.h>

int main() {
	int dan;
	printf("2~9 사이의 정수를 입력하세여 : ");
	scanf("%d", &dan);

	for (int i = dan; i < 10; i++) {
		for (int j = 1; j < 10; j++)
			printf("%d*%d=%2d ",i,j,i*j);
		puts("");
	}
	return 0;
}