// JEFFREY FAIRBANKS
#define  _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include <limits.h>
#include <stdio.h>

#include "Dijkstra.h"

using namespace std;

///  <summary> 
///  A C++ program for Dijkstra's single source shortest path algorithm.
///  The program is for adjacency matrix representation of the graph
///  Done with help from: https://www.geeksforgeeks.org/c-program-for-dijkstras-shortest-path-algorithm-greedy-algo-7/
///  Collaborated with Kyle Duncan
///  </summary>



// Number of vertices in the graph
#define NODES_MAX 100
#define FILE_MAX 8192
#define INFINITY 9999



///////////////////////
//    PROTOTYPES     //
///////////////////////
int input_from_file(char* filename, struct Dijkstra_input* input);
void print_dijkstra_ouput(struct Dijkstra_output* output);
string Semicolin2Space(string text);


//Where all the fun begins 
int main(int argc, char* argv[])
{
	struct Dijkstra_input input;

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

				////this will get the first letter that is read in on each line 
				//file >> temp;



				input_from_file(argv[1], &input);
				input.starting_node = atoi(argv[2]);
				input.target_node = atoi(argv[3]);

				struct Dijkstra_output output;
				output = dijkstra(&input);

				print_dijkstra_ouput(&output);

				cin.get();

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


int input_from_file(char* filename, struct Dijkstra_input* input) {
	char buffer[FILE_MAX];
	char* record, * line;
	FILE* fstream;
	int i = 0, j = 0;
	int columns = 0;
	bool columns_found = false;

	fstream = fopen(filename, "r");
	if (fstream == NULL) {
		printf("\nFile opening failed when reading input.");
		return -1;
	}


	while ((line = fgets(buffer, sizeof(buffer), fstream)) != NULL) {
		record = strtok(line, " ");
		while (record != NULL) {
			input->adjacency[i][j] = atoi(record);
			j++;
			record = strtok(NULL, " ");
		}
		if (!columns_found) {
			columns = input->nodes = j;
			columns_found = true;
		}
		else if (j < columns)
			printf("\nLess columns than %d in %dª row, they will be treated as 0", columns, i + 1);
		else if (j > columns)
			printf("\nMore columns than %d in %dª row, the rest will be ignored", columns, i + 1);
		j = 0;
		++i;
	}

	return 1;
}

void print_dijkstra_ouput(struct Dijkstra_output* output) {
	printf("\nThe Dijkstra shortest path is: %d", output->path[0]);
	for (int i = 1; i < output->size; i++) {
		printf("-->%d", output->path[i]);
	}
	printf("\nPath total distance: %d", output->distance);
}


