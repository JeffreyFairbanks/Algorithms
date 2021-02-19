#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<stdio.h>
#include<limits.h>
  

using namespace std;


/* A naive recursive implementation that simply
follows the optimal substructure property.
Code Adapted with help from Corbin, Venkatesan Prabu, Yasin Zafar and Kyle Duncan. */



/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Function Prototypes                                     ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
int MatrixChainOrder(int p[], int i, int j);
void printParenthesis(int i, int j, int n, int* bracket, char& name);


int main(int argc, char* argv[])   //gives us those nice cmd line arguments!
{
	if (argc < 2) // argc should be 2 for correct execution argv[0] is the executable name, argv[1+] are the  
		// We print argv[0] assuming it is the program name
		cout << "Usage: " << argv[0] << " <RequiredParameter1>\nArguements in angled brackets '<, >' are required, while arguements in square brackets '[, ]' are not.\n";
	else {
		// Do something if the second arguement is stated, like open a file.
		fstream file(argv[1]); //Argv[1] is the name if the file.
		if (file.is_open()) {   //open the file
          			// Where we actually do the work :) 

			const int n = argc - 2;
			int* arr = new int[n + 1];            //dynamically allowcating array
			for (int i = 1; i - 1 <= n; i++)
			{
				arr[i - 1] = stoi(argv[i]);         //incriment through and put into the array.. 
			}

       int nsize = sizeof(arr) / sizeof(arr[0]);   
			 std::cout << "Minimum number of multiplications is %d ", MatrixChainOrder(arr, 1, nsize);;               //call our function so that we can let the real fun begin!
			// std::cout << " Parenthesis: " << printParenthesis(1, n - 1, n, (int*)bracket, name);                          //have to figure out how to call this....

      std::cin.get();     //pause for effect
			file.close();       // close our file cause we about to be out!

		}
		else {
			cout << "The file \"" << argv[1] << "\" cannot be opened.\n";   //sad boi hours 
			return 100; // 100 is my Corbin's personal error code for when a file cannot be opened. 
		}
		return -1; // -1 is Corbin's personal error code that specifies that too few arguements are reached.
	}
}

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Functions                                               ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

   //TAKEN WITH HELP FROM https://www.wikitechy.com/technology/python-programming-matrix-chain-multiplication/
			//and help from https://www.geeksforgeeks.org/printing-brackets-matrix-chain-multiplication-problem/ 
// Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int min = INT_MAX;
	int count;

	//int bracket[j][j];

	// place parenthesis at different places between first
	// and last matrix, recursively calculate count of
	// multiplications for each parenthesis placement and
	// return the minimum count
	for (k = i; k < j; k++)
	{
		count = MatrixChainOrder(p, i, k) +
			MatrixChainOrder(p, k + 1, j) +
			p[i - 1] * p[k] * p[j];

		if (count < min)
			min = count;
	}

	// Return minimum count
	return min;
}


// Function for printing the optimal
// parenthesization of a matrix chain product
void printParenthesis(int i, int j, int n, int* bracket, char& name)
{
	// If only one matrix left in current segment
	if (i == j) {
		cout << name++;
		return;
	}

	cout << "(";

	// Recursively put brackets around subexpression
	// from i to bracket[i][j].
	// Note that "*((bracket+i*n)+j)" is similar to
	// bracket[i][j]
	printParenthesis(i, *((bracket + i * n) + j), n,
		bracket, name);

	// Recursively put brackets around subexpression
	// from bracket[i][j] + 1 to j.
	printParenthesis(*((bracket + i * n) + j) + 1, j, n,
		bracket, name);
	cout << ")";
}


