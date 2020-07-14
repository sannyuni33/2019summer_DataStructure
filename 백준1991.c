/*
19.07.22
이 문제 어떻게 풀까
전위 중위 후위 탐색 알고리즘은 다 아는거라서 근다치는데
입력방식이 트리를 구성하기 꽤나 빡셌음.
입력방식과 트리구성을 사이의 인터페이스를 어떻게 구축하나,
이게 관건인듯.

맨 처음에는 3개 문자를 입력받고나서,
트리가 공백이면 3개의 노드를 생성해서 데이터를 넣어주고
첫번째노드의 왼쪽자식, 오른쪽자식을 각각 두번째 세번째노드로 연결하고
공백이 아니면 데이터가 ptemp랑 같은 노드로 이동한 뒤에
알파벳을 입력받은 경우만 노드를 생헝하고 데이터입력
그렇지 않으면 NULL로 설정하고 자식으로 연결해주는 방식을 하려다가...
데이터가 ptemp랑 같은 노드를 탐색해야하는 부담이 꽤 클것으로 예상됬기 때문에
이 방법은 접고 다른 방법을 생각해보았음.

n개 만큼의 노드를 생성해서 연결리스트에 집어넣고 각 노드구조체가
자신의 왼쪽자식. 오른쪽자식은 어떤 데이터를 갖고있는지를 리스트에 있는 노드들의
데이터와 비교해서 같은 노드를 발견하면 연결하는 방식을 생각해보았음.

그러면 구조체의 멤버변수도 6가지로 늘어나고 좀 지저분해 보여서 맘에 안들던 차에
차라리 그것보다는 n크기 만큼의 구조체배열을 동적할당 하는게
코드 길이상이나 메모리 효율이 좀 더 나을것으로 생각되서 그걸로 일단 해보겠음.

맞았음!
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
	char data, ldata, rdata;
	struct treeNode* leftChild;
	struct treeNode* rightChild;
}tnode;

void preorder(tnode*);  //전위순회
void inorder(tnode*);   //중위순회
void postorder(tnode*); //후위순회

int main() {
	int n, i, j;
	char ptemp, ltemp, rtemp;
	tnode* root;

	scanf("%d", &n);
	getchar();
	tnode* nodeList = (tnode*)malloc(sizeof(tnode)*n);
	for (i = 0; i < n; i++) { //n개 만큼의 노드 생성.
		scanf("%c %c %c", &ptemp, &ltemp, &rtemp);
		getchar();
		
		(nodeList + i)->data = ptemp;
		(nodeList + i)->ldata = ltemp;
		(nodeList + i)->rdata = rtemp;
		(nodeList + i)->leftChild = NULL;
		(nodeList + i)->rightChild = NULL;
	}

	for (i = 0; i < n; i++) { //부모와 자식 연결
		for (j = 0; j < n; j++) {
			if ((nodeList + i)->ldata == (nodeList + j)->data)
				(nodeList + i)->leftChild = &nodeList[j];

			if ((nodeList + i)->rdata == (nodeList + j)->data)
				(nodeList + i)->rightChild = &nodeList[j];
		}
	}
	
	root = &nodeList[0];
	preorder(root);
	puts("");
	inorder(root);
	puts("");
	postorder(root);
	puts("");

	free(nodeList);
	return 0;
}

void preorder(tnode* root) {
	if (root) {
		printf("%c", root->data);
		preorder(root->leftChild);
		preorder(root->rightChild);
	}
}
void inorder(tnode* root) {
	if (root) {
		inorder(root->leftChild);
		printf("%c", root->data);
		inorder(root->rightChild);
	}
}
void postorder(tnode* root) {
	if (root) {
		postorder(root->leftChild);
		postorder(root->rightChild);
		printf("%c", root->data);
	}
}

