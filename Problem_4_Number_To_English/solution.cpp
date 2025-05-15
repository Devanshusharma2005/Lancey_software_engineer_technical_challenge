#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

vector<string> one = {
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
};

vector<string> ten = {
    "", "", "twenty", "thirty", "forty",
    "fifty", "sixty", "seventy", "eighty", "ninety"
};

vector<string> scale = {
    "", "thousand", "million", "billion", "trillion"
};

string below1000(int n) {
    string res;
    if (n>=100) {
        res += one[n/100] + " hundred";
        n %= 100;
        if (n==1) res += " ";
    }
    if (n >= 20) {
        res+=ten[n / 10];
        if (n%10) res += "-" + one[n%10];
    } else if (n>0) {
        res += one[n];
    }
    return res;
}

string solve(long long num) {
    if (num <0 || num > 999999999999) return "Number out of range";
    if (num == 0) return "zero";

    vector<int> part;
    while (num > 0) {
        part.push_back(num % 1000);
        num /= 1000;
    }

    string res;
    for (int i = part.size()-1; i >= 0; --i) {
        if (part[i] == 0) continue;
        string cur = below1000(part[i]);
        if (!scale[i].empty()) cur += " " + scale[i];
        if (!res.empty()) res += " ";
        res += cur;
    }
    return res;
}

int main() {
    fastio;
    long long num;
    while (cin >> num) {
        cout << solve(num) << '\n';
    }
}


