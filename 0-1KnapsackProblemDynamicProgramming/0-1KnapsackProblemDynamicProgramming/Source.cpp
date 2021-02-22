// JEFFREY FAIRBANKS

#include<iostream>
#include<vector>
#include<string>
#include<fstream>

using namespace std;

///////////////////////
//    PROTOTYPES     //
///////////////////////
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
			cout << "Number of items: " << argv[1] << endl;
			string numberOfItemsInFile = argv[1]; // puts the number of items into a variable

			//grabbing the maximum Weight Of the Knapsack value
			cout << "Maximum Weight Of The Knapsack: " << argv[2] << endl; //puts the maximumWeightOfKnapsack into a variable
			string maximumWeightOfKnapsack = argv[2];

			//function to read the files and print the answer.
			readFromCmdLineFile(argc, argv, numberOfItemsInFile, maximumWeightOfKnapsack); //the greatest function in this repo


		}
	}
	catch (exception e) {
		cout << "Something very bad happened. I would be more descriptive but you must have messed something up pretty bad. :( \n";  //sad boi hours 
	}

	cout << "\nPress Enter to end the program. \n";   //thank you for coming!
	cin.get(); //wait for the user to press enter to end the program.
	return 0; //bye bye 
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


	cout << "Enter weights of each of the items: ";    //print out to user so that they can see the values entered
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
					cout << weight[i] << " ";
				}
				else                            //otherwise it goes into the value vector
				{
					if (!printed)
					{
						cout << "Enter the value of each of the items: ";            //tells the user what the following numbers mean.
						printed = true;
					}
					file >> value[i];                //put from the file into the vector
					cout << value[i] << " ";         //print to user
				}

			}
			cout << endl;

			file.close();                       //being sure to close the file before moving onto the next file.
		}
		else
		{
			cout << "The file \"" << argv[3] << "\" cannot be opened.\n";   //sad day to see this. 
		}

	}


	//  cout << knapSack(stoi(maximumWeightOfKnapsack), weight, value, stoi(numberOfItemsInFile));

}




