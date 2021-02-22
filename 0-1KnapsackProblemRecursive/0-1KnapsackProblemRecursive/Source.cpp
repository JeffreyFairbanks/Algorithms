// JEFFREY FAIRBANKS

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

///////////////////////
//    PROTOTYPES     //
///////////////////////
int knapsack(vector <int> weight, vector <int> value, int maxweight, int index);



int main(int argc, char* argv[])
{
	try {
		if (argc < 4) // we need 5 files in order to run this program.
			//the argv[0] should be the file name.
			cout << "\nUsage: " << argv[0] << "Please enter the following CMD Line arguments. {Program}.exe <numberOfItemsInFiles> <maximumWeightOfKnapsack> <weightsFile> <valuesFile>    \n";
		else {
			//here is where we will read in the actual cmd line arguments.

			//grabbing the number of items in the file.
			cout << "Number of items: " << argv[1] << endl;
			string numberOfItemsInFile = argv[1]; // puts the number of items into a variable

			//grabbing the maximum Weight Of the Knapsack value
			cout << "Maximum Weight Of The Knapsack: " << argv[2] << endl; //puts the maximumWeightOfKnapsack into a variable
			string maximumWeightOfKnapsack = argv[2];

			//now we will want to open some files and put them into vectors here. This will help us grab arvg[3] and argv[4].
			vector <int> weight(stoi(numberOfItemsInFile)), value(stoi(numberOfItemsInFile));

			fstream file(argv[3]); //Argv[3] is the name of the weights File.			
				if (file.is_open())
			  {
				 //want to use vectors for sake of simplicity of the function we want to use.
				  cout << "Enter weights of each of the items: ";		

					 for (int i = 0; i < stoi(numberOfItemsInFile); i++) 
					 {
							file >> weight[i];
							cout << weight[i] << " ";
					 }
				 file.close();
				}
				else 
				{
					cout << "The file \"" << argv[3] << "\" cannot be opened.\n";
          return 100; // 100 is Corbin;s personal error code for when a file cannot be opened. 
        }

			//Now we wil open the values file.

				fstream files(argv[4]); //Argv[4] is the name of the values File.
				if (files.is_open())
				{
					//Process the file here.
					//want to use vectors for sake of simplicity of the function we want to use.
					cout << "\n Enter weights of each of the items: ";
					for (int j = 0; j < stoi(numberOfItemsInFile); j++)
					{
						files >> value[j];
						cout << value[j] << " ";
					}
					files.close();
				}
				else
				{
					cout << "The file \"" << argv[4] << "\" cannot be opened.\n";
					return 100; // 100 is Corbin;s personal error code for when a file cannot be opened. 
				}

			//now we will call the function so that it can be displayed to the user!
			cout << "Maximum value of bag is: " << knapsack(weight, value, stoi(maximumWeightOfKnapsack), stoi(numberOfItemsInFile));  //still need to pass in the correct weight and values from the above arrays

		}
	}
	catch (exception e) {
		cout << "Something very bad happened. I would be more descriptive but you must have messed something up pretty bad. :( \n";
	}

	cout << "Press Enter to end the program. \n";
	cin.get();
	return 0;
}


/// <summary>
/// 
/// </summary>
/// <param name="weight"></param>
/// <param name="value"></param>
/// <param name="maxweight"></param>
/// <param name="index"></param>
/// <returns></returns>
/// adapted from: https://github.com/kothariji/Dynamic_Programming_Journey/blob/main/DAY-01/0-1%20Knapsack%20Recursion.cpp 
int knapsack(vector <int> weight, vector <int> value, int maxweight, int index)
{
	//base condition
	if ((index < 0) || (maxweight <= 0))
		return 0;

	if (weight[index] <= maxweight)
		return max(value[index] + knapsack(weight, value, maxweight - weight[index], index - 1), knapsack(weight, value, maxweight, index - 1));

	else
		return knapsack(weight, value, maxweight, index - 1);
}