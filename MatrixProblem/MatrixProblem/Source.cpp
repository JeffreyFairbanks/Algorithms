#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<stdio.h>
#include<limits.h>
#include<vector>
  

using namespace std;

/* A naive recursive implementation that simply
follows the optimal substructure property.
Code Adapted with help from Corbin, Venkatesan Prabu, Yasin Zafar and Kyle Duncan. */


/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Function Prototypes                                     ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
void matrixChainOrder(int p[], int n);
void printParenthesis(int i, int j, int n, int** bracket, char& name);
void printMatrixTable(int** arr, int n);


int main(int argc, char* argv[])  //gives us those nice cmd line arguments!
{
  if (argc > 1) // If there is more than 1 arg, then there is enough.
  {

	  try {
		//start the work 
			
    //we want to make a vector here to capture the values from the user.
      vector<int> userInput;


      
			for (int i = 1; i < argc; i++)
			{
        string input = argv[i];
        userInput.push_back(stoi(input));
      }

      int* arr = new int[userInput.size() - 1];


      for (int i = 0; i < userInput.size(); i++)
      {
        arr[i] = userInput[i];

      }

			matrixChainOrder(arr, userInput.size());               //call our function so that we can let the real fun begin!

		  std::cout << endl;

		}
    catch (exception e) {
      cout << "You done messed up... Please make sure you are entering integers for the matrix size!";
    }

	}
	std::cin.get();     //pause for effect
	return 0;
}

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Functions                                               ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

/// <summary>
/// ************************************************************
/// </summary>
/// <param name="p"></param>
/// <param name="n"></param>
void matrixChainOrder(int p[], int n)
{
	//dynamically allowcate double pointer
	int** m = new int*[n];
	int** bracket = new int*[n];

  for (int i = 0; i < n; i++)
  {
    m[i] = new int[n];
    bracket[i] = new int[n];
  }

  // cost is zero when multiplying one matrix. 
  for (int i = 1; i < n; i++)
    m[i][i] = 0;

  // L is chain length. 
  for (int L = 2; L < n; L++)
  {
    for (int i = 1; i < n - L + 1; i++)
    {
      int j = i + L - 1;
      m[i][j] = INT_MAX;
      for (int k = i; k <= j - 1; k++)
      {
        // q = cost/scalar multiplications 
        int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (q < m[i][j])
        {
          m[i][j] = q;

          // Each entry bracket[i,j]=k shows 
          // where to split the product arr 
          // i,i+1....j for the minimum cost. 
          bracket[i][j] = k;
        }
      }
    }
  }

  // The first matrix is printed as 'A', next as 'B', 
 // and so on 
  char name = 'A';

  cout << "Optimal values \n";
  printMatrixTable(m, n);

  cout << "decsision table: \n";
  printMatrixTable(bracket, n);

	cout << "Optimal Parenthesization is : ";
	printParenthesis(1, n - 1, n, bracket, name);
	cout << endl;
  cout << "nOptimal Cost is : " << m[1][n - 1];
}


/// <summary>
/// Function for printing the optimal parenthesization of a matrix chain product 
/// </summary>
/// <param name="i"></param>
/// <param name="j"></param>
/// <param name="n"></param>
/// <param name="bracket"></param>
/// <param name="name"></param>
void printParenthesis(int i, int j, int n, int** bracket, char& name)
{
  // If only one matrix left in current segment 
  if (i == j)
  {
    cout << name++;
    return;
  }

  cout << "(";

  // Recursively put brackets around subexpression 
  // from i to bracket[i][j]. 
  // Note that "*((bracket+i*n)+j)" is similar to 
  // bracket[i][j] 
  printParenthesis(i, bracket[i][j], n, bracket, name);

  // Recursively put brackets around subexpression 
  // from bracket[i][j] + 1 to j. 
  printParenthesis(bracket[i][j] + 1, j, n, bracket, name);
  cout << ")";
}


/// <summary>
/// Function in order to print out the Matrix tables for both the Optimal values and Decision Table.
/// </summary>
/// <param name="arr"></param>
/// <param name="n"></param>
void printMatrixTable(int **arr, int n)    //write more about ************************************
{
  for (int i = 0; i < n; i++)
  {
    //bool to see if it already did print
    bool didIPrintThis = false;
    for (int j = 0; j < n; j++)
    {
      if (arr[j][i] > 0)
      {
        didIPrintThis = true;
        cout << arr[j][i] << "\t";

      }
    }
    if (didIPrintThis == true)
      cout << "\n";
  }

}