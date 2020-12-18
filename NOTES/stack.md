## stack class cpp
> imp points about `#include <stack>`  
    
> st.push(num)  
> st.pop()  
> st.empty()  
> st.size()  
> st.top()  

#### declare stack
```cpp
	stact<int>            st;
	stact<char>           st;
	stact<string>         st;
	stact<pair<int, int>> st;
```

#### imp methods for stack
```cpp

	int num[] = {1, 2, 3, 4, 5, 6, 7};

	// pushing element in the stack
	st.push(num[0]);
	st.push(num[1]);
	st.push(num[2]);
	st.push(num[3]);

	// checking size of stack
	st.size() // 4

	// cheking top element in stack
	st.top() // returns top element which is 4 in this case

	// checking stack is empaty or not'
	st.empty() // false

	// poping few elements from stack
	st.pop();
	st.pop();
	st.pop();
	st.pop();

```