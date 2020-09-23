#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
	This program is a modification of the first one
	The output of the program with the same input data as in the lab slides:

	Enter the total amount of processes (up to 20): 10
	Enter the value of quantum: 3

	Enter Process Arrival Time
	P[1]: 0
	P[2]: 0
	P[3]: 0
	P[4]: 0
	P[5]: 0
	P[6]: 11
	P[7]: 11
	P[8]: 11
	P[9]: 11
	P[10]: 11

	Enter Process Burst Time
	P[1]: 1
	P[2]: 2
	P[3]: 4
	P[4]: 6
	P[5]: 8
	P[6]: 8
	P[7]: 6
	P[8]: 4
	P[9]: 2
	P[10]: 1

	Process         Arrival Time    Waiting Time    Burst Time      TurnaroudTime
	P[1]            0               0               1               1
	P[2]            0               1               2               3
	P[3]            0               24              4               25
	P[4]            0               25              6               28
	P[5]            0               38              8               40
	P[6]            11              29              8               31
	P[7]            11              23              6               26
	P[8]            11              26              4               27
	P[9]            11              10              2               12
	P[10]           11              12              1               13
	Completion Time: 42
	Average Waiting Time: 24.300000
	Average Turnaround Time: 20.600000

	Same data with quantum = 2:

	Process         Arrival Time    Waiting Time    Burst Time      TurnaroudTime
	P[1]            0               0               1               1
	P[2]            0               1               2               3
	P[3]            0               9               4               11
	P[4]            0               24              6               26
	P[5]            0               34              8               36
	P[6]            11              29              8               31
	P[7]            11              27              6               29
	P[8]            11              21              4               23
	P[9]            11              10              2               12
	P[10]           11              12              1               13
	Completion Time: 42
	Average Waiting Time: 22.200000
	Average Turnaround Time: 18.500000

	The same data with quantum = 4:
	Process         Arrival Time    Waiting Time    Burst Time      TurnaroudTime
	P[1]            0               0               1               1
	P[2]            0               1               2               3
	P[3]            0               3               4               7
	P[4]            0               30              6               32
	P[5]            0               32              8               36
	P[6]            11              25              8               29
	P[7]            11              29              6               31
	P[8]            11              12              4               16
	P[9]            11              16              2               18
	P[10]           11              18              1               19
	Completion Time: 42
	Average Waiting Time: 22.100000
	Average Turnaround Time: 19.200000

	The same data with quantum = 5:
	Process         Arrival Time    Waiting Time    Burst Time      TurnaroudTime
	P[1]            0               0               1               1
	P[2]            0               1               2               3
	P[3]            0               3               4               7
	P[4]            0               34              6               35
	P[5]            0               35              8               38
	P[6]            11              27              8               30
	P[7]            11              30              6               31
	P[8]            11              16              4               20
	P[9]            11              20              2               22
	P[10]           11              22              1               23
	Completion Time: 42
	Average Waiting Time: 24.300000
	Average Turnaround Time: 21.000000

	Conclusion: completion time doesn't change, but average waiting and turnaround numbers are less with smaller quantum
*/

void swap(int* first, int* second) { //for swapping
	int temp;
	temp = *first;
	*first = *second;
	*second = temp;
}

int main() {
	int Q;
	int N, arrive[20], burst[20]; //storing data
	int burst1[20]; //will need this later
	int index[20];
	printf("Enter the total amount of processes (up to 20): "); //getting data
	scanf_s("%d", &N);

	printf("Enter the value of quantum: ");
	scanf_s("%d", &Q);

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
		burst1[i] = burst[i];
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

	int time = 0; //time
	int turnAround[20];

	int wait[20]; //here i count waiting from the very beginning
	wait[0] = arrive[0];

	int numOfEx = 0;

	while (numOfEx != N) { //here i divide the precesses and execute them
		for (int i = 0; i < N; i++) { 
			if (time >= arrive[i]) { //execute when it is the time
				if (burst[i] > 0) {
					if (burst[i] <= Q) { 
						numOfEx++;
						wait[i] = time;
						time = time + burst[i];
						turnAround[i] = time;
						burst[i] = burst[i] - Q;
					}
					else {
						burst[i] = burst[i] - Q;
						time = time + Q;
					}
				}
			}
		}
	}
	double avWait = 0;
	for (int i = 0; i < N; i++) { //calculating TunrAround time
		avWait = avWait + wait[i];
	}
	avWait = avWait / N;

	double avTurnAround = 0;
	for (int i = 0; i < N; i++) { //calculating TunrAround time
		turnAround[i] = turnAround[i] - arrive[i];
		avTurnAround = avTurnAround + turnAround[i];
	}
	avTurnAround = avTurnAround / N;

	printf("\nProcess\t\tArrival Time\tWaiting Time\tBurst Time\tTurnaroudTime"); //printing everythin
	for (int i = 0; i < N; i++) {
		printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d", index[i], arrive[i], wait[i] - arrive[i], burst1[i], turnAround[i]); //the time of waiting here starts from arriving point
	}

	printf("\nCompletion Time: %d", time);
	printf("\nAverage Waiting Time: %f", avWait);
	printf("\nAverage Turnaround Time: %f", avTurnAround);

	system("Pause");

	return 0;
}

