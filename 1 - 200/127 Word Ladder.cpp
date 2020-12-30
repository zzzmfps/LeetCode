// 27ms, 99.46%
static int x = []() {
    ios_base::sync_with_stdio(false); // toggles off the synchronization
    cin.tie(nullptr);                 // ties cin with nullptr, not cout
    return 0;
}();

class Solution
{
  public:
    int ladderLength(const string &beginWord, const string &endWord,
                     const vector<string> &wordDict)
    {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        if (wordSet.find(endWord) == wordSet.end())
            return 0;
        unordered_set<string> head, tail, *phead, *ptail;
        head.insert(beginWord);
        tail.insert(endWord);
        int dist = 2;
        while (!head.empty() && !tail.empty())
        {
            if (head.size() < tail.size())
            {
                phead = &head;
                ptail = &tail;
            }
            else
            {
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> temp;
            for (auto iter = phead->begin(); iter != phead->end(); ++iter)
            {
                string word = *iter;
                wordSet.erase(word);
                for (int p = 0; p < word.size(); ++p)
                {
                    char letter = word[p];
                    for (int k = 0; k < 26; ++k)
                    {
                        word[p] = 'a' + k;
                        if (ptail->find(word) != ptail->end())
                            return dist;
                        if (wordSet.find(word) != wordSet.end())
                        {
                            temp.insert(word);
                            wordSet.erase(word);
                        }
                    }
                    word[p] = letter;
                }
            }
            ++dist;
            swap(*phead, temp);
        }
        return 0;
    }
};
