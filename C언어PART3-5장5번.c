// 변수의 주소를 void 포인터에 저장하고, void 포인터 활용하는 함수 정의
#include <stdio.h>

void area(double* dp);

int main() {
	double r;
	void* vp = &r;
	printf("반지름 입력쿠: ");
	scanf("%lf", &r);
	area(vp);

	return 0;
}

void area(double* dp) {
	double result = *dp * *dp * 3.14;
	printf("원의 넓이: %.2lf\n", result);
}