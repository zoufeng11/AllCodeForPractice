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
	vector<int> v1 = { 6,-3,-2,7,-15,1,2,2};
	vector<int>result = s1.GetLeastNumbers_Solution(v, 4);
	int result1 = s1.FindGreatestSumOfSubArray(v1);

	Solution Ins;
	vector<int>Insv1 = { 1,3,4,5,7 };
	vector<int>Insv2 = { 1,2,3,4,0 };

	ListNode* resultwq = Ins.insert(Insv1, Insv2, 2);

	Solution listIns;
	ListNode* list = new ListNode(120);
	list->next = new ListNode(360);
	list->next->next = new ListNode(2);
	listIns.listDivide(list, 2);

	struct TreeNode sTreeHead(1);
	sTreeHead.left = new TreeNode(2);
	sTreeHead.right = new TreeNode(3);
	sTreeHead.left->left = new TreeNode(4);
	sTreeHead.left->right = new TreeNode(5);
	sTreeHead.right->left = new TreeNode(6);
	sTreeHead.right->right = new TreeNode(7);

	vector<int> resultPreOrderTree = s1.preorderTree(&sTreeHead);
	vector<int> resultInOrderTree = s1.InorderTree(&sTreeHead);
	vector<int> resultPostOrderTree = s1.postorderTree(&sTreeHead);
	vector<vector<int>>vecRes = s1.printTree(&sTreeHead);
	bool isCheck = s1.check(&sTreeHead);
	SolutionH test;
	//test.testSortString();
	
	//stest.testStringUse();
	//test.Errorlistmain();
	test.compare();


}
