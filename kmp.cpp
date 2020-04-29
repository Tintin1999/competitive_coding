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
#define minheap priority_queue
#define fio                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL)
// #define debug(x, y) cout<<"case #"<<x<<" at itr #"<<y<<endl
#define debug(x) cout << "case #" << x << endl
#define ff first
#define ss second
#define str string
#define range(ini, x) for (int itr = ini; itr < x; itr++)
#define takearr(x)    \
	for (auto &i : x) \
	cin >> i
#define print(x)     \
	for (auto i : x) \
		cout << i << " "; \
	cout<<endl;
#define FOR(x, y) for (int i = x; i < y; i++)
#define for0(i, n) for (int i = 0; i < n; i++)
#define for1(i, n) for (int i = 1; i <= n; i++)
#define foreach(i, x) for (auto i : x)
#define setbitcount __builtin_popcount
//******************/
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
//******************/
// #define range(ini, x, step) for( int itr = ini, i < x; itr += step )
using namespace std;
// using namespace __gnu_pbds;
// template < class type > using oset=tree<type, null_type,less<type>, rb_tree_tag,tree_order_statistics_node_update>;
const int mmx = 1e5 + 1;
const int mnx = 1e4 + 1;
const int mmod = 1e9 + 7;

/* KMP */
vi genlps( str text ){

	int n = text.length();
	vi lps(n,0);
	int i = 1, len = 0;

	while( i < n ){
		if( text[i] == text[len] ){
			++len;
			lps[i] = len;
			++i;
		}
		else{

			if( len == 0 ){
				++i;
			}
			else{
				len = lps[len - 1];
			}
		}
	}
	return lps;

}

void printmatch( str text, str pattern ){

	int n = text.length(), m = pattern.length(), i = 0, j = 0;

	vi lps = genlps( pattern );

	while( i < n ){

		if( text[i] == pattern[j] ){
			++i;
			++j;
		}
		if( j == m ){
			cout<<"Match found at index "<< i - j <<endl;
			j = lps[ j - 1 ];
		}
		else if( i < n && text[i] != pattern[j] ){
			if( j == 0 )
				++i;
			else{
				++i;
				j = lps[ j - 1 ];
			}
		}

	}

}

signed main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    str text, pattern;
    cin>>text;
    cin>>pattern;

	printmatch( text, pattern );
	
    return 0;
}