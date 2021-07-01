#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <stdlib.h>
#include <sstream>
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
public:
	vector<string> permutation;
	set<string> permutationSet;
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

	vector<vector<int>> buf;
	vector<int>vecPath;
	vector<vector<int>>FindPath(TreeNode* root, int expectNumber)
	{
		
		if (root == NULL)
			return buf;
		
		vecPath.push_back(root->val);
		if (expectNumber-root->val == 0 && root->left == NULL && root->right == NULL)
		{
			buf.push_back(vecPath);
		}
		FindPath(root->left, expectNumber - root->val);
		FindPath(root->right, expectNumber - root->val);

		if (vecPath.size() != 0)
		{
			vecPath.pop_back();
		}
		return buf;
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

	int FindGreatestSumOfSubArray(vector<int> array) {
		if (array.size() == 0)
			return 0;
		int sum = 0;
		int result = array[0];
		for (int i = 0; i < array.size(); i++)
		{
			if (sum < 0)
			{
				sum = array[i];
			}
			else
			{
				sum = sum + array[i];
			}

			if (sum > result)
			{
				result = sum;
			}
		}
		return result;
	}

	vector<string> Permutation(string str) {
		if (str.size() != 0)
		{
			int nSize = str.size();
			Permutation(str, nSize, 0);
		}
		for (set<string>::iterator iter = permutationSet.begin(); iter != permutationSet.end(); ++iter)
		{
			permutation.push_back(*iter);
		}
		return permutation;
	}

	void Permutation(string str, int nSize, int n)
	{
		if (n == str.size())
		{
			permutationSet.insert(str);
		}

		else
		{
			Permutation(str, nSize, n + 1);
			for (int i = n + 1; i < str.size(); ++i)
			{
				if (str[n] != str[i])
				{
					char tmp = str[n];
					str[n] = str[i];
					str[i] = tmp;

					Permutation(str, nSize, n + 1);

					tmp = str[n];
					str[n] = str[i];
					str[i] = tmp;
				}
			}
		}
	}

	int NumberOf1Between1AndN_Solution(int n)
	{
		int temp = 0;
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			temp = i;
			while (temp)
			{
				if (temp % 10 == 1)
					count++;
				temp = temp / 10;
			}
		}
		return count;
	}

	ListNode* insert(vector<int> A, vector<int> nxt, int val) {
			// write code here
		ListNode* node = new ListNode(val);
		if (A.empty())
		{
			node->next = node;
			return node;
		}
		else
		{
			ListNode* head = new ListNode(A[0]);
			ListNode* tmp = head;
			for (int i = 0; i < A.size(); i++)
			{
				tmp->next = new ListNode(A[nxt[i]]);
				tmp = tmp->next;
			}

			if (val < head->val)
			{
				tmp->next = node;
				node->next = head;
				return node;
			}
			if (val > tmp->val)
			{
				tmp->next = node;
				node->next = head;
				return head;
			}
			ListNode* p = head;
			ListNode* cur = head->next;
			while (cur != NULL)
			{
				if (val <= cur->val && val > p->val)
				{
					p->next = node;
					node->next = cur;
					return head;
				}
				p = cur;
				cur = cur->next;

			}
			return head;
		}
	}
	ListNode* removeNode(ListNode* pHead, int delVal)
	{
		if (pHead == NULL)
			return NULL;
		ListNode* Pre = pHead;
		ListNode* Cur = pHead->next;
		//The first sinario was delete the head of value;
		if (delVal == pHead->val)
		{
			pHead = pHead->next;
			delete Pre;
			return pHead;
		}
		//senario 2 :delete the following correct value;
		while (Cur != NULL)
		{
			if (Cur->val == delVal)
			{
				Pre->next = Cur->next;
				delete Cur;
				return pHead;
			}
			Pre = Pre->next;
			Cur = Cur->next;
		}
		return pHead;

	}
	ListNode* listDivide(ListNode* head, int val)
	{
		if (head == NULL)
			return NULL;
		ListNode* Ptr = head;

		ListNode* LessNode = NULL;
		ListNode* LargeNode = NULL;
		ListNode* LessHead = LessNode;
		ListNode* LargeHead = LargeNode;
		while (Ptr!= NULL)
		{
			ListNode* pNext = Ptr->next;
			if (Ptr->val <= val)
			{
				if (LessNode == NULL)
				{
					LessHead = Ptr;
					LessNode = Ptr;
				}
				else
				{
					LessNode->next = Ptr;
					LessNode = LessNode->next;
				}
				
			}
			else
			{
				if (LargeNode == NULL)
				{
					LargeHead = Ptr;
					LargeNode = Ptr;
				}
				else
				{
					LargeNode->next = Ptr;
					LargeNode = LargeNode->next;
				}
				
			}
			Ptr->next = NULL;
			Ptr = pNext;
		}
		if (LessHead == NULL)
		{
			return LargeHead;
		}
		if (LargeHead == NULL)
		{
			return LessHead;
		}
		if (LessHead && LargeHead)
		{
			LessNode->next = LargeHead;
		}
		
		return LessHead;
	}

	vector<int> preorderTree(TreeNode* head)
	{
		stack<TreeNode*> stk;
		vector<int>temp;
		if (head != NULL)
		{
			stk.push(head);
		}
		while (!stk.empty())
		{
			TreeNode*tempTree = stk.top();
			temp.push_back(tempTree->val);
			stk.pop();
			if(tempTree->right)
				stk.push(tempTree->right);
			if(tempTree->left)
				stk.push(tempTree->left);
		}
		return temp;
	}
	vector<int> InorderTree(TreeNode* head)
	{
		stack<TreeNode*> stk;
		TreeNode* Cur = head;
		vector<int>temp;
		while (!stk.empty() || Cur !=NULL)
		{			
			while (Cur!=NULL)
			{
				stk.push(Cur);
				Cur = Cur->left;
			}
			if (!stk.empty())
			{
				Cur = stk.top();
				temp.push_back(Cur->val);
				stk.pop();
				Cur = Cur->right;
			}
			
		}
		return temp;

	}
	vector<int> postorderTree(TreeNode* head)
	{
		stack<TreeNode*>s1;
		stack<TreeNode*>s2;
		vector<int>vtemp;
		if (head != NULL)
			s1.push(head);
		TreeNode* tempTree = head;
		while (!s1.empty())
		{
			tempTree = s1.top();
			s2.push(tempTree);
			s1.pop();
			if (tempTree->left)
				s1.push(tempTree->left);
			if (tempTree->right)
				s1.push(tempTree->right);
		}
		while (!s2.empty())
		{
			vtemp.push_back(s2.top()->val);
			s2.pop();
		}
		return vtemp;
	}

	vector<vector<int> > printTree(TreeNode* root)
	{
		//print the tree with each Row
		queue<TreeNode*>q1;
		TreeNode* last = NULL;
		TreeNode* nlast = NULL;
		vector<int> vecLine;
		vector<vector<int>>vecRes;
		if (root)
		{
			q1.push(root);
			last = root;
		}
		while (!q1.empty())
		{
			TreeNode* tempTree = q1.front();
			vecLine.push_back(tempTree->val);
			q1.pop();
			if (tempTree->left != NULL)
			{
				q1.push(tempTree->left);
				nlast = tempTree->left;
			}
			if (tempTree->right != NULL)
			{
				q1.push(tempTree->right);
				nlast = tempTree->right;
			}
			if (tempTree == last)
			{
				last = nlast;
				vecRes.push_back(vecLine);
				vecLine.clear();
			}
		}
		return vecRes;
	}

