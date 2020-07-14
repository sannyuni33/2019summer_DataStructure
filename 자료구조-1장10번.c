#include <stdio.h>

typedef struct department {
	char deptname[20];
	int popul;
	struct department* link;
}DEPARTMENT;

void myPrint(DEPARTMENT*);

int main() {
	DEPARTMENT dep1 = { "컴퓨터공학부",550,NULL }, dep2 = { "게임공학부",300,NULL }, dep3 = { "전자공학부",350,NULL };
	dep1.link = &dep2;
	dep2.link = &dep3;

	myPrint(&dep1);
	
	return 0;
}

// 19.07.12 리뷰 : while(1) 말고 while( != NULL) 써서 더 짧게 하는 방법 있을거임. 연구해보셈. 
void myPrint(DEPARTMENT* p) {
	DEPARTMENT temp = *p;
	puts("-전체 부서 정보-");
	while (temp.link != NULL) {
		printf("부서 이름: %s\n부서 인원: %d\n\n", temp.deptname, temp.popul);
		temp = *temp.link;
		/*if (temp.link == NULL) {
			printf("부서 이름: %s\n부서 인원: %d\n\n", temp.deptname, temp.popul);
			break;
		}*/
	}
	printf("부서 이름: %s\n부서 인원: %d\n\n", temp.deptname, temp.popul);
}
/* 20.07.07 리뷰: while(1) -> while(temp.link != NULL) 로 바꾸고,
단순히 28~31 라인 주석처리만 하면 
당연히 맨 마지막 노드의 link가 NULL이니까 마지막 노드의 요소는 출력되지 않음.
while문 종료 후 프린트 한 번만 더해주면 되긴하는데 뭔가 멋이 없는데 ...
*/