#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void solve(string& str) {
    vector<int> letter_frequency(26);
    for (auto ch : str)
        letter_frequency[ch - 'A']++;
    // Check maximum only one odd
    int odd_count = 0;
    for (auto count : letter_frequency)
        odd_count += count % 2 == 1;
    if (odd_count > 1) {
        cout << "NO SOLUTION\n";
        return;
    }
    int odd_index = -1;
    string first_half;
    for (int i = 0; i < 26; ++i) {
        char ch = 'A' + i;
        for (int j = 0; j < letter_frequency[i] / 2; ++j) 
            first_half += ch;
        if (letter_frequency[i] % 2 == 1)
            odd_index = i;
    }
    string result = first_half;
    if (odd_index != -1)
        result += 'A' + odd_index;
    reverse(first_half.begin(), first_half.end());
    result += first_half;
    cout << result << endl;
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