public:
	bool check(TreeNode* root) {
		// write code here
		int res = getDepth(root);
		if (res == -1)
			return false;
		return true;
	}
	int getDepth(TreeNode* node)
	{
		if (node == NULL)
			return 0;
		int L = 1 + getDepth(node->left);
		int R = 1 + getDepth(node->right);
		if (abs(L - R) > 1)
			return -1;
		return L > R ? L : R;
	}
	bool checkComplete(TreeNode* head)
	{
		queue<TreeNode*>q1;
		if (head == NULL)
			return false;
		q1.push(head);
		while (!q1.empty())
		{
			TreeNode* CurTree = q1.front();
			if (CurTree->left != NULL && CurTree->right != NULL)
			{
				q1.pop();
				q1.push(CurTree->left);
				q1.push(CurTree->right);
			}
			if (CurTree->left == NULL && CurTree->right != NULL)
				return false;
			if (CurTree->left && CurTree->right == NULL || CurTree->left == NULL && CurTree->right == NULL)
			{
				q1.pop();
				while (!q1.empty())
				{
					CurTree = q1.front();
					if (CurTree->left == NULL && CurTree->right == NULL)
						q1.pop();
					else
						return false;
				}
				return true;
			}
		}
	}
	/*****从二叉树的节点A出发，可以向上或者向下走，
	但沿途的节点只能经过一次，当到达节点B时，
	路径上的节点数叫作A到B的距离。对于给定的一棵二叉树，求整棵树上节点间的最大距离。
	给定一个二叉树的头结点root，请返回最大距离****/
	public:
		int depth(TreeNode *node, int &res)
		{
			if (node == nullptr) return 0;
			int t1 = depth(node->left, res);
			int t2 = depth(node->right, res);
			res = max(res, t1 + t2 + 1);
			return max(t1, t2) + 1;
		}
		int findLongest(TreeNode* root) {
			// write code here
			int res = 0;
			depth(root, res);
			return res;
		}
		/**一棵二叉树原本是搜索二叉树，但是其中有两个节点调换了位置，
		使得这棵二叉树不再是搜索二叉树，请找到这两个错误节点并返回他们的值。
		保证二叉树中结点的值各不相同。***/
		vector<int> findError(TreeNode* root) {
			// write code here
			stack<TreeNode *> ss;
			TreeNode *cur = root;
			vector<int> ret(2);
			ret[0] = INT_MAX;
			ret[1] = INT_MIN;
			TreeNode *last = nullptr;
			while (!ss.empty() || cur)
			{
				if (cur)
				{
					ss.push(cur);
					cur = cur->left;
				}
				else
				{
					cur = ss.top();
					ss.pop();
					if (last && last->val > cur->val)
					{
						ret[1] = max(ret[1], last->val);
						ret[0] = min(ret[0], cur->val);
					}
					last = cur;
					cur = cur->right;
				}
			}
			return ret;
		}

};

