/* 
main에서 char* string1 = "Hello"; 
이렇게 하고 cp1 = string1 한 담에 %s로 찍으면 안나오는 이유는 멀까
19.07.12 리뷰 : 라고 했었는데 잘만 돌아감. 내가 저번에 뭐 잘못 친듯.
컴퓨터는 안 틀림.
*/
#include <stdio.h>

char* string1();
char* string2();

int main() {
	char* cp1 = string1();
	char* cp2 = string2();
	printf("%s %s\n", cp1, cp2);
	return 0;
}

char* string1() {
	return "Hello";
}
char* string2() {
	return "C World";
}
