class Solution {
public:
    int lengthOfLongestSubstring(string str) {

        unordered_map<char,int> mp;
        int l = 0;
        int r = 0;
        int max_len = 0;

        while(r < str.size()){
            if(mp.find(str[r])==mp.end()){
                mp[str[r]]=r;
            }
            else{
                l = max(l, mp[str[r]] + 1);
                mp[str[r]]=r;
            }
            max_len = max(max_len, (r-l+1));
            r++;
        }

        return max_len;

        // <----> first approach <----->


        // unordered_set<char> st;
        // int left = 0;
        // int right = 0;
        // int max_len = 0;

        // while(right < s.size()){
        //     if(st.find(s[right])==st.end()){
        //         st.insert(s[right]);
        //         max_len = max(max_len,right - left + 1);
        //         right++;
        //     }
        //     else{
        //         st.erase(s[left]);
        //         left++;
        //     }
        // }
        // return max_len;
    }
};