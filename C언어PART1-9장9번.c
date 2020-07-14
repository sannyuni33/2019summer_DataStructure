/* 
19.07.12 리뷰
두 피연산자와 연산자, 3개 중 하나라도 이상한 값이 들어오는 경우 
입력이 올바르지 않다는 메시지를 띄우기 위해 3중 if문이 각각 scanf()!=0 을 검사함.
scanf(%d %c %d)로 입력 받을때는 모든 경우를 걸러낼 수가 없었음.
(피연산자 중 하나를 문자로 넣으면 쓰레기 값이 나오는 등)
어떻게 하면 같은 동작을 해도 더 짧고 가독성 높은 코드를 짤지 고민해봐야 함.
*/

#include <stdio.h>

void sum(int a, int b);
void minus(int a, int b);
void multi(int a, int b);
void divide(double a, double b);

int main() {
	int a, b;
	char oprt;
	while (1) { 
		printf("계산식 입력: ");
		if (scanf("%d", &a) != 0) {
			getchar();
			if (scanf("%c", &oprt) != 0) {
				if (scanf("%d", &b) != 0) {
					switch (oprt)
					{
					case '+':
						sum(a, b);
						break;
					case '-':
						minus(a, b);
						break;
					case '*':
						multi(a, b);
						break;
					case '/':
						divide(a, b);
						break;
					default:
						printf("수식 좋게 쓰세요ㅡㅡ\n");
						return 0;
					}
				}
				else {
					printf("수식 좋게 쓰세요ㅡㅡ\n");
					return 0;
				}
			}
			else {
				printf("수식 좋게 쓰세요ㅡㅡ\n");
				return 0;
			}
		}
		else {
			printf("수식 좋게 쓰세요ㅡㅡ\n");
			return 0;
		}
	}
}

void sum(int a, int b) {
	printf("결과: %d\n", a + b);
}

void minus(int a, int b) {
	printf("결과: %d\n", a - b);
}

void multi(int a, int b) {
	printf("결과: %d\n", a * b);
}

void divide(double a, double b) {
	printf("결과: %.2lf\n", a / b);
}