## All imp #define in cpp
> imp points about `#define xyz abc`

```cpp

	#define setbits(x)      __builtin_popcountll(x) // gives number of set bits in a number
	#define zrobits(x)      __builtin_ctzll(x) // gives number of leading zeros 
	#define ps(x,y)         fixed<<setprecision(y)<<x // set y precision after decimal 
	#define mk(arr,n,type)  type *arr=new type[n]; // makes arr of size n 
	#define EPS   			1e-9 // almost zero 
	#define PI    			3.1415926535897932384626433832795
	#define w(x)            int x; cin>>x; while(x--)
	#define MOD             1000000007 // 1e9+7
	#define DEB(x)  		cout << "[ " << #x << " ==> " << x << " ]" << endl;// print variable and it's value x=>5
	#define NL()   cout << endl;
	#define MAX_CHAR 256 // number of char

```