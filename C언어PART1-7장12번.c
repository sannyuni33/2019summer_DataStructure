//알파벳 하나 입력하면 걔 다음부터 z까지출력
//대소문자 모두 유효
//알파벳 아닌거 들어오면 출력 안함
#include <stdio.h>
#include<stdlib.h>

int main() {
	char alp;
	printf("알파벳을 입력하셈 : ");
	scanf("%c", &alp);
	
	if (alp > 96 && alp < 123) {
		printf("입력한 %c 이후의 알파벳은\n", alp);
		for (int i = alp + 1; i < 123; i++)
			printf("%c,", i);
		printf("입니다리다리 다리우스\n");
	}
	else if (alp > 64 && alp < 91) {
		printf("입력한 %c 이후의 알파벳은\n", alp);
		for (int i = alp + 1; i < 91; i++)
			printf("%c,", i);
		printf("입니다리다리 다리우스\n");
	}
	else
		printf("끄지셈\n");

	return 0;
}