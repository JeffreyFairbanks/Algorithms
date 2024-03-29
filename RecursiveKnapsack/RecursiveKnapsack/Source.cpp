// JEFFREY FAIRBANKS
//collaborated with Kyle Duncan

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

///////////////////////
//    PROTOTYPES     //
///////////////////////
int knapsack(vector <int> weight, vector <int> value, int maxweight, int index, int &recursiveTimesCalled, vector<int>& OptimalSolutions);
void readFromCmdLineFile(int argc, char* argv[], string numberOfItemsInFile, string maximumWeightOfKnapsack);



int main(int argc, char* argv[])
{
	try {
		if (argc < 4) // we need 4 files in order to run this program.
			// Tell the user what went wrong. 
			cout << "\nUsage: " << argv[0] << "Please enter the following CMD Line arguments. <numberOfItemsInFiles> <maximumWeightOfKnapsack> <weightsFile> <valuesFile>    \n";
		else {
			//here is where we will read in the actual cmd line arguments.

			//grabbing the number of items in the file.
			//cout << "Number of items: " << argv[1] << endl;
			string numberOfItemsInFile = argv[1]; // puts the number of items into a variable

			//grabbing the maximum Weight Of the Knapsack value
			//cout << "Maximum Weight Of The Knapsack: " << argv[2] << endl; //puts the maximumWeightOfKnapsack into a variable
			string maximumWeightOfKnapsack = argv[2];

			//function to read the files and print the answer.
			readFromCmdLineFile(argc, argv, numberOfItemsInFile, maximumWeightOfKnapsack); //the greatest function in this repo


		}
	}
	catch (exception e) {
		cout << "Something very bad happened. I would be more descriptive but you must have messed something up pretty bad. :( \n";  //sad boi hours 
	}
	return 0; //bye bye 
}


/// <summary>
/// This function will do some maths for us and crunch the numbers to tell us what the maximum value that our knapsack can hold. 
/// </summary>
/// <param name="weight"> weight of each of the items</param>
/// <param name="value"> The value of each of the items</param>
/// <param name="maxweight">the maximum weight that our knapsack can hold</param>
/// <param name="index"> were we are in our vectors</param>
/// <returns>returns the max value that our knapsack can hold. </returns>
/// adapted from: https://github.com/kothariji/Dynamic_Programming_Journey/blob/main/DAY-01/0-1%20Knapsack%20Recursion.cpp 
/// Taken with help from Kyle Duncan
int knapsack(vector <int> weight, vector <int> value, int maxweight, int index, int &recursiveTimesCalled, vector<int>& OptimalSolutions )
{
	//recursiveTimesCalled++;

	//base condition
	if ((index == 0) || (maxweight == 0))   //if they are zero, return 0
		return 0;

	if (weight[index-1] > maxweight)
	{
		return knapsack(weight, value, maxweight, index - 1, ++recursiveTimesCalled, OptimalSolutions); // :)   //recursive call with index back one
	}
	else
	{
		int rightSide = OptimalSolutions.size();
		int right = value[index-1] + knapsack(weight, value, maxweight - weight[index-1], index - 1, ++recursiveTimesCalled, OptimalSolutions);  //check the right side with recursion 

		int leftSide = OptimalSolutions.size();
		int left = knapsack(weight, value, maxweight, index - 1, ++recursiveTimesCalled, OptimalSolutions);  //check the left side with recursion

		if (right > left) //compare the two of them
		{
			if (OptimalSolutions.size() > leftSide)
			{
				OptimalSolutions.erase(OptimalSolutions.begin() + leftSide, OptimalSolutions.begin() + OptimalSolutions.size());
  		}
			OptimalSolutions.push_back(index);
			return right;

		}
		else 
		{
			if (leftSide > rightSide) //compare the two vectors 
			{
				OptimalSolutions.erase(OptimalSolutions.begin() + rightSide, OptimalSolutions.begin() + leftSide);
			}
			return left;
		}
	}
}


/// <summary>
/// This function allows us to read from the command line files and put them into vectors. At the end of this function,
/// It will call the knapsack function to complete the program out for us.
/// </summary>
/// <param name="argc"> command line number</param>
/// <param name="argv"> command line value</param>
/// <param name="numberOfItemsInFile">The number of items that are in the files</param>
/// <param name="maximumWeightOfKnapsack">The maximum weight that the knapsack can be</param>
void readFromCmdLineFile(int argc, char* argv[], string numberOfItemsInFile, string maximumWeightOfKnapsack)
{

	//want to use vectors for sake of simplicity of the function we want to use.
	vector <int> weight(stoi(numberOfItemsInFile)), value(stoi(numberOfItemsInFile));
	
	vector <int> optimalSolution();  //used to tell which items are going to be picked up.


	//cout << "Enter weights of each of the items: ";    //print out to user so that they can see the values entered
	bool printed = false;                              // we only want it to print once.... twice is kind of annoying.


	for (int k = 3; k < 5; k++)                        // this is so that it will read through the rest of the cmd arguments so that we can open the file and read
	{
		fstream file(argv[k]); //Argv[3] is the name of the weights File and Argv[4] is the name of the values file.		

		if (file.is_open())  //make sure that the file is open.
		{

			for (int i = 0; i < stoi(numberOfItemsInFile); i++)         //read the file into the correct place here 
			{
				if (argv[k] == argv[3])          //making sure that the argv[3] goes into the correcct weight vector
				{
					file >> weight[i];
					//cout << weight[i] << " ";
				}
				else                            //otherwise it goes into the value vector
				{
					if (!printed)
					{
						//cout << "Enter the value of each of the items: ";            //tells the user what the following numbers mean.
						printed = true;
					}
					file >> value[i];                //put from the file into the vector
					//cout << value[i] << " ";         //print to user
				}

			}
			//cout << endl;

			file.close();                       //being sure to close the file before moving onto the next file.
		}
		else
		{
			cout << "The file \"" << argv[3] << "\" cannot be opened.\n";   //sad day to see this. 
		}

	}

	int recursiveTimesCalled = 0;  
	vector<int> OptimalSolutions;
	int optimalWeight = 0;


	//now we will call the knapsack function so that it can be displayed to the user!
	cout << "The value of the bag is: " << knapsack(weight, value, stoi(maximumWeightOfKnapsack), stoi(numberOfItemsInFile) - 1, ++recursiveTimesCalled, OptimalSolutions);
	cout << endl;


	for (int index : OptimalSolutions)   //makes the output for the optimal solutions.
	{
		optimalWeight += weight[index - 1];
	}

	cout << "The optimal solutions are: ";
	for (int Items : OptimalSolutions)                    //prints out the optimal solutions (which ones we should grab).
		cout << "I" << Items << " ";



	cout << "\nThe Optimal weight is: " <<  optimalWeight;       //prints out the optimal weight here 



	cout << "\nRecurisve times called: " << recursiveTimesCalled << endl;  //prints out the recursive times called 

	cout << endl;

}