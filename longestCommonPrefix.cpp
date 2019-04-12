class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() > 0){
        string ans = strs[0];
        string ans2 = ans;
        bool prefix = true;
        for(int i = 1; i < strs.size(); i++){
            string ans3 = "";
            for(int j = 0; j < strs[i].length(); j++){
                if(ans.length() >= j){
                    if(strs[i][j] == ans[j]){
                        ans3 += ans[j];
                    }else{
                        break;
                    }
                }
            }
            if(ans3.length() < ans2.length()){
                ans2 = ans3;
            }
        }
        return ans2;
        }else{
            return "";
        }
    }
};