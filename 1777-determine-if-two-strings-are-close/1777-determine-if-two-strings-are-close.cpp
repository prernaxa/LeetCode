class Solution {
public:
    bool closeStrings(string word1, string word2) {
       if(word1.size()!=word2.size()) return false;

       unordered_map<char, int> freq1, freq2;
       for(char c: word1) freq1[c]++;
       for(char c: word2) freq2[c]++;

       unordered_set<char> set1, set2;
       for(auto &p: freq1) set1.insert(p.first);
       for(auto &p: freq2) set2.insert(p.first);

       if(set1 != set2) return false;

       vector<int> vals1, vals2;
       for(auto &p: freq1) vals1.push_back(p.second);
       for(auto &p: freq2) vals2.push_back(p.second);

       sort(vals1.begin(), vals1.end());
       sort(vals2.begin(), vals2.end());

       return vals1 == vals2;

    }
};