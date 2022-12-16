// 3. Longest Substring Without Repeating Characters
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector <int> freq(256,0);
        int i=0 ,j=0 , ans = 0;
        while(j<s.length()){
            char ch = s[j];
            int indx = ch;
            freq[indx]++;
            //Window shrink
            while(freq[s[j]] > 1){
                char ch1 = s[i];
                int k = ch1;
                freq[s[i]]--;
                i++;
            }
            ans = max(ans , j-i+1);
            j++;
        }
        return ans;
    }
};