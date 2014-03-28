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

// a better way
int ShortestDist(string text[], int n, string word1, string word2)
{

    unordered_map<string, vector<int> > map_word_indexs;

    InitMap(text, n, map_word_indexs);

    if( map_word_indexs.find(word1) == map_word_indexs.end()

        || map_word_indexs.find(word2) == map_word_indexs.end())

    return INT_MAX;

    

    vector<int>& v1 = map_word_indexs[word1];

    vector<int>& v2 = map_word_indexs[word2];

    vector< pair<int, int> > vsorted;

    for(int i = 0; i < v1.size(); ++i)

        vsorted.push( make_pair(v1[i], 0) );

    for(int i = 0; i < v2.size(); ++i)

        vsorted.push( make_pair(v2[i], 1) );

    sort(vsorted.begin(), vsorted.end());

    

    int min_dist = INT_MAX;

    for(int i = 1; i < vsorted.size(); ++i)

    {

        if(vsorted[i-1].second != vsorted[i].second)

            min_dist  = min(min_dist, vsorted[i].first - vsorted[i-1].first);

    }

    return min_dist;

}
