/*
19.07.24 리뷰
최소힙에서 살짝 바꿔서 만든 코드!
진성민: 코드가 되게 간결하고 보기가 좋았습니다. 
특히, size가 0일 때 저는 reu-turn 0을 했는데 바로 printf로 찍는게 훨씬 나은 것 같다
고영상:전체적인 구조는 제 코드랑 비슷한거 같은데 
main문을 확실히 간결하게 한 점이 맘에 들었다. 나도 담에는 이렇게 간결하게 짜봐야겠다.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100000

typedef struct heap {
	int heapArray[MAX_SIZE];
	int size;
}heap;

void insertNode(heap*, int);
void deleteNode(heap*);

int main() {
	int n, d;
	heap* hh = (heap*)malloc(sizeof(heap));
	hh->size = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &d);
		if (d == 0)
			deleteNode(hh);
		else
			insertNode(hh, d);
	}
	
	free(hh);
	return 0;
}

void insertNode(heap* hh, int x) {
	hh->size++;
	int i = hh->size;
	while (i != 1 && x > hh->heapArray[i / 2]) {
		hh->heapArray[i] = hh->heapArray[i / 2];
		i /= 2;
	}
	hh->heapArray[i] = x;
}

void deleteNode(heap* hh) {
	if (hh->size == 0) {
		puts("0");
		return;
	}
		
	int item = hh->heapArray[1], temp = hh->heapArray[hh->size], parent = 1, child = 2;
	hh->size--;

	while (child <= hh->size) { // <에서 <=로 바꿈
		if (child < hh->size &&(hh->heapArray[child] < hh->heapArray[child + 1])) //child <= 에서 <로 바꿈
			child++;
		if (temp >= hh->heapArray[child])
			break;
		else {
			hh->heapArray[parent] = hh->heapArray[child]; //이거 안썼었음...ㅎ하
			parent = child;
			child *= 2;
		}
	}
	hh->heapArray[parent] = temp;
	printf("%d\n", item);

}

