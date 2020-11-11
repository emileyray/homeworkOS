#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int check_resources(int* rqst, int* src, int numOfRec); //checking resources

int main() {
	FILE* input; //inputting file
	char buffer[255];

	input = fopen("input.txt", "r");

	int data[100][100];

	int numOfRes = 0;
	int numOfProc = 0;
	int lineIndex = 0;

	while (fgets(buffer, 255, input)) { //reading the file line by line
		char* line = strtok(strdup(buffer), "\n");

		if (line != NULL) {
			numOfRes = strlen(line) / 2 + 1;
			for (int i = 0; i < numOfRes; i++) {
				data[lineIndex][i] = line[i * 2] - 48;
			}
			lineIndex++;
		}
	}

	fclose(input);
	
	numOfProc = (lineIndex - 2) / 2;

	int* E; //existing resources
	int* A; //available resources
	int** C; //allocation matrix
	int** R; //request matrix

	E = malloc(numOfRes * sizeof(int));
	A = malloc(numOfRes * sizeof(int));
	C = malloc(numOfProc * sizeof(int*));
	R = malloc(numOfProc * sizeof(int*));

	for (int i = 0; i < numOfProc; i++){
		C[i] = malloc(numOfRes * sizeof(int));
		R[i] = malloc(numOfRes * sizeof(int));
	}

	for (int i = 0; i < lineIndex; i++) { //saving all the data into the arrays
		for (int j = 0; j < numOfRes; j++) {
			if (i == 0) {
				E[j] = data[i][j];
			}

			if (i == 1) {
				A[j] = data[i][j];
			}
			if (i > 1 && i < numOfProc + 2) {
				C[i - 2][j] = data[i][j];
			}
			if (i >= numOfProc + 2) {
				R[i - 2 - numOfProc][j] = data[i][j];
			}
		}
	}

	int* finished = malloc(numOfProc * sizeof(bool)); //finished proc

	for (int i = 0; i < numOfProc; i++) {
		finished[i] = false;
	}

	bool terminating = true;

	while (terminating) { //checking the resources for unfinished proc
		terminating = false;
		for (int i = 0; i < numOfProc; i++) {
			if (!finished[i] && check_resources(R[i], A, numOfRes)) {
				for (int j = 0; j < numOfRes; j++) {
					A[j] += C[i][j];
				}
				finished[i] = true;
				terminating = true;
			}
		}
	}

	FILE* output = fopen("output.txt", "w"); //output file
	bool deadlocked = false;

	for (int i = 0; i < numOfProc; i++) { //results
		if (!finished[i]) {
			deadlocked = true;
			fprintf(output, "Process %d deadlocked.\n", i);
		}
	}

	if (!deadlocked) { //results
		fprintf(output, "No deadlock detected.\n");
	}

	fclose(output);

	return 0;
}

int check_resources(int* rqst, int* src, int numOfRec) {
	for (int i = 0; i < numOfRec; ++i)
		if (rqst[i] > src[i])
			return 0;
	return 1;
}