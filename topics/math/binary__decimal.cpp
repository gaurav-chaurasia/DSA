#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;

#define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
#define w(x) int x; cin >> x; while (x--)
#define endl '\n'
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define f first
#define s second
#define MAX_CHAR 256
#define MOD (int)1e9 + 7

// print the array
void print_arr(const vector<int> &arr) {
    cout << "[ ";
    for (auto it: arr) {
        cout << it;
    }
    cout << " ]" << endl;
}

class Solution {
public:
    // ****************************** //
    //      decimal to binary         //
    // ****************************** //
    void decimal_to_binary(int n, vector<int> &arr) {
        arr.clear();
        arr.resize(32);

        int i = 0;
        while (n > 0) {
            arr[i] = n % 2;
            n /= 2;
            i++;
        }

        reverse(all(arr));
        print_arr(arr);
    }

    // ****************************** //
    //              best              //
    // ****************************** //
    void decimal_to_binary(int n, string &str) {
        str = bitset<32>(n).to_string();

        cout << "[ " << str << " ]" << endl;
    }


    // ****************************** //
    //      binary to decimal         //
    // ****************************** //
    void binary_to_decimal (int n, int &ans) {
        int num = n;
        int dec_value = 0;
        int base = 1;

        while (num) {
            int last_digit = num % 10;
            num /= 10;

            dec_value += last_digit * base;
            base = base * 2;
        }

        ans = dec_value;
        cout << ans << endl;
    }

    // ****************************** //
    //              best              //
    // ****************************** //
    void binary_to_decimal (string n, int &ans) {
        ans = stoi(n, 0, 2);

        cout << ans << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Solution *SOL = new Solution();

    int ans;
    string str;
    vector<int> arr; 
    SOL->decimal_to_binary(15, arr);
    SOL->decimal_to_binary(17, arr);
    SOL->decimal_to_binary(23, arr);
    SOL->decimal_to_binary(99, arr);

    SOL->decimal_to_binary(15, str);
    SOL->decimal_to_binary(17, str);
    SOL->decimal_to_binary(23, str);
    SOL->decimal_to_binary(99, str);

    str = "1001";
    int num = 1001;
    SOL->binary_to_decimal(str, ans);
    SOL->binary_to_decimal(num, ans);

    delete SOL;
    return 0;
}
