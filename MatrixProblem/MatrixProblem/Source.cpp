#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<stdio.h>
#include<limits.h>
  

using namespace std;


/* A naive recursive implementation that simply
follows the above optimal substructure property */



/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Function Prototypes                                     ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
int MatrixChainOrder(int p[], int i, int j);

int main(int argc, char* argv[])
{
	if (argc < 2) // argc should be 2 for correct execution argv[0] is the executable name, argv[1+] are the  
		// We print argv[0] assuming it is the program name
		cout << "Usage: " << argv[0] << " <RequiredParameter1>\nArguements in angled brackets '<, >' are required, while arguements in square brackets '[, ]' are not.\n";
	else {
		// Do something if the second arguement is stated, like open a file.
		fstream file(argv[1]); //Argv[1] is the name if the file.
		if (file.is_open()) {
          			// Where we actually do the work :) 
                    int arr[] = { 1, 2, 3, 4, 3 };               //NEED TO HAVE THEM ACTUALLY PASS IN THE VALUES FROM THE CMD LINE
                    int n = sizeof(arr) / sizeof(arr[0]);        //MORE CMD LINE STUFFS

                    std::cout << "Minimum number of multiplications is %d ", MatrixChainOrder(arr, 1, n - 1);
                    cin.get();

			file.close();
		}
		else {
			cout << "The file \"" << argv[1] << "\" cannot be opened.\n";
			return 100; // 100 is my personal error code for when a file cannot be opened. 
		}
		return -1; // -1 is my personal error code that specifies that too few arguements are reached.
	}
}

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Functions                                               ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

   //TAKEN WITH HELP FROM https://www.wikitechy.com/technology/python-programming-matrix-chain-multiplication/
  // Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
int MatrixChainOrder(int p[], int i, int j)
{
  if (i == j)
    return 0;
  int k;
  int min = INT_MAX;
  int count;

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