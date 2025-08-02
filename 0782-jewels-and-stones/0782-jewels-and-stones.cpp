class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewelsMap;
        int count=0;
        for(char j:jewels){
            jewelsMap.insert(j);
        }
       for(char s:stones){
        if(jewelsMap.count(s))
        count++;
       }
       return count;
    }
};