#include <iostream>
#include <string>
using namespace std;

int solve(string s) {
    if(s.empty()) return -1;
    int f[26] = {0};
    for(char c : s) {
        if(c<'a' || c >'z') continue; // idhr lower cases ka check lagadia
        f[c - 'a']++;
    }
    for(int i = 0; i < s.size(); ++i) {
        if(s[i]<'a'||s[i]>'z') continue;
        if(f[s[i]-'a'] ==1) return i;
    }
    return -1;
}

int main() {
    string s;
    cin >> s;
    int idx = solve(s);
    if(idx == -1) cout << "No Unique Character Found\n";
    else cout << s[idx] << " " << idx << "\n";
}
