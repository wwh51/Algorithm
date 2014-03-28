/*

Question: Find the missing number in an array of consecutive integers.
Example:
input:2,3,4,5,6,7,8,9,10,11,12,13,14,15 output: null
input:2,3,5,6,7,8,9,10,11,12,13,14,15 output: 4
input:2,3,4,5,6,7,8,9,10,11,12,14,15 output: 13

*/
int missingNumber(vector<int> v)
{
    int len = v.size();
    if(len < 2) return -1;
    int high = len - 1;
    int low = 0;
    while(low < high)
    {
        int mid = low + (high-low)/2;
        if(mid - low == v[mid] - v[low]) // in mid to high
        {
            if(mid + 1 < v.size() && v[mid]+1 != v[mid+1])
                return v[mid]+1;
            else
                low = mid + 1;
        }
        else
        {
            if(mid - 1 >= 0 && v[mid] - 1 != v[mid-1])
                return v[mid] - 1;
            else
                high = mid - 1;
        }
    }

    return -1;
}
