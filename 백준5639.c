/*
19.07.22
문제를 보자마자 띠용하고 떠오른 생각은
입력에서 전위순회한 결과라고 생각하지 말고 그냥
이진 탐색트리에 삽입하는 연산한 다음에
후위 출력하면 끝나는거 아닌가라는 생각을 함.
그게 될지 한 번 해보겠음.

일단 예제입력 순서대로 입력한다고 치면
문제에서 주어진 트리 모양으로 만들어지긴 함.
근데 좀 꺼림칙하긴 한데,,

아니 근데 노드수는 만개까지 되는데 입력을 어떻게 끝내지????
이거 찾는데 시간 좀 쓰는중..
입력이 끝났을 때 scanf를 호출하면 EOF가 리턴된다는데 이게 뭔소릴까

3번 연달아 입력해야만 끝난다고 함...

ctrl+z 3번 하니까 제대로 되고 문제도 맞았씸
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
	int data;
	struct treenode* leftChild;
	struct treenode* rightChild;
}tnode;

tnode* root = NULL;

tnode* insertNode(tnode*, int);
void postorder(tnode*);

int main() {
	int num;
	scanf("%d", &num);
	root = insertNode(root, num);
	while (scanf("%d", &num) != EOF) {
		insertNode(root, num);
	}
	postorder(root);

	return 0;
}

tnode* insertNode(tnode* root, int d) {
	tnode* newNode;
	
	if (root == NULL) {
		newNode = (tnode*)malloc(sizeof(tnode));
		newNode->data = d;
		newNode->leftChild = NULL;
		newNode->rightChild = NULL;
		return newNode;
	}
	else if (d < root->data)
		root->leftChild = insertNode(root->leftChild, d);
	else if (d > root->data)
		root->rightChild = insertNode(root->rightChild, d);
	else
		puts("이미 있는 키임! 끄지삼!");
	return root;
}

void postorder(tnode* root) {
	if (root) {
		postorder(root->leftChild);
		postorder(root->rightChild);
		printf("%d\n", root->data);
	}
}