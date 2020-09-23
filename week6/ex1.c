#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
	The output of the program:
	Enter the total amount of processes (up to 20): 3

	Enter Process Arrival Time
	P[1]: 5
	P[2]: 3
	P[3]: 7

	Enter Process Burst Time
	P[1]: 20
	P[2]: 5
	P[3]: 10

	Process         Arrival Time    Waiting Time    Burst Time      TurnaroudTime
	P[2]            3               0               5               8
	P[1]            5               3               20              23
	P[3]            7               21              10              31
	Completion Time: 38
	Average Waiting Time: 8.000000
	Average Turnaround Time: 24.666667

*/

void swap(int* first, int* second) { //for swapping
	int temp;
	temp = *first;
	*first = *second;
	*second = temp;
}

int main() {
	int N, arrive[20], burst[20]; //storing data
	int index[20];
	printf("Enter the total amount of processes (up to 20): "); //getting data
	scanf_s("%d", &N);

	printf("\nEnter Process Arrival Time\n");
	for (int i = 0; i < N; i++) {
		index[i] = i + 1;
		printf("P[%d]: ", i + 1);
		scanf_s("%d", &arrive[i]);
	}

	printf("\nEnter Process Burst Time\n");
	for (int i = 0; i < N; i++) {
		printf("P[%d]: ", i + 1);
		scanf_s("%d", &burst[i]);
	}

	for (int i = 0; i < N; i++) { //here i arrange according to the arrival time
		for (int j = 0; j < N - 1; j++) {
			if (arrive[j] > arrive[j + 1]) {
				swap(&arrive[j], &arrive[j + 1]);
				swap(&burst[j], &burst[j + 1]);
				swap(&index[j], &index[j + 1]);
			}
		}
	}

	int wait[20]; //here i count waiting from the very beginning
	wait[0] = arrive[0]; 
	double avWait = 0;
	for (int i = 1; i < N; i++) { //we wait either for arriving or for the previous process to be done
		wait[i] = wait[i - 1] + burst[i - 1] > arrive[i] ? wait[i - 1] + burst[i - 1] : burst[i - 1];
		avWait = avWait + wait[i] - arrive[i];
	}
	avWait = avWait / N;

	int turnAround[20];
	double avTurnAround = 0;
	for (int i = 0; i < N; i++) { //calculating TunrAround time
		turnAround[i] = wait[i] + burst[i] - arrive[0];
		avTurnAround = avTurnAround + turnAround[i];
	}
	avTurnAround = avTurnAround / N;

	printf("\nProcess\t\tArrival Time\tWaiting Time\tBurst Time\tTurnaroudTime"); //printing everythin
	for (int i = 0; i < N; i++) {
		printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d", index[i], arrive[i], wait[i] - arrive[i], burst[i], turnAround[i]); //the time of waiting here starts from arriving point
	}

	printf("\nCompletion Time: %d", turnAround[N - 1] + arrive[N - 1]);
	printf("\nAverage Waiting Time: %f", avWait);
	printf("\nAverage Turnaround Time: %f", avTurnAround);

	return 0;
}

