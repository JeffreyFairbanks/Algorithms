/// JEFFREY FAIRBANKS

#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<stdio.h>
#include<limits.h>
#include<vector>
  

using namespace std;

/* A naive recursive implementation that simply follows the optimal substructure property.
Code Adapted with help from Corbin, Venkatesan Prabu, Yasin Zafar and Kyle Duncan. */


/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Function Prototypes                                     ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
void matrixChainOrder(int p[], int n);                                            //Used to multiply the matrix together
void printParenthesis(int i, int j, int n, int** bracket, char& name);            //Used to print out the parenthesis in the most optimal mannor
void printMatrixTable(int** arr, int n);                                          //Used to print out the Matrix tables


int main(int argc, char* argv[])  //gives us those nice cmd line arguments!
{
  if (argc > 1) // If there is more than 1 arg, then there is enough.
  {

	  try {
		//start the work 
			
    //we want to make a vector here to capture the values from the user.
      vector<int> userInput;  //vectors are a little easier to use so POG


      
			for (int i = 1; i < argc; i++)   //this nice for loop will grab the data from the user that was passed through the command line
			{
        string input = argv[i];                 //grabs from the cmd line 
        userInput.push_back(stoi(input));       //add each to the end of the vector
      }

      int* arr = new int[userInput.size() - 1];  // make a new array that will be used in order to pass to the functiions. 
                                                  // out functions recquire a **arr so this accomplishes that for us.

      for (int i = 0; i < userInput.size(); i++)  //for loop puts the vector into the int* to accomplish what was said above.
      {
        arr[i] = userInput[i];
      }

			matrixChainOrder(arr, userInput.size());               //call our function so that we can let the real fun begin!

		  std::cout << endl;   //add a line so its a little nicer 

		}
    catch (exception e) {
      cout << "You done messed up... Please make sure you are entering integers for the matrix size!";   //you done goofed my bro 
    }

	}
	std::cin.get();     //pause for effect
	return 0;           // Thank you for coming
}

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Functions                                               ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

/// <summary>
/// Multiply the matrix. 
/// This was adapted from: https://tutorialspoint.dev/algorithm/dynamic-programming-algorithms/printing-brackets-matrix-chain-multiplication-problem
/// </summary>
/// <param name="p"> This is our **arr passed in </param>
/// <param name="n"> This is the size of that **arr</param>
void matrixChainOrder(int p[], int n)
{
	//dynamically allowcate double pointer
	int** m = new int*[n];
	int** bracket = new int*[n];

  for (int i = 0; i < n; i++)  //this for loop makes all the values inside the length that we need.
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
   
  cout << "Optimal values \n";     //prints out our optimal values table
  printMatrixTable(m, n);

  cout << "decsision table: \n";    //print out our desicion table 
  printMatrixTable(bracket, n);

	cout << "Optimal Parenthesization is : ";      //tells us what the optimal parenthesization is
	printParenthesis(1, n - 1, n, bracket, name);
	cout << endl;

  cout << "nOptimal Cost is : " << m[1][n - 1];    //tells us what the optimal cost is 
}


/// <summary>
/// Function for printing the optimal parenthesization of a matrix chain product 
/// </summary>
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
/// <param name="arr"> our **arr gets passed in here </param>
/// <param name="n"> The size of that **arr </param>
void printMatrixTable(int **arr, int n)    
{
  for (int i = 0; i < n; i++)
  {
    //bool to see if it already did print
    bool didIPrintThis = false;
    for (int j = 0; j < n; j++)
    {
      if (arr[j][i] > 0)     //begin the print 
      {
        didIPrintThis = true;
        cout << arr[j][i] << "\t";  //print out the array here to the user 

      }
    }
    if (didIPrintThis == true)    //we printed so we leavin!
      cout << "\n";
  }

}