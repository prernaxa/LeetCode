class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
       unordered_set<string> bannedSet(banned.begin(), banned.end());
        unordered_map<string, int> freqMap;

        string word;
        for (char& c : paragraph) {
           
            if (isalpha(c)) {
                word += tolower(c); 
            } else if (!word.empty()) {
                if (!bannedSet.count(word))
                    freqMap[word]++;
                word.clear();     // reset word
            }
        }


        if (!word.empty() && !bannedSet.count(word)) {
            freqMap[word]++;
        }

    
        string mostFreq;
        int maxCount = 0;
        for (auto& [w, count] : freqMap) {
            if (count > maxCount) {
                maxCount = count;
                mostFreq = w;
            }
        }

        return mostFreq; 
    }
};