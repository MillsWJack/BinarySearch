//Implementation of algorithm Binary Search
//Program searches array of prime numbers for a number

//PSEUDO
/*
	1. min = 0 and max = n-1.
	2. If max < min, 
		1. Target is not present in array.
	3. Compute guess as the average of max and min, rounded down (so that it is an integer).
	4. If array[guess] equals target
		1. Return guess
	5. If the guess was too low,
		1. Min = guess + 1.
	6. Otherwise, the guess was too high. 
		1. Max = guess - 1.
	7. Go back to step 2.
*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int doSearch(vector<int> array, int target);

int guessNum = 0;

int main()
{
	vector<int> values(2097152);
	iota(begin(values), end(values), 0);

	int result = doSearch(values, 15938);
	cout << "Found number at index " << result << endl
		<< "It took " << guessNum << " guesses\n";
	return 0;
}

int doSearch(vector<int> array, int target)
{
	int min = 0;
	int max = array.size() - 1;
	int guess = 0;

	while (array[guess] != target)
	{
		guessNum++;
		guess = floor((min + max) / 2);
		if (max < min)
		{
			return -1;
		}
		if (array[guess] < target)
		{
			min = guess + 1;
		}
		else if(array[guess] > target)
		{
			max = guess - 1;
		}
	}

	return guess;
}