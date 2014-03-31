ListNode *swapPairs(ListNode *head) {
	if(!head || !head->next)
		return head;

	ListNode dummy(-1);
	dummy.next = head;
	ListNode *prev = &dummy, *curr=head, *next = head->next;
	while(curr)
	{
		prev->next = next;
		curr->next = next->next;
		next->next = curr;

		prev = curr;
		curr = curr->next;
		next = curr ? curr->next : NULL;
	}
	return dummy.next;
}

#define NO_OF_CHARS 256
// return -1 if no unique char
int FindFirstUniqueChar(string s)
{
	vector< pair<int, int> > arr_count_index(NO_OF_CHARS, make_pair(0,-1));
	for(int i = 0; i < s.size(); ++i)
	{
		int c = (unsigned char)(s[i]);
		if(arr_count_index[c].first == 0)
		{
			arr_count_index[c].second = i;
		}
		arr_count_index[c].first++;
	}

	int nFirst = INT_MAX;
	for(int i = 0; i < NO_OF_CHARS; ++i)
	{
		if(arr_count_index[i].first == 1)
			nFirst = min(nFirst, arr_count_index[i].second);
	}

	return nFirst == INT_MAX ? -1 : nFirst;
}


// return empty vector if no path found
vector<int> pathsum(TreeNode *root, int sum)
{
	vector<int> result;
	if(!root)
		return result;
	if(!pathsum(root, sum, result,sum))
		result.clear();
	return result;
}

bool pathSum(TreeNode *root, vector<int> &result, int target) 
{	
	result.push_back(root->val);
	if(result->left == NULL && result->right == NULL)
		return gap == root->val;

	if(result->left && pathSum(result->left, result, target - root->val))
		return true;
	if(result->right && pathSum(result->right, result, target - root->val))
		return true;

	result.pop_back();
	return false;
}

bool  IsConstructed(string str1, string str2)
{
	if(str1.size() > str2.size())
		return false;
	vector<int> count(NO_OF_CHARS, 0);
	for(int i = 0; i < str2.size(); ++i)
	{
		int c = (unsigned char)(str2[i]);
		++count[c];
	}
	for(int i = 0; i < str1.size(); ++i)
	{
		int c = (unsigned char)(str1[i]);
		--count[c];
		if(count[c] < 0)
			return false;
	}
	return true;
}

//regex e("^\s*[+-]?(\d+|\d*\.\d+|\d+\.\d*)([eE][+-]?\d+)?\s*$");
