// JEFFREY FAIRBANKS

#include<iostream>
#include<vector>
#include<string>

using namespace std;

///////////////////////
//    PROTOTYPES     //
///////////////////////
int knapsack(vector <int> weight, vector <int> value, int maxweight, int index);


int main()
{
	int n;
	cout << "Enter the number of items: ";
	cin >> n;
	vector <int> weight(n), value(n);

	cout << "enter weights: " << endl;
	for (int i = 0; i < n; i++)
		cin >> weight[i];
	cout << "enter values: " << endl;
	for (int i = 0; i < n; i++)
		cin >> value[i];

	int maxweight(0);

	cout << "Enter maximum capacity of knapsack: ";
	cin >> maxweight;

	cout << "Maximum value of bag is: " << knapsack(weight, value, maxweight, n - 1);

	cin.get();
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