class Sort {

	class BubbleSort {
	public:
		int* bubbleSort(int* A, int n) {
			//[1,2,3,5,2,3]
			for (int i = n-1; i >0; i--)
			{
				for (int j = 0; j < i; j++)
				{
					if (A[j] > A[j+1])
					{
						int temp = A[j+1];
						A[j+1] = A[j];
						A[j] = temp;
					}
				}
			}
			return A;
		}
	};
	class SelectSort {
		int* selectSort(int* A, int n)
		{
			int k = 0;
			
			for (int i = 0; i < n; i++)
			{
				k = i;
				for (int j = i + 1; j < n; j++)
				{
					if (A[k] < A[j])
					{
						k = j;
					}
				}
				int temp = A[i];
				A[i] = A[k];
				A[k] = temp;
			}
			return A;
		}
		
	};
	class InsertionSort {
	public:
		int* insertionSort(int* A, int n) {
			for (int i = 1; i < n; i++)
			{
				int index = i;
				while (index > 0)
				{
					if (A[index] < A[index - 1])
					{
						int temp = A[index];
						A[index] = A[index - 1];
						A[index - 1] = temp;
						index--;
					}
					else
						break;
				}
				
			}
			return A;
		}
	};

	/*quick sort
	* n(Nlogn)  NOT stable
	*/
	void swap(int* p1, int* p2)
	{
		int temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
	bool quickSort(int* p, int length)
	{
		if (p == NULL)
			return false;
		if (length == 0)
			return false;
		int selectNum = p[length - 1];
		int right = length - 1;
		int i = 0;
		int j = i - 1;
		for (int i = 0; i < length; i++)
		{

			if (p[i] < selectNum)
			{
				swap(&p[i], &p[++j]);
			}
		}
		swap(&p[++j], &p[right]);

		quickSort(p, j);
		quickSort(p + j + 1, length - j - 1);
		return true;
	}


	/*Shell sort
	*o(N1.5)
	*/
	void shellSort(vector<int>& arr, int bgn, int end)
	{
		for (int step = (end - bgn) / 2; step > 0; step /= 2)
		{
			for (int i = bgn; i < bgn + step; ++i)
			{
				/*
				* below is another type of insert
				*/
				for (int j = i + step; j < end; j += step)
				{
					int k = j - step;
					for (; k >= i; k -= step)
						if (arr[k] <= arr[j])
							break;
					if (k != j - step)
					{
						int tmp = arr[j];
						for (int m = j; m > k + step; m -= step)
							arr[m] = arr[m - step];
						arr[k + step] = tmp;
					}
				}
			}
		}
	}

	/*mergeSortInOrder*/
	void mergeSortInOrder(vector<int>& arr, int bgn, int mid, int end)
	{
		int* pBuf = new int[end - bgn];
		int* pTemp = pBuf;
		int lindex = bgn;
		int rindex = mid;

		while ((lindex < mid) && (rindex < end))
			* (pTemp++) = (arr[lindex] < arr[rindex]) ? arr[lindex++] : arr[rindex++];

		while (lindex < mid)
			* pTemp++ = arr[lindex++];
		while (rindex < end)
			* pTemp++ = arr[rindex++];

		//pTemp -> arr
		pTemp = pBuf;
		for (int i = bgn; i < end; i++)
			arr[i] = *pTemp++;

		delete[]pBuf;
	}
	//UpToDown To DownToUp
	void mergeSort(vector<int>& arr, int bgn, int end)
	{
		if (bgn >= end - 1)
			return;

		int mid = (bgn + end) / 2;
		mergeSort(arr, bgn, mid);
		mergeSort(arr, mid, end);
		mergeSortInOrder(arr, bgn, mid, end);
	}

	class stackSolution
	{
	public:
		stack<int> stackData;
		stack<int> stackMin;
		void push(int value)
		{
			stackData.push(value);
			if (stackMin.empty() ||value < stackMin.top())
			{
				stackMin.push(value);
			}
		}
		void pop()
		{
			if (!stackData.empty())
			{
				if (stackData.top() == stackMin.top())
				{
					stackMin.pop();
				}
				stackData.pop();
			}
		}
		int top()
		{
			return stackData.top();
		}
		int min()
		{
			return stackMin.top();
		}
	};


};

class SolutionH
{

public:
	void testSortString()
	{
		int num;
		string comingstring;
		cin >> num;
		set<string> setString;
		while (num > 0)
		{
			cout << "the num is " << num << endl;
			num--;
			cin >> comingstring;
			setString.insert(comingstring);
		}
		for (auto i : setString)
			cout << i.c_str()<<endl;
	}

