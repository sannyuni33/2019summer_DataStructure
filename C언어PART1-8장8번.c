/*네 자리의 연도를 입력받아서 윤년 여부를 판단
19.07.12리뷰: "년은 윤년이 아니지롱!" 이랑 "년은 윤년이지롱!"이라는 
문자열을 따로 선언해놓고 %s로 출력하는게 코드길이는 짧아지겠지만, 
이렇게 짜는게 가독성이 더 좋지 않을까..라는 생각을 해보았음. 
*/
#include <stdio.h>

int main() {
	int year;
	printf("윤년 여부를 조사할 연도를 입력하세요(yyyy): ");
	scanf("%d", &year);

	if (year % 4 == 0) {
		if (year % 100 == 0)
			printf("%d년은 윤년이 아니지롱!\n", year);
		else
			printf("%d년은 윤년이지롱!\n", year);
	}
	else
		printf("%d년은 윤년이 아니지롱!\n", year);
	
	return 0;
}