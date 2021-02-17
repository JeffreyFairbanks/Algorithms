#include<iostream>
#include<fstream>
#include<string>

using namespace std;

/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
/*::  Function Prototypes                                     ::*/
/*::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/


int main(int argc, char* argv[])
{
	if (argc < 2) // argc should be 2 for correct execution argv[0] is the executable name, argv[1+] are the  
		// We print argv[0] assuming it is the program name
		cout << "Usage: " << argv[0] << " <RequiredParameter1>\nArguements in angled brackets '<, >' are required, while arguements in square brackets '[, ]' are not.\n";
	else {
		// Do something if the second arguement is stated, like open a file.
		fstream file(argv[1]); //Argv[1] is the name if the file.
		if (file.is_open()) {
			//Process the file here.
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
