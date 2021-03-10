# Algorithms
HW from the NNU Algorithms class 


# 0 -1 Knapsack Dynamic Programming: README
This program will complete the 0-1 Knapsack problem
using Dynamic Programming to solve for:
Optimal Solution: {values}
Optimal Solution's Weight: {value}
Optimal Solution's Value: {value}
Number of Table References: {value}
Dynamic Programming Table:  {values}

For this project there are a few things to note.
In order to run the program correctly, there are a few
command line parameters that must be passed in.
There are 4 arguments. The arguments follow this layout:
numberOfItemsInFiles=5, maximumWeightOfKnapsack=5, weightsFile=weights1.txt, valuesFile=values1.txt
EXAMPLE OF WHAT WOULD BE PASSED IN:
"5" "5" ".../weights.txt" ".../values.txt"

Example solution: 
arguments passed in:
"5" "5" ".../weights.txt" ".../values.txt"
where weights are:  3  4 2 3 1
where values are:   7 10 5 9 3
SOLUTION:
The optimal Solution is: I3 I4
Optimal Solution's Weight:  5
Optimal Solution's Value: 14
Number of Table References: 80
0 0 0 0 0 0
0 0 0 7 7 7
0 0 0 7 10 10
0 0 5 7 10 12
0 0 5 9 10 14
0 3 5 9 12 14


# 0 -1 Knapsack Recursive Solution: README
This program will complete the 0-1 Knapsack problem
using recursion to solve for:
Optimal Solution: {values}
Optimal Solution's Weight: {value}
Optimal Solution's Value: {value}
Number of Recursive Calls: {value}

As seen before, there are a few things to note
about this project. The command lines follow those seen above.
The arguments follow this layout:
numberOfItemsInFiles=5, maximumWeightOfKnapsack=5, weightsFile=weights1.txt, valuesFile=values1.txt
EXAMPLE OF WHAT WOULD BE PASSED IN:
"5" "5" ".../weights.txt" ".../values.txt"


