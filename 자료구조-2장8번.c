//아이디 비번 입력받고 비교하기(비번은 *로 표시, 아래에 링크 있음 -> while문 부분)
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>

int main() {
	char id[] = "admin";
	char pw[] = "a1234";
	char id_input[20];
	char pw_input[20];
	int cnt = 0;

	printf("아이디를 입력하세여: ");
	gets(id_input);
	printf("비번을 입력하세여: ");
	while (1) {
		if (_kbhit()) {
			pw_input[cnt] = _getch();
			if (pw_input[cnt] == 13)
				break;
			cnt++;
			printf("*");
		}
	}
	pw_input[cnt] = '\0';
	puts("");
	
	if (strcmp(id, id_input) != 0)
		puts("아이디가 틀렸슴다");
	else if (strcmp(pw, pw_input) != 0)
		puts("비번이 틀렸슴다");
	else
		puts("로긴띠!");
	
	return 0;
}

//https://m.blog.naver.com/PostView.nhn?blogId=security428&logNo=220746273327&proxyReferer=https%3A%2F%2Fwww.google.com%2F