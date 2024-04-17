#include <bits/stdc++.h>
using namespace std;


int main() {
    string s = "434";

    istringstream iss(s);

    int n;
    iss >> n;
    cout << n << endl;

    ostringstream oss;
    oss << 3.14;
    s = oss.str();
    cout << s;
}

