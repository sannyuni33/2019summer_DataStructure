/*
19.07.17
이 문제 푸는데는 설계가 중요한 역할을 했음!
제일 먼저 문제를 보고 N만큼 노드 동적할당해서 생성+데이터 저장,
노드의 형태는 이중 원형 연결리스트로 하는게 문제목적에 가장 알맞고
P만큼의 크기 int형 배열 선언해서 삭제대상 저장,
필요한 기능은 첫 번째 노드로 삽입, 첫 번째 노드 삭제,
왼쪽으로 이동 / 오른쪽으로 이동, 그리고 방향결정 해서 다섯가지.
여기까지 쭉쭉 설계됬음.

왼쪽이동 오른쪽이동 기능은 데이터(노드)를 직접 이동시키는 것보다
헤드를 반대방향으로 움직이는게 전체 노드를 움직이는 것과
결과는 같고 훨씬 더 효율적이라는 생각은 약 5초만에 떠오름.

설계하는데 시간이 좀 걸렸던 곳은 방향결정이었음.
가운데에 끼어있는 노드가 어느쪽으로 가야 더 적게 이동해서
가장 왼쪽으로 올 수 있는지.... 결정하는 알고리즘을 생각해야 했는데
왼쪽에서부터 그 수에 이르기까지의 이동횟수를 세서
전체 노드수의 절반보다 적으면 왼쪽. 많으면 오른쪽으로 가면 되겠다
라는 생각을 3분만에 하게됨.

이거가지고 구현하니깐 금방 만들어졌음!
공부를하면 할수록 알고리즘 아이디어가 잘 떠오르는게 체감됨.
컴퓨터 방식으로 생각하는데에 익숙해진 것 같음.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct dequeuenode {
	int data;
	struct dequeuenode* llink;
	struct dequeuenode* rlink;
}DNODE;

typedef struct circleDequeue {
	DNODE* head;
}CDQ;

CDQ* createDQ();
void inputNode(CDQ*, int);
void deleteNode(CDQ*);
void moveToLeft(CDQ*);
void moveToRight(CDQ*);
void decideDirection(CDQ*, int);


int cost = 0, nodeNum;
int* blackList;

int main() {
	CDQ* cdq = (CDQ*)malloc(sizeof(CDQ));
	cdq->head = NULL;
	int p, i;
	scanf("%d", &nodeNum);
	scanf("%d", &p);

	//33~37행은 준비단계. 입력받은만큼 큐의 노드를 생성하고 데이터를 입력함.
	//그 다음에 삭제대상 수를 블랙리스트 배열에 저장.
	for (i = nodeNum; i > 0; i--)
		inputNode(cdq, i);
	blackList = (int*)malloc(sizeof(int)*p);
	for (i = 0; i < p; i++)
		scanf("%d", &blackList[i]);
	
	//블랙리스트 배열의 i번째 원소를 삭제하는 함수.
	for (i = 0; i < p; i++)
		decideDirection(cdq,i);

	printf("%d\n", cost);
	free(cdq);
	return 0;
}

CDQ* createDQ() {
	CDQ* temp = (CDQ*)malloc(sizeof(CDQ));
	temp->head = NULL;
	return temp;
}

void inputNode(CDQ* cdq, int d) {
	DNODE* newNode = (DNODE*)malloc(sizeof(DNODE));
	DNODE* temp;
	newNode->data = d;

	//공백데크인 경우
	if (cdq->head == NULL) {
		cdq->head = newNode;
		newNode->llink = newNode;
		newNode->rlink = newNode;
	}
	//다른 노드가 있는 경우
	else {
		temp = cdq->head;
		do {
			temp = temp->rlink;
		} while (temp->rlink != cdq->head);
		newNode->rlink = cdq->head;
		cdq->head->llink = newNode;
		newNode->llink = temp;
		temp->rlink = newNode;
		cdq->head = newNode;
	}
}

void deleteNode(CDQ* cdq) {
	//대가리(제일 왼쪽)만 지울거라서 데이터 전달, 리턴안해도 됨.
	if (cdq->head->rlink == cdq->head)
		cdq->head = NULL;
	else {
		DNODE* temp = cdq->head;
		temp->rlink->llink = temp->llink;
		temp->llink->rlink = temp->rlink;
		cdq->head = temp->rlink;
		free(temp);
	}
	nodeNum--;
}


void moveToLeft(CDQ* cdq) {
	cdq->head = cdq->head->rlink;
	cost++;
}
void moveToRight(CDQ* cdq) {
	cdq->head = cdq->head->llink;
	cost++;
}

void decideDirection(CDQ* cdq, int p) {
	DNODE* cdd = cdq->head;
	int i,  moving = 0;

	//삭제할려는 넘을 찾을때까지 오른쪽으로 이동
	while (cdd->data != blackList[p]) {
		cdd = cdd->rlink;
		moving++;
	}
	
	if ((double)nodeNum / 2 > moving) // 절반까지 못갔으면 왼쪽이동
		for (i = 0; i < moving; i++)
			moveToLeft(cdq);
	else
		for (i = 0; i < nodeNum-moving; i++) //절반 넘게 갔으면 오른쪽이동
			moveToRight(cdq);
	
	deleteNode(cdq); //그 다음 삭제
}