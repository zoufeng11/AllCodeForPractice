#include "Solution.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	vector<int> vec1 = { 1,2,3,4,5 };
	vector<int> vec2 = { 4,5,3,2,1 };
	Solution s;
	if (s.IsPopOrder(vec1, vec2))
	{
		cout << "vec1 and vec2 could be pushed and popup" << endl;
	}
	else
	{
		cout << "vec1 and vec2 could not be pushed and popup" << endl;
	}

	Solution jump;
	int temp = jump.jumpFloorII(3);

	Solution number;
	int times = number.numberOf1(-1);

	cout << "times is equal to " + times << endl;

	Solution vec;
	vector<vector<int>> matrix = { {1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16} };
	vector<int> vecResult = vec.printMatrix(matrix);

	Solution s1;

	vector<int> v = { 1,4,6,8,5,3,2,9,7,34,23,5 };
	vector<int>result = s1.GetLeastNumbers_Solution(v, 4);




}
