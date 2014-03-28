

template<typename T>
int partition(vector<T>& a,int left,int right)
{
	T pivot = a[right];
	int index = left;

	for(int i= left;i < right;i++){
		if(a[i] <= pivot)
		{
			if(i != index)
				swap(a[index], a[i]);
			index++;
		}
	}
	swap(a[right], a[index]);
	return index;
} 

template<typename T>
void QuickSortImpl(vector<T>& v, int left, int right)
{
	if(left >= right) return;

	int q= partition(v, left, right);
	QuickSortImpl(v, left, q-1);
	QuickSortImpl(v, q+1, right);
}


template<typename T>
void QuickSort(vector<T>& v)
{
	QuickSortImpl(v, 0, v.size()-1);
}

// O(N) topK
template<typename T>
vector<int> topK(vector<T>& v, int K)
{
    if(v.size() <= K) return v;
    vector<int> result(K);
    int result_index = 0;

    int left = 0;
    int right = v.size()-1;
    int num_to_be_copied = K;
    while(num_to_be_copied > 0 && left <= right)
    {
        int q = partition(v, left, right);
        int larger_num = right - q + 1;
        if(larger_num <= num_to_be_copied)
        {
            copy(v.begin() + q, v.begin() + right + 1, result.begin() + result_index); // q to right
            result_index += larger_num;
            num_to_be_copied -= larger_num;
            right = q-1;
        }
        else
        {
            left = q+1;
        }
    }
    return result;
}



#define N 40
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> v(N,0);
	for(int i = 0; i < N; ++i) v[i] = i;
	
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " ")); cout<<endl;
	random_shuffle(v.begin(), v.end());
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " ")); cout<<endl;
	
	vector<int> vtop = topK(v,10);
	copy(vtop.begin(), vtop.end(), ostream_iterator<int>(cout, " ")); cout<<endl;
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " ")); cout<<endl;

	QuickSort(v);
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " ")); cout<<endl;

	return 0;
}

