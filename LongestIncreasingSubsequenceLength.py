Given an unsorted array of integers, find the length of longest increasing subsequence.

# For example,
# Given [10, 9, 2, 5, 3, 7, 101, 18],
# The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

# Your algorithm should run in O(n2) complexity.

# Follow up: Could you improve it to O(n log n) time complexity?

def CeilIndex(v, l, r, key):
    while(r-l > 1):
        m = l + (r-l)/2
        if(v[m] >= key):
            r = m
        else:
            l = m
    return r


def LongestIncreasingSubsequenceLength(v):
    vlen = len(v)
    if(vlen==0):
        return 0
    tail = [0]*vlen
    length = 1
    tail[0] = v[0]
    for i in range(1, vlen):
        if(v[i] < tail[0]):
            tail[0] = v[i]
        elif (v[i] > tail[length-1]):
            tail[length] = v[i]
            length += 1
        else:
            tail[CeilIndex(tail, -1, length-1, v[i])] = v[i]
        print tail
    return length

#input = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15] 
input = [10, 1000, 2,3,4,5,6,7,8] 
print LongestIncreasingSubsequenceLength(input)
