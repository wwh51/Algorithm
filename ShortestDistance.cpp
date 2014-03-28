/*
  You have a large text file containing words. Given any two words, find the shortest distance 
  (in terms of number of words) between them in the file. Can you make the searching operation in O(1) 
  time? What about the space complexity for your solution?
*/
int ShortestDistance(string text[], int n, string word1, string word2){
    if(word1 == word2) return 0;
    int pos_last_word1 = -1, pos_last_word2 = -1, min_dist = INT_MAX;
    for(int i = 0; i < n; ++i)
    {
        if(text[i] == word1)
        {
            pos_last_word1 = i;
            if(pos_last_word2 >= 0)
                min_dist = min(min_dist, pos_last_word1 - pos_last_word2);
        }
        else if(text[i] == word2)
        {
            pos_last_word2 = i;
            if(pos_last_word1 >= 0)
                min_dist = min(min_dist, pos_last_word2 - pos_last_word1);
        }
    }
    return min_dist;
}
