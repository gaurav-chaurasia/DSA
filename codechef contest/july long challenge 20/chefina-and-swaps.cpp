// /*
//     try: 
//     not a correct solution 
//     could not find what is wrong in solution  
// */ 



#include <bits/stdc++.h>

using namespace std;

#define sq(a) (a)*(a)
#define EPS   1e-9
#define PI    3.1415926535897932384626433832795
#define MOD   1000000007
 
typedef long long ll;
typedef unsigned long long ull;
 
void solve() {
    int n, temp;
    ll cost = 0;
    cin >> n;
    vector <int> a, b, ab;
    vector < pair<int, int> > a_count, b_count, ab_count;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        a.push_back(temp);
        ab.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        cin >> temp;
        b.push_back(temp);
        ab.push_back(temp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(ab.begin(), ab.end());

    for (int i = 0; i < 2*n; i++) {
        if (ab_count.empty()) {
            ab_count.push_back(make_pair(ab[i], 1));
        } else {
            if (ab[i] != ab_count.back().first) {
                ab_count.push_back(make_pair(ab[i], 1));
            } else {
                ab_count.back().second++;
            }
        }
    }

    for (int i = 0; i < 2*n; i++) {
        if (a_count.empty()) {
            a_count.push_back(make_pair(ab[i], 0));
        } else {
            if (ab[i] != a_count.back().first) {
                a_count.push_back(make_pair(ab[i], 0));
            } else {
                continue;
            }  
        }
    }
    auto ita = a_count.begin();
    for (int i = 0; i < n; ) {
        if (a[i] == ita->first) {
            ita->second++;
            i++;
        } else {
            ita++;
        }
    }
    for (int i = 0; i < 2*n; i++) {
        if (b_count.empty()) {
            b_count.push_back(make_pair(ab[i], 0));
        } else {
            if (ab[i] != b_count.back().first) {
                b_count.push_back(make_pair(ab[i], 0));
            } else {
                continue;
            }  
        }
    }
    auto itb = b_count.begin();
    for (int i = 0; i < n; ) {
        if (b[i] == itb->first) {
            itb->second++;
            i++;
        } else {
            itb++;
        }
    }

    for (auto it: ab_count) {
        if (it.second % 2 == 1) {
            cout << -1 << endl; 
            return;
        }
    }
    int f, m, l;
    f = 0;
    m = a_count.size()-1;
    l = a_count.size()-1;
    while (f < l and f < m) {
        
        if (a_count[f].second == b_count[f].second) f++;
        if (a_count[m].second <= b_count[m].second and m >= 0) m--;
        if (a_count[l].second >= b_count[l].second and l >= 0) l--;
        
        if ((a_count[f].second == b_count[f].second) or (a_count[m].second <= b_count[m].second and m >= 0) or (a_count[l].second >= b_count[l].second and l >= 0)) 
            continue;

        if (a_count[f].second > b_count[f].second) {
            a_count[f].second--;
            b_count[f].second++;
            a_count[l].second++;
            b_count[l].second--;
            cost += (ll) min(b_count[f].first, b_count[l].first);
        } else {
            a_count[f].second++;
            b_count[f].second--;
            a_count[m].second--;
            b_count[m].second++;
            cost += (ll) min(b_count[f].first, b_count[m].first);
        }
    }
    cout << cost << endl;
}
 
int main() {
    int t{0};
    cin >> t;
    while (t--){
       solve();
    }   
    return 0;
}





// #include <bits/stdc++.h>
 
// using namespace std;
 
// typedef long long ll;
// typedef unsigned long long ull;

// void solve() {
//     int n, temp = 0;
//     cin >> n;
//     // vector<int> a(n), b(n);
//     // for (int i =0; i < n; i++) {
//     //     a.at(i) = temp;
//     // }
//     // for (int i =0; i < n; i++) {
//     //     b.at(i) = temp;
//     // }
//     map <int, int> a_count, b_count; 
//     for (int i =0; i < n; i++) {
//         // a_count.at(a.at(i))++;
//         cin >> temp;
//         auto it = a_count.find(temp);
//         if (it != a_count.end())
//             it->second += 1;
//         else 
//             a_count.insert({temp, 1});
        
//     }
//     for (int i =0; i < n; i++) { // storing count b
//         // b_count.at(b.at(i))++;
//         cin >> temp;
//         auto it = b_count.find(temp);
//         if (it != b_count.end())
//             it->second += 1;
//         else 
//             b_count.insert({temp, 1});
//     }
//     // sort(a.begin(), a.end());
//     // sort(b.begin(), b.end());
//     temp = 0;
//     for (auto ita =a_count.begin(), itb =b_count.begin();
//             ita != a_count.end() and itb != b_count.end();
//             ita++, itb++) // checking whether it is already identical 
//         if (ita->first != itb->first or ita->second != itb->second) {
//             temp = -1;
//             break;
//         }
//     if (temp == 0) {// if it is already identical 
//         cout << 0 << endl;
//         return;
//     }
//     // vector<int> count((max(a.at(n-1), b.at(n-1)) + 1), 0);
//     map <int, int> count;
//     for (auto i =a_count.begin(); i != a_count.end(); i++) {
//         auto it = count.find(i->first);
//         if (it != count.end())
//             it->second += i->second;
//         else 
//             count.insert({i->first, i->second});
//     }
//     for (auto i =b_count.begin(); i != b_count.end(); i++) {
//         auto it = count.find(i->first);
//         if (it != count.end())
//             it->second += i->second;
//         else 
//             count.insert({i->first, i->second});
//     }
//     for (auto it = count.begin(); it != count.end(); it++) {
//         // cout << it << " -@- ";
//         if (it->second % 2 != 0) {
//             cout << -1 << endl;
//             return;
//         }
//     }

//     // vector<int> a_count((max(a.at(n-1), b.at(n-1)) + 1), 0), 
//     //             b_count((max(a.at(n-1), b.at(n-1)) + 1), 0);
//     // vector <int> a_swap(n, false), b_swap(n, false);

//     // for (int i =0; i < n; i++) {
//     //     if ((2 * a_count.at(a.at(i))) > count.at(a.at(i))) {
//     //         a_swap.at(i) = 2;
//     //     } else if ((2 * a_count.at(a.at(i))) < count.at(a.at(i))) {
//     //         a_swap.at(i) = 1;
//     //     } else {
//     //         a_swap.at(i) = 0;
//     //     }
//     // }
//     // for (int i =0; i < n; i++) {
//     //     if ((2 * b_count.at(b.at(i))) > count.at(b.at(i))) {
//     //         b_swap.at(i) = 2;
//     //     } else if ((2 * b_count.at(b.at(i))) < count.at(b.at(i))) {
//     //         b_swap.at(i) = 1;
//     //     } else {
//     //         b_swap.at(i) = 0;
//     //     }
//     // }
//     ll cost =0;

//     for (auto ita = a_count.rbegin(); ita != a_count.rend(); ) {
//         auto itb = b_count.find(ita->first);
//         if (itb != b_count.end()) {
//             if (ita->second > itb->second) {
//                 // a has more
//                 for (auto it = b_count.begin(); it != b_count.end(); it++) {
//                     auto it1 = a_count.find(it->first);
//                     if (it1 != a_count.end()) {
//                         if (it->second > it1->second) {
//                             ita->second -= 1;
//                             itb->second += 1;
//                             it->second -= 1;
//                             it1->second += 1;
//                             cost += min(it->first, ita->first);
//                             break;
//                         }
//                     } else a_count.insert({it->first, 0});
//                 }
//             } else if (ita->second < itb->second) {
//                 // b has more
//                 for (auto it = b_count.begin(); it != b_count.end(); it++) {
//                     auto it1 = a_count.find(it->first);
//                     if (it1 != a_count.end()) {
//                         if (it->second < it1->second) {
//                             ita->second += 1;
//                             itb->second -= 1;
//                             it->second += 1;
//                             it1->second -= 1;
//                             cost += min(it->first, ita->first);
//                             break;
//                         }
//                     }
//                 }
//             } else {
//                 ita++;
//             }
//         } else {
//             //a has more insert some 
//             b_count.insert({ita->first, 0});
//         } 
//     }

//     // int j = n-1, k = n-1;
//     // for (int i = 0; i < n; i++) {
//     //     if ((2 * a_count.at(a.at(i))) > count.at(a.at(i))) {
//     //         for ( ; j >= 0; j--) {
//     //             if ((2 * b_count.at(b.at(j))) > count.at(b.at(j))) {
//     //                 b_count.at(a.at(i))++;
//     //                 b_count.at(b.at(j))--;
//     //                 a_count.at(a.at(i))--;
//     //                 a_count.at(b.at(j))++;
//     //                 swap(b.at(j), a.at(i));
//     //                 cost += min(b.at(j), a.at(i));
//     //                 j--;
//     //                 break;
//     //             }
//     //         }
//     //     // } else if ((2 * a_count.at(a.at(i))) < count.at(a.at(i))) {
//     //     //     for ( ; k >= 0; k--) {
//     //     //         if ((2 * b_count.at(b.at(k))) < count.at(b.at(k))) {
//     //     //             b_count.at(b.at(k))++;
//     //     //             a_count.at(a.at(i))--;
//     //     //             swap(b.at(k), a.at(i));
//     //     //             cost += min(b.at(k), a.at(i));
//     //     //         }
//     //     //     }
//     //     } else continue;
//     // }
//     // j = n-1, k = n-1;
//     // for (int i = 0; i < n; i++) {
//     //     if ((2 * b_count.at(b.at(i))) > count.at(b.at(i))) {
//     //         for ( ; j >= 0; j--) {
//     //             if ((2 * a_count.at(a.at(j))) > count.at(a.at(j))) {
//     //                 a_count.at(b.at(i))++;
//     //                 a_count.at(a.at(j))--;
//     //                 b_count.at(b.at(i))--;
//     //                 b_count.at(a.at(j))++;
//     //                 swap(a.at(j), b.at(i));
//     //                 cost += min(a.at(j), b.at(i));
//     //                 j--;
//     //                 break;
//     //             }
//     //         }
//     //     // } else if ((2 * a_count.at(a.at(i))) < count.at(a.at(i))) {
//     //     //     for ( ; k >= 0; k--) {
//     //     //         if ((2 * b_count.at(b.at(k))) < count.at(b.at(k))) {
//     //     //             b_count.at(b.at(k))++;
//     //     //             a_count.at(a.at(i))--;
//     //     //             swap(b.at(k), a.at(i));
//     //     //             cost += min(b.at(k), a.at(i));
//     //     //         }
//     //     //     }
//     //     } else continue;
//     // }
//     cout << cost << endl;
//     return;
// }
 
// int main() {
//     int t{0};
//     cin >> t;
//     while (t--){
//        solve();
//     }   
//     return 0;
// }


// #include <bits/stdc++.h>
 
// using namespace std;
 
// typedef long long ll;
// typedef unsigned long long ull;

// void solve() {
//     int n, temp = 0;
//     cin >> n;
//     vector<int> a(n), b(n);
//     for (int i =0; i < n; i++) {
//         cin >> temp;
//         a.at(i) = temp;
//     }
//     for (int i =0; i < n; i++) {
//         cin >> temp;
//         b.at(i) = temp;
//     }
//     sort(a.begin(), a.end());
//     sort(b.begin(), b.end());
//     ll size = max(a.at(n-1), b.at(n-1));
//     if (size <= 10000000) {
//         temp = 0;
//         for (int i =0; i < n; i++) // checking whether it is already identical 
//             if (a.at(i) != b.at(i)) {
//                 temp = -1;
//                 break;
//             }
//         if (temp == 0) {// if it is already identical 
//             cout << 0 << endl;
//             return;
//         }
//         vector<int> count((max(a.at(n-1), b.at(n-1)) + 1), 0);
//         for (int i =0; i < n; i++) {
//             count.at(a.at(i))++;
//         }
//         for (int i =0; i < n; i++) {
//             count.at(b.at(i))++;
//         }
//         for (auto it : count) {
//             // cout << it << " -@- ";
//             if (it % 2 != 0) {
//                 cout << -1 << endl;
//                 return;
//             }
//         }

//         vector<int> a_count((max(a.at(n-1), b.at(n-1)) + 1), 0), 
//                     b_count((max(a.at(n-1), b.at(n-1)) + 1), 0);
//         // vector <int> a_swap(n, false), b_swap(n, false); 

//         for (int i =0; i < n; i++) {
//             a_count.at(a.at(i))++;
//         }
//         for (int i =0; i < n; i++) {
//             b_count.at(b.at(i))++;
//         }
//         // for (int i =0; i < n; i++) {
//         //     if ((2 * a_count.at(a.at(i))) > count.at(a.at(i))) {
//         //         a_swap.at(i) = 2;
//         //     } else if ((2 * a_count.at(a.at(i))) < count.at(a.at(i))) {
//         //         a_swap.at(i) = 1;
//         //     } else {
//         //         a_swap.at(i) = 0;
//         //     }
//         // }
//         // for (int i =0; i < n; i++) {
//         //     if ((2 * b_count.at(b.at(i))) > count.at(b.at(i))) {
//         //         b_swap.at(i) = 2;
//         //     } else if ((2 * b_count.at(b.at(i))) < count.at(b.at(i))) {
//         //         b_swap.at(i) = 1;
//         //     } else {
//         //         b_swap.at(i) = 0;
//         //     }
//         // }
//         ull cost =0;
//         ll j = 1;
//         for (ll i = size; i > 0; ) { // for a 
//             if ((2 * a_count.at(i)) > count.at(i)) {
//                 for ( ; j <= size; ) {
//                     if ((2 * b_count.at(j)) > count.at(j)) {
//                         b_count.at(i)++;
//                         b_count.at(j)--;
//                         a_count.at(i)--;
//                         a_count.at(j)++;
//                         cost += (ull)min(j, i);
//                         break;
//                     } else {
//                         j++;
//                         continue;
//                     }
//                 }
//             // } else if ((2 * a_count.at(a.at(i))) < count.at(a.at(i))) {
//             //     for ( ; k >= 0; k--) {
//             //         if ((2 * b_count.at(b.at(k))) < count.at(b.at(k))) {
//             //             b_count.at(b.at(k))++;
//             //             a_count.at(a.at(i))--;
//             //             swap(b.at(k), a.at(i));
//             //             cost += min(b.at(k), a.at(i));
//             //         }
//             //     }
//             } else {
//                 i--;
//                 continue;
//             }
//         }
//         j = 1;
//         for (ll i = size; i > 0; ) { // for b
//             if ((2 * b_count.at(i)) > count.at(i)) {
//                 for ( ; j <= size; ) {
//                     if ((2 * a_count.at(j)) > count.at(j)) {
//                         a_count.at(i)++;
//                         a_count.at(j)--;
//                         b_count.at(i)--;
//                         b_count.at(j)++;
//                         cost += (ull)min(j, i);
//                         break;
//                     } else {
//                         j++;
//                         continue;
//                     }
//                 }
//             // } else if ((2 * a_count.at(a.at(i))) < count.at(a.at(i))) {
//             //     for ( ; k >= 0; k--) {
//             //         if ((2 * b_count.at(b.at(k))) < count.at(b.at(k))) {
//             //             b_count.at(b.at(k))++;
//             //             a_count.at(a.at(i))--;
//             //             swap(b.at(k), a.at(i));
//             //             cost += min(b.at(k), a.at(i));
//             //         }
//             //     }
//             } else {
//                 i--;
//                 continue;
//             }
//         }
//         cout << cost << endl;
//         return;
//     } else {
//         int n, temp = 0;
//         cin >> n;
//         // vector<int> a(n), b(n);
//         // for (int i =0; i < n; i++) {
//         //     a.at(i) = temp;
//         // }
//         // for (int i =0; i < n; i++) {
//         //     b.at(i) = temp;
//         // }
//         map <int, int> a_count, b_count; 
//         for (int i =0; i < n; i++) {
//             // a_count.at(a.at(i))++;
//             cin >> temp;
//             auto it = a_count.find(temp);
//             if (it != a_count.end())
//                 it->second += 1;
//             else 
//                 a_count.insert({temp, 1});
            
//         }
//         for (int i =0; i < n; i++) { // storing count b
//             // b_count.at(b.at(i))++;
//             cin >> temp;
//             auto it = b_count.find(temp);
//             if (it != b_count.end())
//                 it->second += 1;
//             else 
//                 b_count.insert({temp, 1});
//         }
//         // sort(a.begin(), a.end());
//         // sort(b.begin(), b.end());
//         temp = 0;
//         for (auto ita =a_count.begin(), itb =b_count.begin();
//                 ita != a_count.end() and itb != b_count.end();
//                 ita++, itb++) // checking whether it is already identical 
//             if (ita->first != itb->first or ita->second != itb->second) {
//                 temp = -1;
//                 break;
//             }
//         if (temp == 0) {// if it is already identical 
//             cout << 0 << endl;
//             return;
//         }
//         // vector<int> count((max(a.at(n-1), b.at(n-1)) + 1), 0);
//         map <int, int> count;
//         for (auto i =a_count.begin(); i != a_count.end(); i++) {
//             auto it = count.find(i->first);
//             if (it != count.end())
//                 it->second += i->second;
//             else 
//                 count.insert({i->first, i->second});
//         }
//         for (auto i =b_count.begin(); i != b_count.end(); i++) {
//             auto it = count.find(i->first);
//             if (it != count.end())
//                 it->second += i->second;
//             else 
//                 count.insert({i->first, i->second});
//         }
//         for (auto it = count.begin(); it != count.end(); it++) {
//             // cout << it << " -@- ";
//             if (it->second % 2 != 0) {
//                 cout << -1 << endl;
//                 return;
//             }
//         }

//         // vector<int> a_count((max(a.at(n-1), b.at(n-1)) + 1), 0), 
//         //             b_count((max(a.at(n-1), b.at(n-1)) + 1), 0);
//         // vector <int> a_swap(n, false), b_swap(n, false);

//         // for (int i =0; i < n; i++) {
//         //     if ((2 * a_count.at(a.at(i))) > count.at(a.at(i))) {
//         //         a_swap.at(i) = 2;
//         //     } else if ((2 * a_count.at(a.at(i))) < count.at(a.at(i))) {
//         //         a_swap.at(i) = 1;
//         //     } else {
//         //         a_swap.at(i) = 0;
//         //     }
//         // }
//         // for (int i =0; i < n; i++) {
//         //     if ((2 * b_count.at(b.at(i))) > count.at(b.at(i))) {
//         //         b_swap.at(i) = 2;
//         //     } else if ((2 * b_count.at(b.at(i))) < count.at(b.at(i))) {
//         //         b_swap.at(i) = 1;
//         //     } else {
//         //         b_swap.at(i) = 0;
//         //     }
//         // }
//         ull cost =0;

//         for (auto ita = a_count.rbegin(); ita != a_count.rend(); ) {
//             auto itb = b_count.find(ita->first);
//             if (itb != b_count.end()) {
//                 if (ita->second > itb->second) {
//                     // a has more
//                     for (auto it = b_count.begin(); it != b_count.end(); it++) {
//                         auto it1 = a_count.find(it->first);
//                         if (it1 != a_count.end()) {
//                             if (it->second > it1->second) {
//                                 ita->second -= 1;
//                                 itb->second += 1;
//                                 it->second -= 1;
//                                 it1->second += 1;
//                                 cost += (ull)min(it->first, ita->first);
//                                 break;
//                             }
//                         } else a_count.insert({it->first, 0});
//                     }
//                 } else if (ita->second < itb->second) {
//                     // b has more
//                     for (auto it = b_count.begin(); it != b_count.end(); it++) {
//                         auto it1 = a_count.find(it->first);
//                         if (it1 != a_count.end()) {
//                             if (it->second < it1->second) {
//                                 ita->second += 1;
//                                 itb->second -= 1;
//                                 it->second += 1;
//                                 it1->second -= 1;
//                                 cost += (ull)min(it->first, ita->first);
//                                 break;
//                             }
//                         }
//                     }
//                 } else {
//                     ita++;
//                 }
//             } else {
//                 //a has more insert some 
//                 b_count.insert({ita->first, 0});
//             } 
//         }

//         // int j = n-1, k = n-1;
//         // for (int i = 0; i < n; i++) {
//         //     if ((2 * a_count.at(a.at(i))) > count.at(a.at(i))) {
//         //         for ( ; j >= 0; j--) {
//         //             if ((2 * b_count.at(b.at(j))) > count.at(b.at(j))) {
//         //                 b_count.at(a.at(i))++;
//         //                 b_count.at(b.at(j))--;
//         //                 a_count.at(a.at(i))--;
//         //                 a_count.at(b.at(j))++;
//         //                 swap(b.at(j), a.at(i));
//         //                 cost += min(b.at(j), a.at(i));
//         //                 j--;
//         //                 break;
//         //             }
//         //         }
//         //     // } else if ((2 * a_count.at(a.at(i))) < count.at(a.at(i))) {
//         //     //     for ( ; k >= 0; k--) {
//         //     //         if ((2 * b_count.at(b.at(k))) < count.at(b.at(k))) {
//         //     //             b_count.at(b.at(k))++;
//         //     //             a_count.at(a.at(i))--;
//         //     //             swap(b.at(k), a.at(i));
//         //     //             cost += min(b.at(k), a.at(i));
//         //     //         }
//         //     //     }
//         //     } else continue;
//         // }
//         // j = n-1, k = n-1;
//         // for (int i = 0; i < n; i++) {
//         //     if ((2 * b_count.at(b.at(i))) > count.at(b.at(i))) {
//         //         for ( ; j >= 0; j--) {
//         //             if ((2 * a_count.at(a.at(j))) > count.at(a.at(j))) {
//         //                 a_count.at(b.at(i))++;
//         //                 a_count.at(a.at(j))--;
//         //                 b_count.at(b.at(i))--;
//         //                 b_count.at(a.at(j))++;
//         //                 swap(a.at(j), b.at(i));
//         //                 cost += min(a.at(j), b.at(i));
//         //                 j--;
//         //                 break;
//         //             }
//         //         }
//         //     // } else if ((2 * a_count.at(a.at(i))) < count.at(a.at(i))) {
//         //     //     for ( ; k >= 0; k--) {
//         //     //         if ((2 * b_count.at(b.at(k))) < count.at(b.at(k))) {
//         //     //             b_count.at(b.at(k))++;
//         //     //             a_count.at(a.at(i))--;
//         //     //             swap(b.at(k), a.at(i));
//         //     //             cost += min(b.at(k), a.at(i));
//         //     //         }
//         //     //     }
//         //     } else continue;
//         // }
//         cout << cost << endl;
//         return;
//     }
// }
 
// int main() {
//     int t{0};
//     cin >> t;
//     while (t--){
//        solve();
//     }   
//     return 0;
// }