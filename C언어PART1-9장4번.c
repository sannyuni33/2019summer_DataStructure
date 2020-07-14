/*문자 하나 입력하면 숫자인지 아닌지 판단해줌
20.07.06 리뷰: 의도한 기능은 잘 수행되고,
길이 2 이상의 문자열 입력시 앞글자 갖고 판단함.
입력 길이 제한 필요.
*/
#include <stdio.h>

int checkInt(char temp);

int main() {
	char n;
	printf("문자를 입력하셈: ");
	scanf("%c", &n);
	checkInt(n);

	return 0;
}

int checkInt(char temp) {
	if (temp > 47 && temp < 58)
		printf("입력한 문자 %c(은)는 숫자입니다!\n",temp);
	else
		printf("입력한 문자 %c(은)는 숫자가 아임니다..\n",temp);

	return 0;
}