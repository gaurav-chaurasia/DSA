#include <iostream>
#include <algorithm>
#include <vector>
// #include <set>
using namespace std;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define NL()   cout << endl;
typedef long long ll;
typedef unsigned long long ull;
int temp, res;

template <typename ForwardIterator, typename T>
ForwardIterator first_equal_to_or_less_than(ForwardIterator first, ForwardIterator last, T value) {

    auto it = std::lower_bound(first, last, value);

    if (*it == value) return it;

    return (it == first ? last : --it);
}

int main() {
    int i, temp, n, m; cin >> n >> m;
    // multiset<int> h;
    vector<int> t(m), h(n);

    for (i = 0; i < n; i++) {
        cin >> temp;
        h.at(i) = temp;
    }
    for (i = 0; i < m; i++) {
        cin >> temp;
        t.at(i) = temp;
    }
    sort(h.begin(), h.end());

    // for(auto it: h) DEB(it); NL();
    // for(auto it: t) DEB(it); NL();
    
    while(!t.empty()) {
        auto x = t.begin();
        auto it = first_equal_to_or_less_than(h.begin(), h.end(), *x);
        
        // DEB(*x);
        // DEB(*it);

        it != h.end() ?  res = *it : res = -1;

        t.erase(x);
        if (it != h.end()) h.erase(it);
        
        cout << res << endl;
    }
    return 0;
}
