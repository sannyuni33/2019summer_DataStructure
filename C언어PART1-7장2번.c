//정수입력하면 n, n-1, ... 2, 1개 별찍기(오른쪽으로 붙여서)
#include <stdio.h>

int main() {
	int n;
	int blank, star;
	printf("숫자를 입력하세여 : ");
	scanf("%d", &n);
	blank = 0;
	star = n;

	while (1) {
		for (int i = 0; i < blank; i++)
			printf(" ");
		for (int j = 0; j < star; j++)
			printf("*");
		puts("");
		blank++;
		star--;
		if (star == 0)
			break;
	}

	return 0;
}