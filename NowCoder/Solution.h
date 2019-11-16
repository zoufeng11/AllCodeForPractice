#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution
{

	//1,2,3,4,5
	//4,5,3,2,1
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV) {
		if (pushV.size() == 0)
			return false;

		int index = 0;  
		stack<int> s;
		//
		for (int i = 0; i < pushV.size(); i++)
		{
			s.push(pushV[i]);


			while (s.empty() == false && s.top() == popV[index] && index < popV.size())
			{
				s.pop();
				index++;
			}

		}
		
		if (s.empty() == true)
			return true;
		else
			return false;
	}
	int jumpFloorII(int number) {
		if (number == 1)
			return 1;
		return 2 * jumpFloorII(number - 1);
	}
	int numberOf1(int n)
	{
		//method 1 , use flag to left move
		int times = 0;
		int flag = 1;
		while (flag != 0)
		{
			if ((n & flag) != 0)
				times++;
			//n = n >> 1;//right move does not match the sinaroy , the num less than zero would not change while right moving.
			flag = flag << 1;
		}
		return times;

		//method 2  , use n&(n-1)
		/*int times = 0;
		while (n != 0)
		{
			n = n & (n - 1);
			times++;
		}
		return times;*/
	}
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		int length = 0;
		ListNode* tempPtr = pListHead;
		ListNode* Ptr = pListHead;
		while (tempPtr != NULL)
		{
			length++;
			tempPtr = tempPtr->next;
		}
		int step = length - k;
		if (step < 0)
			return NULL;
		while (step-- > 0)
		{
			Ptr = Ptr->next;
		}
		return Ptr;
	}
	vector<int> printMatrix(vector<vector<int> > matrix)
	{
		
		int colm = matrix[0].size();
		int row = matrix.size();
		vector<int> vec;
		if (colm == 0 || row == 0)
			return vec;
		int top = 0; int bottom = row -1; int left = 0; int right = colm -1;
		
		while (left <= right && top <= bottom)// why count we use while (left < right)
		{
			for (int i = left; i <= right; i++)
			{
				vec.push_back(matrix[top][i]);
			}
			if (top < bottom)
			{
				for (int i = top + 1; i <= bottom; i++)
				{
					vec.push_back(matrix[i][right]);
				}
			}
			if (left < right && top < bottom)
			{
				for (int i = right - 1; i >= left; i--)
				{
					vec.push_back(matrix[bottom][i]);
				}
			}

			if ( top + 1 < bottom && left < right)
			{
				for (int i = bottom - 1; i >= top +1; i--)
				{
					vec.push_back(matrix[i][left]);
				}
			}
			top++;
			right--;
			left++;
			bottom--;
		}
		return vec;
	}

	vector<int> PrintFromTopToBottom(TreeNode* root)
	{
		vector<int> vec;
		if (root == NULL)
			return vec;
		queue<TreeNode*> que;
		TreeNode* ptr = root;
		que.push(root);
		while (!que.empty())
		{
			ptr = que.front();
			vec.push_back(ptr->val);
			if (ptr->left != NULL)
			{
				que.push(ptr->left);
			}
			if (ptr->right != NULL)
			{
				que.push(ptr->right);
			}
			que.pop();
		}
		return vec;
	}
	vector<vector<int>>FindPath(TreeNode* root, int expectNumber)
	{
		vector<vector<int>> buf;
		if (root == NULL)
			return buf;
		vector<int>vec;
		if (expectNumber == 0 && root->left == NULL && root->right)
		{
			buf.push_back(vec);
		}
		FindPath(root->left, expectNumber - root->val);
		FindPath(root->right, expectNumber - root->val);
	}

	vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
		if (input.empty())
			return input;
		vector<int>vec;
		if (k > input.size())
			return vec;
		for (int i = 0; i < k; i++)
		{
			for (int j = i+1; j < input.size(); j++)
			{
				if (input[i] > input[j])
				{
					int temp = input[j];
					input[j] = input[i];
					input[i] = temp;
				}
			}
			vec.push_back(input[i]);
		}
		return vec;

	}
};

