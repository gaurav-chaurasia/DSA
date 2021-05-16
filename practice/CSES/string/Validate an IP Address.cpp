// #include <bits/stdc++.h>
// using namespace std;

// #define DEB(x) cout << "[ " << #x << " ==> " << x << " ]";
// #define NL() cout << endl;
// typedef long long ll;
// typedef unsigned long long ull;

// int validate(string s)
// {
//     int n = s.size();

//     // checking if any part of string is more then 3 digit
//     if (n > 3)
//         return false;

//     // checing if all digit present are number
//     for (int i = 0; i < n; i++)
//         if ((s[i] >= '0' && s[i] <= '9') == false)
//             return false;

//     // checking
//     if (s.find('0') == 0 && n > 1)
//         return false;

//     int num = stoi(s);
//     cout << num << endl;
//     return num >= 0 && num <= 255;
// }

// int isValid(string s)
// {
//     // vector<string> strs;
//     // stringstream check(s);
//     // string temp;

//     // while (getline(check, temp, '.'))
//     // {
//     //     strs.push_back(temp);
//     // }

//     // for (auto it : strs)
//     // {
//     //     if (!validate(it))
//     //     {
//     //         return 0;
//     //     }
//     // }
//     // return 1;

//     int cnt = 0;
//     string str = "";
//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] == '.')
//         {
//             cnt++;
//             if (str.empty() || (str.front() == '0' && str.size() > 1) || stoi(str) > 255)
//             {
//                 return false;
//             }
//             str = "";
//             continue;
//         }

//         if (!isdigit(s[i]) || str.size() == 3)
//         {
//             return false;
//         }

//         str += s[i];
//     }
//     if (str.empty() || (str.front() == '0' && str.size() > 1) || stoi(str) > 255)
//     {
//         return false;
//     }
//     if (cnt == 3)
//     {
//         return true;
//     }
//     return false;
// }

// int main() {
//     cout << isValid("222.1-1.111.111") << endl;

//     return 0;
// }


int isValid(string s) {
    int count = 0;
    string str = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '.') {
            count++;
            if (str.empty() || (str.front() == '0' && str.size() > 1) || stoi(str) > 255) {
                return 0;
            }
            str = "";
            continue;
        }

        if (!isdigit(s[i]) || str.size() == 3) {
            return 0;
        }

        str += s[i];
    }
    if (str.empty() || (str.front() == '0' && str.size() > 1) || stoi(str) > 255) {
        return 0;
    }
    if (count == 3) {
        return 1;
    }
    return 0;
}



#define BITS 32 
class Solution
{
    public:
    int maxSubarrayXOR(int arr[], int n)
    {
        int index = 0; 
        for (int i = BITS-1; i >= 0; i--) { 
            int max_ind = index; 
            int max_ele = INT_MIN; 
            for (int j = index; j < n; j++) { 
                if ( (arr[j] & (1 << i)) != 0 && arr[j] > max_ele ) 
                    max_ele = arr[j], max_ind = j; 
            } 
 
            if (max_ele == INT_MIN) 
                continue; 
  
            swap(arr[index], arr[max_ind]); 
            max_ind = index; 
  
            for (int j=0; j<n; j++) { 
                if (j != max_ind && (arr[j] & (1 << i)) != 0) 
                    arr[j] = arr[j] ^ arr[max_ind]; 
            } 
            index++; 
        } 
        
        int res = 0; 
        
        for (int i = 0; i < n; i++) 
            res ^= arr[i]; 
        
        return res; 
    }
};