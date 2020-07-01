#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
#define PAUSE \
	int t;    \
	cin >> t
#define int long long
#define vi vector<long long>
#define mapii map<long long, int>
#define mapci map<char, int>
#define append(x) push_back(x)
#define tcase          \
	long long t;       \
	scanf("%lld", &t); \
	while (t--)
#define prq priority_queue
#define fio                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL)
// #define debug(x, y) cout<<"case #"<<x<<" at itr #"<<y<<endl
#define debug(x) cout << "case #" << x << endl
#define ff first
#define ss second
#define range(ini, x) for (int itr = ini; itr < x; itr++)
#define takearr(x)    \
	for (auto &i : x) \
	cin >> i
#define print(x)     \
	for (auto i : x) \
		cout << i << " ";
#define FOR(x, y) for (int i = x; i < y; i++)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define foreach(i, x) for (auto i : x)
#define setbitcount __builtin_popcount
// #define range(ini, x, step) for( int itr = ini, i < x; itr += step )
using namespace std;
// using namespace __gnu_pbds;
// template < class type > using oset=tree<type, null_type,less<type>, rb_tree_tag,tree_order_statistics_node_update>;
const int mmx = 1e5 + 1;
const int mnx = 1e4 + 1;
const int mmod = 1e9 + 7;

int power(int a, int b, int m = mmod) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int inv( int x ){
	return power( x, mmod - 2 );
}

int mod( int num ){
	return num % mmod;
}

int fact( int num ){
	int ans = 1;
	for( int i = 1; i <= num; ++i ){
		ans = mod( ans * i );
	}
	return ans;
}

signed main()
{
	int t;
	cin>>t;
	while(t--){
		int N, T, M;
		cin>>N>>T>>M;
		int U = N - M;
		if( U < T )
			cout<<mod(1)<<endl;
		else{
		///Failing Probability U!(N-T)! / (N!(U-T)!)
		int neum = mod( fact(U) * fact( N - T ) );
		int denom = mod( fact(N) * fact( U - T ));
		//find main ans
		int ansNeum = mod( denom - neum + mmod );
		int ansDenom = denom;
		int finalAns = mod( ansNeum * inv( ansDenom ) );
		cout<<finalAns<<endl;
		}
	}
    return 0;
}
