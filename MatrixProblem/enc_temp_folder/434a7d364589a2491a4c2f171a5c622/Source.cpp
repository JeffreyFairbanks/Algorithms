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
void ParenthesisOptimization(int** arr, int i, int j);

int main(int argc, char* argv[])  //gives us those nice cmd line arguments!
{
	try {
		if (argc <= 2) // argc should be 2 for correct execution
			// We print argv[0] assuming it is the program name
			cout << "\nUsage: " << argv[0] << " <Matrix Size1> <Matrix Size2> ...[Matrix SizeN]\nArguements in angled brackets '<, >' are required, while arguements in square brackets '[, ]' are not.\n";
		else {
			//start the work 
			const int n = argc - 2;

			int* arr = new int[n + 1];         //dynamically allowcating array


			for (int i = 1; i - 1 <= n; i++)
			{
				arr[i - 1] = stoi(argv[i]);        //incriment through and put into the array..
			}


			std::cout << "Minimum number of multiplications is: " << MatrixChainOrder(arr,1, n);               //call our function so that we can let the real fun begin!
		  std::cout << endl;

		}
	}
	catch (exception e) {
		cout << "You done messed up... Please make sure you are entering integers for the matrix size!";
	}

	std::cin.get();     //pause for effect
	return 0;
}

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Functions                                               ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

  // TAKEN WITH HELP FROM https://www.wikitechy.com/technology/python-programming-matrix-chain-multiplication/
	//		and help from https://www.geeksforgeeks.org/printing-brackets-matrix-chain-multiplication-problem/ 
 //Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int MatrixChainOrder(int p[], int i, int j)
{
	if (i == j)
		return 0;
	int k;
	int min = INT_MAX;  //make sure that nothing is smaller when we first setup this min value
	int count;

	// place parenthesis at different places between first
	// and last matrix, recursively calculate count of
	// multiplications for each parenthesis placement and
	// return the minimum count
	for (k = i; k < j; k++)
	{
		count = MatrixChainOrder(p, i, k) +   //recursive functions here
			MatrixChainOrder(p, k + 1, j) +
			p[i - 1] * p[k] * p[j];

		if (count < min)             //make sure that we grab the smallest 
			min = count;
	}

	std::cout << endl;
	std::cout << "Optimalization of the Parenthesis is: ", ParenthesisOptimization(&p, 1, j);         // tell the user what the best parenthesis layout is. 
	//??????????


	// Return minimum count
	return min;
}



/// <summary>
/// This function is here in order to show the user the optimal places that the parenthesis should be.
/// </summary>
/// <param name="arr"> This is our array that was read in from the cmd line arguments. </param>
/// <param name="i"> incrimentor i </param>
/// <param name="j"> incrimentor j </param>
void ParenthesisOptimization(int **arr, int i, int j)
{
	if (i == j)
	{
		std::cout << "A" << i;                                    //A because good effort.
	}
	else
	{
		std::cout << "(";                                          //put that open parenthesis (:
		ParenthesisOptimization(arr, i, arr[i][j]);          //recursively call with different indexes 
		ParenthesisOptimization(arr, arr[i][j] + 1, j);      //recursively call with incrimented value
		std::cout << ")";                                         //put that closed parenthesis :)
	} 

}


