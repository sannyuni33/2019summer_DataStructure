/*
자료구조에서 배웠던 최소 힙 응용해서 해결 !
오랜시간이 걸리진 않았음.
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
	while (i != 1 && x < hh->heapArray[i / 2]) {
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
	printf("%d\n", item);

}