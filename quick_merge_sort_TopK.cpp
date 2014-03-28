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




void  merge (int list1[ ] , int size1 , int list2[ ] , int size2 , int list3[ ])
{
    int i1, i2, i3;    
    i1 = 0; i2 = 0; i3 = 0;
    /* while both lists are non-empty */
    while (i1 < size1 && i2 < size2) {
        if (list1[i1] < list2[i2]) {
            list3[i3++] = list1[i1++];
        } 
        else {
            list3[i3++] = list2[i2++];
        }
    }
    while (i1 < size1) {   
        /* copy remainder of list1 */
        list3[i3++] = list1[i1++];
    }
    while (i2 < size2) { 
        /* copy remainder of list2 */
        list3[i3++] = list2[i2++];
    }
}

  void merge_sort (int array[], int len)
{
    if (len< 2) {
        return;
    }

    vector<int> temp(len);
    int mid, i;    
    mid = len/ 2;
    merge_sort(array, mid);
    merge_sort(array + mid, len - mid);
    merge (array, mid, array + mid, len- mid, temp);
    for (i = 0; i < len; i++) {
        array[i] = temp[i];
      }
}


// 数组中有多少个前后颠倒的对，例如 1 3 4 2 有2个
// merge sort, count it in merge

void  merge (int list1[ ] , int size1 , int list2[ ] , int size2 , int list3[ ], int& disorder_count)
{
    int i1, i2, i3;    
    i1 = 0; i2 = 0; i3 = 0;
    /* while both lists are non-empty */
    while (i1 < size1 && i2 < size2) {
        if (list1[i1] < list2[i2]) {
            list3[i3++] = list1[i1++];
            disorder_count += i2;
        } 
        else {
            list3[i3++] = list2[i2++];
        }
    }
    while (i1 < size1) {   
        /* copy remainder of list1 */
        list3[i3++] = list1[i1++];
        disorder_count += i2;
    }
    while (i2 < size2) { 
        /* copy remainder of list2 */
        list3[i3++] = list2[i2++];
    }
}

  void merge_sort (int array[], int len, int& disorder_count)
{
    if (len< 2) {
        return;
    }

    vector<int> temp(len);
    int mid, i;    
    mid = len/ 2;
    merge_sort(array, mid, disorder_count);
    merge_sort(array + mid, len - mid, disorder_count);
    merge (array, mid, array + mid, len- mid, temp, disorder_count);
    for (i = 0; i < len; i++) {
        array[i] = temp[i];
      }
}

int get_disorder_num(int array[], int len)
{
  int disorder_count = 0;
  merge_sort(aray, len, disorder_count);
  return disorder_count;
}

