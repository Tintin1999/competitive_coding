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


int fx( int num ){

	int n = num - 1;
	return ( n * ( n + 1 ) / 2 );

}

signed main()
{
	int C;
	cin>>C;

	vector <float> times;

	for0(i,C){

		int x, y, v;
		cin>>x>>y>>v;
		int dist = x * x + y * y;
		float ttt = dist / ( v * v * 1.0 );
		times.push_back(ttt);

	}

	// for( auto i: times ) cout<<i<<endl;

	map <float, int> timeHash;
	for0(i,C){
		timeHash[ times[i] ]++;
	}
	int counter = 0;
	for( auto i: timeHash ){
		counter += fx( i.ss );
	}
	cout<<counter<<endl;
    return 0;
}
