#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef pair<int, int> pint;
typedef vector<pair<ll, ll>> vpl;
typedef pair<ll, ll> pll;

#define TestCase \
    int t;       \
    cin >> t;    \
    while (t--)
#define loop for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define ANS cout << ans << "\n"
#define PY cout << "YES\n"
#define PN cout << "NO\n"
#define endl "\n"
const int mod = 1e9 + 7;
const ll NEG_INF = -1e18;
const ll POS_INF = 1e18;
const ll MAX = 1e5 + 1;



bool isDifficult(const string &s) {
    return s.find("FFT") != string::npos || s.find("NTT") != string::npos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    TestCase {
        string str;
        cin >> str;

        if (!isDifficult(str)) {
            cout << str << endl;
            continue;
        }

        int count[26] = {};
        for (char c : str) count[c - 'A']++;

        string result = "";

        for (int i = 0; i < 26; ++i) {
            if ('A' + i != 'F' && 'A' + i != 'N' && 'A' + i != 'T') {
                result.append(count[i], 'A' + i);
                count[i] = 0;
            }
        }

        int f = count['F' - 'A'];
        int n = count['N' - 'A'];
        int t = count['T' - 'A'];

        while (f || n || t) {
            if (f > 0) {
                result += 'F';
                f--;
            }
            if (n > 0) {
                result += 'N';
                n--;
            }
            if (t > 0) {
                result += 'T';
                t--;
            }
        }

        cout << result << endl;
    }

    return 0;
}
