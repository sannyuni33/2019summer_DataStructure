/*
19.07.16
이 문제 어떻게 풀었냐,
자료구조때 연결자료구조 이용한 스택구현 내용으로 만들기로 함.(구조체, 포인터 사용)
그래서 스택노드 구조체랑 스택노드* top, 그리고 push pop 함수와 괄호검사 함수 세 개만 선언함.
push와 pop은 자료구조에서 배운 내용과 동일하고
괄호검사 함수에서 두 번을 틀렸는데.
첫 번째 틀렸을때는 ((()) 같은 경우에서 yes라고 나온거임.
이게 왜 틀렸었냐면, ) 와 ] 의 케이스에서 ( 나 [ 가 맞게만 나오면 통과하기 때문에, yes라고 나왔음.
어떻게 해결했냐면 스택에 남아있는 노드가 있을경우 괄호검사 함수가 0을 리턴하게 해서 해결했음.
근데도 틀렸다고 했는데, 왜 틀렸냐면 ((((]] 를 치면 no가 나오는건 맞는데 다음에 ()()를 검사하면 no 라고 나왔음.
왜 이러는걸까... 3분 정도 생각해보니까 아직 스택에 데이터가 남아있어서 그런거였음.
그래서 문자열 검사를 해서 y/n를 출력해주고 나면 top=NULL; 을 실행해서 스택을 비워버린거임.
그렇게 하니까 해결되서 맞았습니다!
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
	char data;
	struct node* link;
}stackNode;

void push(char);
char pop();
int checkBracket(char*, int);

stackNode* top = NULL;

int main() {
	char *sentence = (char*)malloc(101);
	int slen;

	while (1) {
		scanf("%[^/\n]s", sentence);
		getchar();
		if (strcmp(sentence, ".") == 0)
			break;
		slen = strlen(sentence);
		
		if (checkBracket(sentence, slen) == 1)
			printf("yes\n");
		else
			printf("no\n");
		top = NULL;
	}
	free(sentence);
	return 0;
}

void push(char c) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = c;
	if (top == NULL)
		temp->link = NULL;
	else
		temp->link = top;
	top = temp;
}

char pop() {
	stackNode* temp;
	if (top == NULL)
		return '0';
	else {
		temp = top;
		top = top->link;
		return temp->data;
	}
}

int checkBracket(char* stc, int slen) {
	char temp;
	for (int i = 0; i < slen; i++) {
		switch (stc[i])
		{
		case '(':
		case '[':
			push(stc[i]);
			break;
		case ')':
			temp = pop();
			if (temp == '0')
				return 0;
			else {
				if (temp != '(')
					return 0;
				else
					break;
			}
		case ']':
			temp = pop();
			if (temp == '0')
				return 0;
			else {
				if (temp != '[')
					return 0;
				else
					break;
			}
		default:
			break;
		}
	}
	if (pop() != '0')
		return 0;
	else
		return 1;
}
