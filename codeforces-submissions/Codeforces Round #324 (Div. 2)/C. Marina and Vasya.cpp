#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;

char another(char x, char y) {
    for (char r = 'a'; r <= 'z'; ++r)
        if (x != r && y != r)
            return r;
    return 'z';
}

int main() {
    int n, t;
    cin>>n>>t;
    string a, b;
    cin>>a>>b;

    vector<int> same, different;
    for (int i = 0; i < n; ++i)
        if (a[i] == b[i])
            same.push_back(i);
        else
            different.push_back(i);

    string out;
    out.resize(n);
    for (int i = 0; i < n; ++i)
        out[i] = another(a[i], b[i]);
    while (t < n) {
        if (same.size() >= 1) {
            const int i = same.back();
            same.pop_back();
            out[i] = a[i];
            ++t;
        } else if (different.size() >= 2) {
            const int i = different.back();
            different.pop_back();
            const int j = different.back();
            different.pop_back();
            out[i] = a[i];
            out[j] = b[j];
            ++t;
        } else {
            cout<<"-1"<<endl;
            return 0;
        }
    }
    cout<<out<<endl;
}