	void testStringUse()
	{
		string t1 = "I |am |good |student";
		size_t s1;
		string t2;

		t2 = t1.substr(0,5);
		s1 = t1.find_first_of("|");
		while (s1 != string::npos)
		{
			s1 = t1.find_first_of("|",s1+1);
		}
		t2.insert(t2.size()," good man");


	}




	void test_MoveCurser()
	{
		string str;
		while (cin >> str) {
			pair<int, int> point(0, 0);              
			size_t found = str.find_first_of(';');  
			int start = 0;

			while (found != string::npos) {
				string s1 = str.substr(start, found - start);
				//cout << s1 << endl;
				start = found + 1;
				found = str.find_first_of(';', found + 1);

				if (s1.size() > 1 && s1.size() <= 3) {    
					char c = s1[0];
					int n = 0;
					int invalid = 0;   
					for (int i = 1; i < s1.size(); ++i) { 
						if (s1[i] >= '0' && s1[i] <= '9')
							n = n * 10 + (s1[i] - '0');
						else {
							invalid = 1;
							break;
						}
					}
					if (invalid == 0) {
						switch (c)
						{
						case 'A': {point.first -= n; break; }
						case 'D': {point.first += n; break; }
						case 'W': {point.second += n; break; }
						case 'S': {point.second -= n; break; }
						}
					}

				}
			}
			cout << point.first << ',' << point.second << endl;
		}
	}

/***********************************************************************/

