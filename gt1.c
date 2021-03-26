/* gt1.c
 * Random nondirected graph generator for GT1 problem
 * By Ken Callow
 * 2021
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char * argv[]){
	if (argc != 4) {
		printf("Usage: gt1 n m k\nn is size of V\nm is size of E\nk is size of vertex cover\n");
		return -1;
	}

	int i, j, n, m, k, nn;
	time_t t;
	srand(time(&t));

	n = atoi(argv[1]); // Number of vertices
	m = atoi(argv[2]); // Number of edges
	k = atoi(argv[3]); // Size of vertex cover
	nn = n*(n+1)/2;    // The set of possible nondirected edges is a triangular matrix thus the size of the solution space is the nth triangular number 
	// If the desired number of edges exceeds the maximum possible number, set it to the maximum possible number
	if (m > nn)
		m = nn;
	
	// Print the randomly generated problem
	printf("GT1\n");
	for (i = 1; i < argc; i++) 
		printf("%s\n", argv[i]);


	// If n or m are 0 there's nothing else to do
	if (n == 0) return 0;
	if (m == 0) return 0;

	// Create a boolean table representing every possible edge
	char decide[nn];
	for (i = 0; i < nn; i++)
		decide[i] = 0;

	// Fill the graph with m randomly selected edges
	i = 0;
	while (m) {
		i = rand() % nn;
		if (!decide[i]) {
			decide[i] = 1;
			m--;
		}
	}

	// Print out the randomly selected edges
	for (i = 0; i < n; i++)
		for (j = i; j < n; j++)
			if (decide[i*n + j - i*(i+1)/2]) {
				printf("%d,%d\n", i, j);
			}

	return 0;
}
