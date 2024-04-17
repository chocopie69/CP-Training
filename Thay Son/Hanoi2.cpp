#include <bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++)
        if ('a' <= s[i] && s[i] <= 'z')
            s[i] = ' ';
    /// s = "            00023    23        00     23    9            9"
    /// s = "adjlfdjljfld00023jlvc23jfdljfld00fljfl23fdfd9fdjljlfdsajl9"
    istringstream iss(s);
    set<string> taphop;
    string n;
    ///set<unsigned long long> taphop;
    ///unsigned long long n;
    while (iss >> n) {
        int i = 0;
        int len2 = n.size();
        while (i < len2 && n[i] == '0') {
            n[i] = ' ';
            i++;
        }

        istringstream iss2(n);
        string n2;
        iss2 >> n2;
        ///cout << n2 << endl;
        taphop.insert(n2);
    }
    cout << taphop.size();
}

