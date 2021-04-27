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


///////////////////////
//    PROTOTYPES     //
///////////////////////
int minDistance(vector<int> dist, int V, vector<bool> sptSet);
void printSolution(vector<int> dist, int V, int n, vector<int> parent);
void printPath(vector<int> parent, int j);
void dijkstra(vector<vector<int>> graph, int V, int src);
vector<string> split(const string& str, const string& delim);


//Where all the fun begins 
int main(int argc, char* argv[])
{
	try {
		if (argc < 3) // we need 4 files in order to run this program.
			// Tell the user what went wrong. 
			cout << "\nUsage: " << argv[0] << "Please enter the following CMD Line arguments. <adjacencyMatrix> <sourceVertexNumber> <destinationVertexNumber>    \n";
		else {
			//here is where we will read in the actual cmd line arguments.

			string matrix = argv[1];     //read in the file 

			vector<vector<int>> adj;     //where the adjacentcy matrix is born 


			fstream file;
			string temp, headers;
			file.open(matrix);       //open the file from the cmd line

			if (file)  //check to be sure that the file opens 
			{
				//this will read in the header line 
				getline(file, headers, '\n');


				while (!file.eof())  //while we are not at the end of the file
				{
					vector<int> line;
					//this will get the first letter that is read in on each line 
					getline(file, temp, '\n'); //get the header line 
					auto inputs = split(temp, " "); //split on space 

					if (!temp.empty())   //make sure that there is actually data where we are looking 
					{
						inputs.erase(inputs.begin()); //gets rid of the letter at the beginning of the line

						for (string str : inputs) //goes through each inputs 
						{
							if (str[0] == '-')  //checks to see if a negative
							{
								line.push_back(0);  //make it a zero if it is negative

							}
							else
							{
								line.push_back(stoi(str));  //if not negative add the number to the vector 
							}
						}
					}
					adj.push_back(line);  //add all the data to the adjacency matrix 

				}
				dijkstra(adj, adj[0].size(), stoi(argv[2]));   //where all the math happens 

			}
			else
			{
				cout << "The file was not opened. Please try again. \n";  //sad boi hours 
			}

		}

	}
	catch (exception e) {
		cout << "Something very bad happened. I would be more descriptive but you must have messed something up pretty bad. :( \n";  //sad boi hours 
	}

	return 0; //bye bye 
}


// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(vector<int> dist, int V, vector<bool> sptSet)
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array
void printSolution(vector<int> dist, int V, int n, vector<int> parent)
{
	int src = 0;
	printf("Vertex\t \tDistance\tPath");
	for (int i = 1; i < V; i++)
	{
		printf("\n%d -> %d \t\t %d\t\t%d ",
			src, i, dist[i], src);
		printPath(parent, i);
	}
}

// Function to print shortest
// path from source to j
// using parent array
void printPath(vector<int> parent, int j)
{
	// Base Case : If j is source
	if (parent[j] == -1)
		return;

	printPath(parent, parent[j]);

	printf("%d ", j);
}

// Function that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
//found at https://www.geeksforgeeks.org/c-program-for-dijkstras-shortest-path-algorithm-greedy-algo-7/
void dijkstra(vector<vector<int>> graph, int V, int src)
{
	vector<int> dist(V); // The output array. dist[i] will hold the shortest
	// distance from src to i

	vector<bool> sptSet(V); // sptSet[i] will be true if vertex i is included in shortest
	// path tree or shortest distance from src to i is finalized

	vector<int> parent(V);

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
	{
		parent[0] = -1;
		dist[i] = INT_MAX;
		sptSet[i] = false;
	}

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++) {
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in the first iteration.
		int u = minDistance(dist, V, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from
			// u to v, and total weight of path from src to v through u is
			// smaller than current value of dist[v]
			if (!sptSet[v] && graph[u][v] &&
				dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}

	// print the constructed distance array
	printSolution(dist, V, V, parent);
}


// Found at: https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
//used to read in the data and split on a specific delimeter
vector<string> split(const string& str, const string& delim)
{
	vector<string> tokens;
	size_t prev = 0, pos = 0;
	do
	{
		pos = str.find(delim, prev);
		if (pos == string::npos) pos = str.length();
		string token = str.substr(prev, pos - prev);
		if (!token.empty()) tokens.push_back(token);
		prev = pos + delim.length();
	} while (pos < str.length() && prev < str.length());
	return tokens;
}
