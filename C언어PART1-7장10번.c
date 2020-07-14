//1부터 입력받은 n까지의 합 구하기
#include <stdio.h>

int main() {
	int n;
	int result=0;
	printf("자연수를 입력하시랑게여 : ");
	scanf("%d",&n);
	for (int i = 1; i < n + 1; i++) {
		result += i;
	}
	printf("%d부터 %d까지의 합은 %d입니당\n", 1, n, result);
	return 0;
}