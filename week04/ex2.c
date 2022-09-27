#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

// Calculate the dot product of the vectors u and v from the component [start] till the component [end] exclusively.
int dotprod(int u[], int v[], int start, int end){

	int result = 0;
	
	for (int i=start; i<end; i++){
		result += u[i] * v[i];
	}

	return result;
}


int main(void) {
	int u[120], v[120];

	// initializing random number generator
	time_t t;
	srand((unsigned) time(&t));
	
	// populate the vectos
	for (int i = 0; i < 120; i++) {
		u[i] = rand() % 100;
		v[i] = rand() % 100;
	}

	int n; // number of processes
	printf("Enter number of processes: ");
	scanf("%d", &n);

	FILE* outFile = fopen("temp.txt", "w");
	FILE* inFile = fopen("temp.txt", "r");

	// Calculating components of the dot product in equally divided processes
	for (int i = 0; i < n; i++) {
		pid_t pid = fork();
		if (pid == 0) {
			int component = dotprod(u, v, (120 / n) * i, (120 / n) * i + (120 / n) - 1);
			fprintf(outFile, "%d\n", component);
			exit(0);
		}
	}

	// block the parent process until all the child precesses are finished
	for (int i = 0; i < n; i++) wait(NULL);

	// calculate the sum of the components from the same file
	int answer = 0; 
	for (int i = 0; i < n; i++) {
		int component;
		fscanf(inFile, "%d", &component);
		answer += component;
	}

	printf("The dot product = %d\n", answer);

	return EXIT_SUCCESS;
}

/*
Example:

Assume that
u = [u1, u2, u3, u4]
v = [v1, v2, v3, v4]
k=1 ==> n = 2 processes

Equally distribute the dot product calculation task. We have multiple ways to distribute the task equally.

1- A possible task distribution is as follows:

First process will calculate dot product for the first two components
Second process will calculate dot product for the last two components

The computation result of the first process is u1 * v1 + u2 * v2 ==> c1
The computation result of the second process is u3 * v3 + u4 * v4 ==> c2

2- Another possible distribution is as follows:

First process will calculate dot product for the even components
Second process will calculate dot product for the odd components

The computation result of the first process is u2 * v2 + u4 * v4 ==> c1
The computation result of the second process is u1 * v1 + u3 * v3 ==> c2



The file temp.txt will contain as follows: (format is not restricted)
-------------------
c1
c2
-------------------

The "main" process will aggregate all dot product computations of its children
It will read the lines and aggregate.

c1 + c2 ==> result of u * v


*/