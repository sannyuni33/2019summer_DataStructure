#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listNode{
	struct listNode* llink;
	char title[30];
	struct listNode* rlink;
}listNode;

typedef struct{
	listNode* head;
	listNode* playing;
}CDL_H;

CDL_H* createList();
void insertFnode(CDL_H*, char*);
void insertMnode(CDL_H*, char*, char*);
void deleteNode(CDL_H*, char*);
listNode* searchNode(CDL_H*, char*);
void playPrev(CDL_H*);
void playNext(CDL_H*);
void showList(CDL_H*);
void mainMenu(CDL_H*);
void printToFile(CDL_H*, FILE*);

int main() {
	CDL_H* CDL = createList();
	CDL->playing = NULL;
	FILE* fp = fopen("songList.txt", "r");
	char tempTitle[30];

	while (!feof(fp)) {
		fscanf(fp,"%[^/\n]s", tempTitle);
		fgetc(fp); //요롷게 하면 된다~~
		insertFnode(CDL, tempTitle);
	}
	fclose(fp);
	mainMenu(CDL);

	fp = fopen("songList.txt", "w");
	printToFile(CDL, fp);
	fclose(fp);
	system("songList.txt");
	return 0;
}

CDL_H* createList() {
	CDL_H* cdl = (CDL_H*)malloc(sizeof(CDL_H));
	cdl->head = NULL;
	return cdl;
}

void mainMenu(CDL_H* cdl) {
	char n = 'a';
	char title[30], pTitle[30];
	listNode* temp;
	while (n != 'Q') {
		printf("\n♡♡♡♡♡♡ MP3 PLAYER ♡♡♡♡♡♡\nn(N): 다음 곡 재생\np(P): 이전 곡 재생\n");
		printf("1: 처음 곡으로 추가\n2: 중간 곡으로 추가\n3: 곡명 검색\n");
		printf("4: 곡 삭제\n5: 재생목록 보기\nQ: 종료\n>>");
		n = getchar();
		getchar();
		
		switch (n)
		{
		case 'N':
		case 'n':
			playNext(cdl);
			break;
		case 'P':
		case 'p':
			playPrev(cdl);
			break;
		case '1':
			printf("제목을 입력해주세여: ");
			scanf("%[^/\n]s", title);
			getchar();
			insertFnode(cdl, title);
			break;
		case '2':
			printf("제목을 입력해주세여: ");
			scanf("%[^/\n]s", title);
			getchar();
			printf("어느 곡 뒤로?: ");
			scanf("%[^/\n]s", pTitle);
			getchar();
			insertMnode(cdl, pTitle, title);
			break;
		case '3':
			printf("제목을 입력해주세여: ");
			scanf("%[^/\n]s", title);
			getchar();
			temp = searchNode(cdl, title);
			if (temp != NULL) printf("재생목록에 존재합니다!\n\n");
			else printf("그런 곡은 없다능\n\n");
			break;
		case '4':
			printf("제목을 입력해주세여: ");
			scanf("%[^/\n]s", title);
			getchar();
			deleteNode(cdl, title);
			break;
		case '5':
			showList(cdl);
			break;
		case 'Q':
			break;
		default:
			printf("다시\n");
			break;
		}
	}
	printf("빠이욤!\n\n");
}

void insertFnode(CDL_H* cdl, char* title) {
	listNode *newNode, *temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->title, title);
	//공백인경우와 아닌경우를 나눠서
	if (cdl->head == NULL) { //공백리스트인 경우
		//이중원형 연결리스트라서 llink rlink 둘 다 자기자신.
		newNode->llink = newNode; 
		newNode->rlink = newNode;
		cdl->head = newNode;
	}
	else { //공백아니고 다른 노드가 있는경우
		temp = cdl->head;
		//맨 뒤로 이동한다음에 뉴노드로 연결하기
		while (temp->rlink != cdl->head) {
			temp = temp->rlink;
		}
		newNode->llink = cdl->head->llink;
		cdl->head->llink = newNode;
		newNode->rlink = cdl->head;
		temp->rlink = newNode;
		cdl->head = newNode;
	}
	printf("곡이 저장되었습니다. '%s'\n", newNode->title);
}

void insertMnode(CDL_H* cdl, char* prev, char* title) {
	listNode* newNode = (listNode*)malloc(sizeof(listNode));
	strcpy(newNode->title, title);
	listNode* prevNode = searchNode(cdl, prev);
	prevNode->rlink->llink = newNode;
	newNode->rlink = prevNode->rlink;
	prevNode->rlink = newNode;
	newNode->llink = prevNode;
	printf("곡이 저장되었습니다. '%s'\n", newNode->title);
}

void deleteNode(CDL_H* cdl, char* title) {
	listNode* temp = searchNode(cdl, title);
	cdl->playing = temp->rlink;
	temp->rlink->llink = temp->llink;
	temp->llink->rlink = temp->rlink;
	free(temp);
	printf("곡이 삭제되었습니다. '%s'\n", title);
}

listNode* searchNode(CDL_H* cdl, char* title) {
	listNode* temp = cdl->head;
	do {
		if (strcmp(title, temp->title) == 0) return temp;
		else temp = temp->rlink;
	} while (temp != cdl->head);
	return NULL;
}

void playPrev(CDL_H* cdl) {
	if (cdl->playing == NULL) {
		cdl->playing = cdl->head;
		printf("곡을 재생합니당! '%s'\n\n", cdl->playing->title);
	}
	else {
		cdl->playing = cdl->playing->llink;
		printf("이전 곡을 재생합니당! '%s'\n\n", cdl->playing->title);
	}
}

void playNext(CDL_H* cdl) {
	if (cdl->playing == NULL) {
		cdl->playing = cdl->head;
		printf("곡을 재생합니당! '%s'\n\n", cdl->playing->title);
	}

	else {
		cdl->playing = cdl->playing->rlink;
		printf("다음 곡을 재생합니당! '%s'\n\n", cdl->playing->title);
	}
}

void showList(CDL_H* cdl) {
	listNode* temp = cdl->head;
	do {
		printf("%s", temp->title);
		temp = temp->rlink;
		if (temp != cdl->head) printf("  ->  ");
	} while (temp != cdl->head);
	printf("\n\n\n");
}

void printToFile(CDL_H* cdl, FILE* fp) {
	//이 함수를 거쳐 저장된 재생목록의 순서가 반대로 바뀌지 않도록 뒤에서부터 파일에 출력
	listNode* temp = cdl->head->llink;
	do {
		fprintf(fp,"%s", temp->title);
		temp = temp->llink;
		if (temp != cdl->head->llink) fprintf(fp, "\n");
	} while (temp != cdl->head->llink);
}