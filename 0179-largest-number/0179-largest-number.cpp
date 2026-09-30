class Solution {
public:
    static bool cmp(string a, string b) {
        return a + b > b + a;
    }

    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        for (int x : nums) {
            arr.push_back(to_string(x));
        }

        sort(arr.begin(), arr.end(), cmp);

        string ans = "";

        for (string s : arr) {
            ans += s;
        }

        if (ans[0] == '0')
            return "0";

        return ans;
    }
};