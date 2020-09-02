#include <stdio.h>

void swap(int *first, int *second){
	int temp = *first;
	*first = *second;
	*second = temp;
}

int* bubble_sort(int* arr, int size){
	int *r = arr;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size - 1; j++){
			if (r[j] > r[j + 1]){
				swap(&r[j], &r[j + 1]);
			}
		}
	}
	return r;
}

int main(){

	int A[5] = { 5, 4, 2, 1, 3 };
	int *B = bubble_sort(A, 5);

	for (int i = 0; i < 5; i++){
		printf("%d ", B[i]);
	}

	//system("Pause");

	return 0;
}
