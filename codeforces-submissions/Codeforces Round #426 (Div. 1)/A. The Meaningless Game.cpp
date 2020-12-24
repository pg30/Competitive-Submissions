#include <cmath>
#include <cstdio>

using namespace std;

typedef long long ll;

const int MAXR = 1000005;

ll cubic_root(ll x)
{
    ll l = 0, r = MAXR;
    while (l != r) {
        ll m = (l + r + 1) / 2;
        if (m * m * m > x)
            r = m - 1;
        else
            l = m;
    }
    return l;
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        ll a, b;
        scanf("%I64d %I64d", &a, &b);
        ll x = cubic_root(a * b);
        if (x * x * x != a * b)
            puts("No");
        else if (a % x == 0 && b % x == 0)
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}
