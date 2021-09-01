

// num = 35642
// 0  -  9 
// one
// 10 
// 67

// 67
// r + make_string()

// 0-9 one
// 11 13 -19

// 21 - string
// 31 -
// 1 
// 1 hadread 21
// 6354321 = odd 
// sixty three lakh fiftyfour thousand + make_string()

// five lakh fourtythree 
// lakh,


// map<int, string> mp;
// 1 "one";


unordered_map<int, string> mp;
mp[1] = 'one';
mp[2] = 'two'
|
mp[10] = 'ten'
mp[90] = "";





string helper(int choice, string join, vector<char> digit) {
    // odd 64 laks + (54321)]

    // '63'
    //  63
    int first_num = stoi(len[0] + len[1]);
    string str = "";
    for (int i = 2; i < len.size(); i++) {
        str += len[i];
    }

    return make_string(first_num) + join + make_string(stoi(str));
}


string make_string(int num) {
    // digit_len [7, 5)
    // [5, 3) thousand
    // [3, 2)
    // [1]
    if (mp[num] != mp.end()) return mp[num];
    vector<char> len = digit_len(num);
    int n = len.size();
    if (n >= 7 and n < 5) {
        // lakh range
        if (n & 1) {
            
        }
        else {
            return helper(1, " lakh ", len);
        }
    }
    else if ()
}










