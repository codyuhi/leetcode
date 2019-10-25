// This is the first solution that I found. It is very messy and inefficient.
// Runtime 1036 ms, faster than 5.02% of c++ online submissions
// Memory is 254.9 MB, less than 6.97%
// Terrible

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        int current = 0;
        set<char> visited;
        stack<char> reverb;
        for(int i = 0; i < s.length(); i++){
            cout << "Processing " << s[i] << endl;
            if(visited.find(s[i]) != visited.end()){
                cout << s[i] << " is in the set" << endl;
                if(longest < current){
                    longest = current;
                    cout << "longest substring is now " << longest << " chars long" << endl;
                }
                current = 0;
                visited = {};
                while(!reverb.empty()){
                    cout << "Evaluating " << reverb.top() << " in the stack" << endl;
                    if(reverb.top() != s[i]){
                        cout << "popping " << reverb.top() << endl;
                        reverb.pop();
                    }else{
                        cout << "found " << s[i] << endl;
                        i = reverb.size();
                        cout << "i is now " << i << endl;
                        cout << "this points to " << s[i] << endl;
                        break;
                    }
                }
                i--;
                cout << "The set is now " << visited.size() << " elements large" << endl;
            }else{
                cout << "Did not find " << s[i] << " in the set.  Inserting to set now." << endl;
                visited.insert(s[i]);
                cout << "adding char to stack" << endl;
                reverb.push(s[i]);
                cout << "The set is now " << visited.size() << " elements large" << endl;
                current++;
                cout << "the current size is now " << current << endl;
                if(longest < current){
                    longest = current;
                    cout << "longest substring is now " << longest << " chars long" << endl;
                }
            }
        }
        return longest;
    }
};