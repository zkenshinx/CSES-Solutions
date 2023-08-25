#include <bits/stdc++.h>

using namespace std;

void solve(string& str) {
	int max_repetition = 0;
	for (int i = 0; i < str.size(); ) {
		int j = i;
		while (j < str.size() && str[i] == str[j]) 
			++j;
		max_repetition = max(max_repetition, j - i);
		i = j;
	}
	cout << max_repetition << endl;
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
