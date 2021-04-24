// JEFFREY FAIRBANKS

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include <limits.h>
#include <stdio.h>

using namespace std;

///  <summary> 
///  A C++ program for Dijkstra's single source shortest path algorithm.
///  The program is for adjacency matrix representation of the graph
///  Done with help from: https://www.geeksforgeeks.org/c-program-for-dijkstras-shortest-path-algorithm-greedy-algo-7/
///  Collaborated with Kyle Duncan
///  </summary>



// Number of vertices in the graph
#define V 9


///////////////////////
//    PROTOTYPES     //
///////////////////////
int minDistance(int dist[], bool sptSet[]);
void printSolution(int dist[], int n);
void dijkstra(int graph[V][V], int src);


//Where all the fun begins 
int main(int argc, char* argv[])
{
	try {
		if (argc < 3) // we need 4 files in order to run this program.
			// Tell the user what went wrong. 
			cout << "\nUsage: " << argv[0] << "Please enter the following CMD Line arguments. <adjacencyMatrix> <sourceVertex> <destinationVertex>    \n";
		else {
			//here is where we will read in the actual cmd line arguments.

			string matrix = argv[1];

			fstream file;
			string temp, headers;
			file.open(matrix);

			if (file)
			{
				//this will read in the header line 
				getline(file, headers, '\n');

				//this will get the first letter that is read in on each line 
				file >> temp;



			}
			else
			{
				cout << "The file was not opened. Please try again. \n";
			}


			//dijkstra(graph, 0);

		}
	}
	catch (exception e) {
		cout << "Something very bad happened. I would be more descriptive but you must have messed something up pretty bad. :( \n";  //sad boi hours 
	}

	return 0; //bye bye 
}


// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array
void printSolution(int dist[], int n)
{
	printf("Vertex Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d tt %d\n", i, dist[i]);
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
	int dist[V]; // The output array. dist[i] will hold the shortest
	// distance from src to i

	bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
	// path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in the first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from
			// u to v, and total weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
				&& dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array
	printSolution(dist, V);
}



//// driver program to test above function
//int main()
//{
//	/* Let us create the example graph discussed above */
//	int graph[V][V] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
//											{ 4, 0, 8, 0, 0, 0, 0, 11, 0 },
//											{ 0, 8, 0, 7, 0, 4, 0, 0, 2 },
//											{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
//											{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
//											{ 0, 0, 4, 14, 10, 0, 2, 0, 0 },
//											{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
//											{ 8, 11, 0, 0, 0, 0, 1, 0, 7 },
//											{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
//
//	dijkstra(graph, 0);
//
//	return 0;
//}
//
//
//
//a  b  c  d  e  f  g  h  i
//a - 1  4 - 1 - 1 - 1 - 1 - 1  8 - 1
//b  4 - 1  8 - 1 - 1 - 1 - 1 11 - 1
//c - 1  8 - 1  7 - 1  4 - 1 - 1  2
//d - 1 - 1  7 - 1  9 14 - 1 - 1 - 1
//e - 1 - 1 - 1  9 - 1 10 - 1 - 1 - 1
//f - 1 - 1  4 14 10 - 1  2 - 1 - 1
//g - 1 - 1 - 1 - 1 - 1  2 - 1  1  6
//h  8 11 - 1 - 1 - 1 - 1  1 - 1  7
//i - 1 - 1  2 - 1 - 1 - 1  6  7 - 1
