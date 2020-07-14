// 자기 참조 구조체를 이용하여 멤버변수 접근하기(연결리스트의 노드와 같은 개념인듯)
#include <stdio.h>

typedef struct department {
	char deptname[20];
	int popul;
	struct department* link;
}DEPARTMENT;

int main() {
	DEPARTMENT dep1 = { "컴퓨터공학부",550,NULL }, dep2 = { "게임공학부",300,NULL }, dep3 = { "전자공학부",350,NULL };
	dep1.link = &dep2;
	dep2.link = &dep3;
	
	puts("-전체 부서 정보-");
	printf("부서 이름: %s\n부서 인원: %d\n\n부서 이름: %s\n부서 인원: %d\n\n부서 이름: %s\n부서 인원: %d\n\n"
	,dep1.deptname,dep1.popul,dep1.link->deptname,dep1.link->popul, dep1.link->link->deptname, dep1.link->link->popul);
	return 0;
}