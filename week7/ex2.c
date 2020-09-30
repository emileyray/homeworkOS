#include <stdio.h>

int main() {
	int N;
	printf("Print the size of the array\n");
	printf(">");
	scanf_s("%d", &N);
	int* data;
	data = (int*)calloc(N, sizeof(int));
	for (int i = 0; i < N; i++) {
		*(data + i) = i;
	}
	for (int i = 0; i < N; i++) {
		printf("%d ", *(data + i));
	}
	free(data);
	system("Pause");
	return 0;
}