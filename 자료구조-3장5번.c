// 구조체 멤버변수 정보 파일에 출력하기
#include <stdio.h>
#include <stdlib.h>

typedef struct department {
	char deptname[20];
	int popul;
	struct department* link;
}DEPT;

int main() {
	DEPT dep1 = { "컴퓨터공학부",550,NULL },
		dep2 = { "오징어심리학과",525,NULL },
		dep3 = { "목탁제조과",58,NULL };
	dep1.link = &dep2;
	dep2.link = &dep3;

	FILE* stream = fopen("department.txt", "w");

	puts("-전체 부서 정보-");
	printf("부서 이름: %s\n부서 인원: %d\n\n부서 이름: %s\n부서 인원: %d\n\n부서 이름: %s\n부서 인원: %d\n\n"
		, dep1.deptname, dep1.popul, dep1.link->deptname, dep1.link->popul, 
		dep1.link->link->deptname, dep1.link->link->popul);
	
	fprintf(stream, "%s %d\n%s %d\n%s %d\n", dep1.deptname, dep1.popul, dep1.link->deptname, dep1.link->popul,
		dep1.link->link->deptname, dep1.link->link->popul);

	fclose(stream);
	system("notepad.exe department.txt");
	return 0;
}