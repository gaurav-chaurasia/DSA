#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define vi vector<int>
#define vc vector<char>
#define vs vector<string>
#define loop(i, n) for (int i=0; i<n; i++)

void solve();

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
}

void change_index(int *index, int arr_len)
{
    if (*index <= arr_len - 2 && arr_len >= 3) {
        *index = *index + 2;
    }
    if (*index == arr_len - 1 && arr_len >= 3) {
        *index = 1;
    }
    if (*index == arr_len - 1 && arr_len >= 3) {
        *index = 2;
    }
    if (arr_len == 2) {
        if (*index == arr_len){
            *index = 1;
        } else {
            *index = arr_len;
        }
        
    }
}

void solve(){
    int N,
        K,
        cur_vertex = 2,
        explode_index;
    cin >> N >> K;
    int arr[N];
    loop (i, N){
        arr[i] = i+1;
    }

    cout << endl;
    while(N>1){
        if (K > 0) {
            change_index(&cur_vertex, N);
            K--;
        } else {
            change_index(&cur_vertex, N);
            explode_index = cur_vertex;

            for (int j = explode_index - 1; j < N-1; j++) {
                arr[j] = arr[j + 1];
            }
            for (int i = 0; i < N; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            N--;
        }
        
        // cout << cur_vertex << " - ";
    }
    cout << arr[0] << endl;
}