	vector<string> split(string str, char del) {
		stringstream ss(str);
		string tok;
		vector<string> ret;
		while (getline(ss, tok, del)) {
			ret.push_back(tok);
		}
		return ret;
	}
	bool IPisvalid(vector<string> svec) {
		if (svec.size() != 4) {
			return false;
		}
		return true;
	}
	bool Maskisvalid(vector<string> svec) {
		bool zero = false;
		if (svec.size() != 4) {
			return false;
		}
		for (int i = 0; i < 4; i++) {
			if (zero == false) {
				if (atoi(svec[i].c_str()) != 255) {
					if (atoi(svec[i].c_str()) != 0 &&
						atoi(svec[i].c_str()) != 128 &&
						atoi(svec[i].c_str()) != 192 &&
						atoi(svec[i].c_str()) != 224 &&
						atoi(svec[i].c_str()) != 240 &&
						atoi(svec[i].c_str()) != 248 &&
						atoi(svec[i].c_str()) != 252 &&
						atoi(svec[i].c_str()) != 254) {
						return false;
					}
					else {
						zero = true;
					}
				}
			}
			else {
				if (atoi(svec[i].c_str()) != 0) {
					return false;
				}
			}
		}
		if (atoi(svec[3].c_str()) == 255) {
			return false;
		}
		return true;
	}

	int IPmain() {
		vector<int> ret(7, 0);
		string str;
		vector<string> svec;
		vector<string> ip;
		vector<string> mask;
		while (getline(cin, str)) {
			svec = split(str, '~');
			ip = split(svec[0], '.');
			mask = split(svec[1], '.');
			if (Maskisvalid(mask) && IPisvalid(ip)) {
				if (atoi(ip[0].c_str()) >= 1 && atoi(ip[0].c_str()) <= 126) {
					++ret[0];
					if (atoi(ip[0].c_str()) == 10)
						++ret[6];
				}
				else if (atoi(ip[0].c_str()) >= 128 && atoi(ip[0].c_str()) <= 191) {
					++ret[1];
					if (atoi(ip[0].c_str()) == 172) {
						if (atoi(ip[1].c_str()) >= 16 && atoi(ip[1].c_str()) <= 31)
							++ret[6];
					}
				}
				else if (atoi(ip[0].c_str()) >= 192 && atoi(ip[0].c_str()) <= 223) {
					++ret[2];
					if (atoi(ip[0].c_str()) == 168)
						++ret[6];
				}
				else if (atoi(ip[0].c_str()) >= 224 && atoi(ip[0].c_str()) <= 239) {
					++ret[3];
				}
				else if (atoi(ip[0].c_str()) >= 240 && atoi(ip[0].c_str()) <= 255) {
					++ret[4];
				}
			}
			else {
				ret[5]++;
			}
		}
		cout << ret[0] << " " << ret[1] << " " << ret[2] << " " << ret[3] << " " << ret[4] << " " << ret[5] << " " << ret[6] << endl;
		return 0;
	}


	struct erroNote
	{
		string filename;
		string codeline;
		int count = 1;
		bool operator==(const erroNote& a)
		{
			if (a.filename == filename && a.codeline == codeline)
				return true;
			else return false;
		}
	};
/************************************************************************/
	int Errorlistmain()
	{
		string str;
		vector<erroNote> ans;
		vector<erroNote>::iterator res;
		while (getline(cin, str))
			//for(int i=0; i<2; i++)
		{
			//getline(cin, str);
			size_t found1 = str.find_last_of('\\');
			size_t found2 = str.find_first_of(' ');
			string s1 = str.substr(found1 + 1, found2 - found1 - 1);
			erroNote temp;
			if (s1.size() > 16)
			{
				s1 = s1.substr(s1.size() - 16, 16);
			}
			string s2 = str.substr(found2 + 1, str.size() - found2);
			temp.filename = s1;
			temp.codeline = s2;
			res = find(ans.begin(), ans.end(), temp);
			if (res == ans.end())
			{
				ans.push_back(temp);
			}
			else
			{
				res->count++;
			}

		}
		if (ans.size() >= 8)
		{
			for (int i = ans.size() - 8; i < ans.size(); i++)
			{
				cout << ans[i].filename << " " << ans[i].codeline << " " << ans[i].count << endl;
			}
		}
		else
		{
			for (int i = 0; i < ans.size(); i++)
			{
				cout << ans[i].filename << " " << ans[i].codeline << " " << ans[i].count << endl;
			}
		}

		return 0;


	}

	int compare()
	{
		string t1;
		string t2;
		while (cin >> t1)
		{
			cin >> t2;
			int numt1 = atoi(t1.c_str());
			int numt2 = atoi(t2.c_str());
			
			if (t1 > t2)
			{
				cout << "t1" << t1 << ">" << "t2" <<t2 << endl;
			}
			else
			{
				cout << "t1" << t1 << "<" << "t2" << t2 << endl;
			}
		}
		return 0;
	}
	

};
