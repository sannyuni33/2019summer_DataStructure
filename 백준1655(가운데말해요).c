/*
19.07.24
문제보자마자 히프 사이즈의 1/2을 이용하는게 좋겠다라는 생각이 들었음.
우선순위 큐 관련 문제라고 알려주니까 바로 생각했지 아니면 생각하기 힘들었을듯
예제 입출력을 보고 분석해본 결과(최소힙을 이용한다고 가정)
히프의 전체사이즈가 홀수인경우 사이즈/2+1 번째 요소를 출력
히프의 전체사이즈가 짝수인경우 사이즈/2 번째 요소를 출력
하면 된다는 것을 알게됨. 플로우차트 그리고 코딩짜보겠음.

아 근데 이게 걍 단순하게 최소힙으로만 하면, 같은 레벨에 있는 노드끼리는 대소관계가
없어서 제대로 된 값이 출력되지 않음. 왼쪽 자식이 더 작아야만 내가 원하는 모양이 됨.

그러면 이 시점에서 선택을 해야함.
배열 전체를 오름차순 정렬해버릴거냐, 아니면 한 노드의 왼쪽 오른쪽 자식끼리만 비교해줄거냐.
오름차순 정렬을 하면 당장 코드 짜서 끝낼 수 있는데 이게 메모리 효율이 좋을지 의심됨.
배열이 커지면 커질수록 더 비효율적임. 10만까지가면 시간초과 뜰 것 같은데.
배열전체 정렬은 아무리 생각해도 개 오바임. 제외시키고,
최소히프를 어떻게 건드려서 정렬을 시켜볼까..

19.07.25
영상이한테 최소힙 최대힙 두 개 써서 루트끼리 교환하는 알고리즘 듣고
바로 플로우차트 그리고 코드짰는데, 틀렸다고 나왔음.
그래서 6시간을 해메다가... 사실 이게 맞는 코드였는데 배열크기를 5만으로 줘서 틀린거였음.
50001로 주니까 바로 맞았다. 6시간동안 얻은 교훈은
"배열 크기를 넉넉하게 주자"였음	. 시팔
*/

/*
진성민: 동적할당을 통해 크기에 구애받지 않아 좋았고, 
cnt를 활용해서 왼쪽과 오른쪽에 넣는 것을 활용하니 코드도 훨씬 간결해지고 좋은 것 같다
고영상: 전반적인 알고리즘음 마찬가지로 내 코드와 비슷했지만 좀 더 간결하게 짠 점이 좋았다. 
특히 cnt변수를 하나로 해서 짠 점이 인상깊었다.
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 50001

typedef struct heapheap {
	int heapArray[MAX_SIZE];
	int size;
}heap;

void insertMaxheap(heap*, int);
int deleteMaxheap(heap*);
void insertMinheap(heap*, int);
int deleteMinheap(heap*);

int main() {
	int n, d, cnt = 0;
	int maxTemp, minTemp;
	heap *maxHeap = (heap*)malloc(sizeof(heap)); 
	heap *minHeap = (heap*)malloc(sizeof(heap));
	
	scanf("%d", &n);
	maxHeap->size = 0;
	minHeap->size = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &d);

		if (cnt % 2 == 0) //28~31행 : 최대힙, 최소힙에 번갈아가면서 숫자 넣어줌.
			insertMaxheap(maxHeap, d);
		else
			insertMinheap(minHeap, d);

		if ((maxHeap->heapArray[1] > minHeap->heapArray[1]) && (cnt != 0)) { //최대힙의 루트가 더 큰 경우 양쪽 루트 교환
			maxTemp = deleteMaxheap(maxHeap);
			minTemp = deleteMinheap(minHeap);
			insertMaxheap(maxHeap, minTemp);
			insertMinheap(minHeap, maxTemp);
		}
		printf("%d\n", maxHeap->heapArray[1]);
		cnt++;
	}
	
	free(maxHeap);
	free(minHeap);
	return 0;
}

void insertMaxheap(heap* hh, int x) {
	hh->size++;
	int i = hh->size;
	while (i != 1 && x > hh->heapArray[i / 2]) {
		hh->heapArray[i] = hh->heapArray[i / 2];
		i /= 2;
	}
	hh->heapArray[i] = x;
}

int deleteMaxheap(heap* hh) {
	int item = hh->heapArray[1], temp = hh->heapArray[hh->size], parent = 1, child = 2;
	hh->size--;

	while (child <= hh->size) { 
		if (child < hh->size && (hh->heapArray[child] < hh->heapArray[child + 1])) 
			child++;
		if (temp >= hh->heapArray[child])
			break;
		else {
			hh->heapArray[parent] = hh->heapArray[child];
			parent = child;
			child *= 2;
		}
	}
	hh->heapArray[parent] = temp;
	return item;
}

void insertMinheap(heap* hh, int x) {
	hh->size++;
	int i = hh->size;
	while (i != 1 && x < hh->heapArray[i / 2]) {
		hh->heapArray[i] = hh->heapArray[i / 2];
		i /= 2;
	}
	hh->heapArray[i] = x;
}

int deleteMinheap(heap* hh) {
	int item = hh->heapArray[1], temp = hh->heapArray[hh->size], parent = 1, child = 2;
	hh->size--;

	while (child <= hh->size) {
		if (child < hh->size && (hh->heapArray[child] > hh->heapArray[child + 1]))
			child++;
		if (temp <= hh->heapArray[child])
			break;
		else {
			hh->heapArray[parent] = hh->heapArray[child];
			parent = child;
			child *= 2;
		}
	}
	hh->heapArray[parent] = temp;
	return item;
}

