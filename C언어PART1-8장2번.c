/* 19.07.12 리뷰 : snd는 초기화 안해줘도 제대로 될걸? 이라고 생각했지만 
 음수만 5번쓰면 쓰레기값 나올걸? 이라고 생각했지만  
 돌려보니까 런타임에러가 떠버림. 초기화는 꼭 필요했었음!
 18행 else if에서 snd랑 비교를 해야하기 때문임. */

/* 20.07.06 리뷰: 음수로만 다섯개찍으니까 0이 나와버림.
fsd랑 snd를 0으로 초기화했으니까 당연히 그럴수 밖에 없음.
파이썬 같으면 -inf로 초기화하면 해결인디...
*/
#include <stdio.h>

int main() {
	int temp; 
	int fst = 0, snd = 0; 

	for (int i = 0; i < 5; i++) {
		printf("정수를 입력하셈 : ");
		scanf("%d", &temp);
		if (temp > fst) {
			snd = fst;
			fst = temp;
		}
		else if (temp > snd) {
			snd = temp;
		}
	}
	printf("두 번째로 큰 수 :%d\n",snd);

	return 0;
}