#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void helper(vector<int>& freq, string& current, vector<string>& result) {
    bool found = false;
    for (int i = 0; i < freq.size(); ++i) {
        if (freq[i] > 0) {
            found = true;
            current.push_back('a' + i);
            freq[i]--;
            helper(freq, current, result);
            freq[i]++;
            current.pop_back();
        }
    }
    if (!found) 
        result.push_back(current);
}

void solve(string& str) {
    vector<int> freq(26);
    for (auto ch : str)
        freq[ch - 'a']++;
    
    vector<string> result;
    string current;
    
    helper(freq, current, result);

    cout << result.size() << '\n';
    for (auto s : result)
        cout << s << '\n';
}

int main() {
    /* Faster Input/Output */
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    /* Input */
    string str;
    cin >> str;

    solve(str);
    return 0;
}