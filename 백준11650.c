/*
2차원 평면 위의 점 N개의 좌표를 입력받고,
그 점들을 x좌표가 증가하는 순으로. x좌표가 같다면 y좌표가 증가하는 순으로 정렬 후 출력.
(x, y) 순서쌍이 흐트러지지 않게 x좌표 기준으로 퀵정렬한 다음에 y좌표 기준으로 퀵정렬 함.
그 내용은 128~ 138 라인.
*/
#include <stdio.h>
#include <stdlib.h>
# define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )

typedef struct location {
	int x, y;
}dot;

/* 1. 피벗을 기준으로 2개의 부분 리스트로 나눈다.
 2. 피벗보다 작은 값은 모두 왼쪽 부분 리스트로, 큰 값은 오른쪽 부분 리스트로 옮긴다.
 2개의 비균등 배열 list[left...pivot-1]와 list[pivot+1...right]의 합병 과정 
(실제로 숫자들이 정렬되는 과정) */
int partition_x(dot list[], int left, int right) {
	dot pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left]; // 정렬할 리스트의 가장 왼쪽 데이터를 피벗으로 선택(임의의 값을 피벗으로 선택)

						/* low와 high가 교차할 때까지 반복(low<high) */
	do {
		/* list[low]가 피벗보다 작으면 계속 low를 증가 */
		do {
			low++; // low는 left+1 에서 시작
		} while (low <= right && list[low].x<pivot.x); //문제가 발생한다면 여기를 의심

		/* list[high]가 피벗보다 크면 계속 high를 감소 */
		do {
			high--; //high는 right 에서 시작
		} while (high >= left && list[high].x>pivot.x);

		// 만약 low와 high가 교차하지 않았으면 list[low]를 list[high] 교환
		if (low<high) {
			temp = list[low];
			list[low] = list[high];
			list[high] = temp;
		}
	} while (low<high);

	// low와 high가 교차했으면 반복문을 빠져나와 list[left]와 list[high]를 교환
	temp = list[left];
	list[left] = list[high];
	list[high] = temp;

	// 피벗의 위치인 high를 반환
	return high;
}

void quick_sort_x(dot list[], int left, int right) {

	/* 정렬할 범위가 2개 이상의 데이터이면(리스트의 크기가 0이나 1이 아니면) */
	if (left<right) {
		// partition 함수를 호출하여 피벗을 기준으로 리스트를 비균등 분할 -분할(Divide)
		int q = partition_x(list, left, right); // q: 피벗의 위치

											  // 피벗은 제외한 2개의 부분 리스트를 대상으로 순환 호출
		quick_sort_x(list, left, q - 1); // (left ~ 피벗 바로 앞) 앞쪽 부분 리스트 정렬 -정복(Conquer)
		quick_sort_x(list, q + 1, right); // (피벗 바로 뒤 ~ right) 뒤쪽 부분 리스트 정렬 -정복(Conquer)
	}
}

int partition_y(dot list[], int left, int right) {
	dot pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left]; // 정렬할 리스트의 가장 왼쪽 데이터를 피벗으로 선택(임의의 값을 피벗으로 선택)

						/* low와 high가 교차할 때까지 반복(low<high) */
	do {
		/* list[low]가 피벗보다 작으면 계속 low를 증가 */
		do {
			low++; // low는 left+1 에서 시작
		} while (low <= right && list[low].y < pivot.y); //문제가 발생한다면 여기를 의심

														  /* list[high]가 피벗보다 크면 계속 high를 감소 */
		do {
			high--; //high는 right 에서 시작
		} while (high >= left && list[high].y>pivot.y);

		// 만약 low와 high가 교차하지 않았으면 list[low]를 list[high] 교환
		if (low<high) {
			temp = list[low];
			list[low] = list[high];
			list[high] = temp;
		}
	} while (low<high);

	// low와 high가 교차했으면 반복문을 빠져나와 list[left]와 list[high]를 교환
	temp = list[left];
	list[left] = list[high];
	list[high] = temp;

	// 피벗의 위치인 high를 반환
	return high;
}

void quick_sort_y(dot list[], int left, int right) {

	/* 정렬할 범위가 2개 이상의 데이터이면(리스트의 크기가 0이나 1이 아니면) */
	if (left<right) {
		// partition 함수를 호출하여 피벗을 기준으로 리스트를 비균등 분할 -분할(Divide)
		int q = partition_y(list, left, right); // q: 피벗의 위치
												// 피벗은 제외한 2개의 부분 리스트를 대상으로 순환 호출
		quick_sort_y(list, left, q - 1); // (left ~ 피벗 바로 앞) 앞쪽 부분 리스트 정렬 -정복(Conquer)
		quick_sort_y(list, q + 1, right); // (피벗 바로 뒤 ~ right) 뒤쪽 부분 리스트 정렬 -정복(Conquer)
	}
}

int main() {
	int n, i;
	dot* dots;
	scanf("%d", &n);
	dots = (dot*)malloc(sizeof(dot)*n);

	for (i = 0; i < n; i ++ ) {
		scanf("%d %d", &dots[i].x, &dots[i].y);
	}

	quick_sort_x(dots, 0, n - 1);

	int start = 0, finish, temp;
	while (start < n) {
		temp = start;
		while((dots[temp].x == dots[temp + 1].x) && (&dots[temp + 1] != NULL))
			temp++;
		finish = temp;
		quick_sort_y(dots, start, finish);
		start = finish + 1;
	}

	for (i = 0; i < n; i++) {
		printf("%d %d\n", dots[i].x, dots[i].y);
	}

	free(dots);
	return 0;
}