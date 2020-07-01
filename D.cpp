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

pair <int, int> datefx( int num )
{

    int monthdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int month = 1;
    for( int i = 0; i < 12; ++i )
    {
        if( ( num - monthdays[i] ) > 0 )
        {
            ++month;
            num -= monthdays[i];
        }
        else break;
    }
    int day = num;
    return make_pair( month, day );

}

int patfx( pair <int, int> date )
{
    return pow( abs( 6 - date.ff ), 2 ) + abs( date.ss - 15);
}

signed main()
{

    int N, r1, r2, rev;
    cin >> N;
    cin >> r1 >> r2;
    cin >> rev;

    int ans = N;

    for( int tv = 0; tv <= N; ++tv )
    {	
    	int tempRev = 0;
    	int tvRoom = tv;
    	int nonTvRoom = N - tv;

        for( int i = 1; i <= 365; ++i )
        {
            int patients = patfx( datefx(i) );
            if( patients > N ){
            	tempRev += nonTvRoom * r2 + tvRoom * r1;
            }
            else{
            	if( patients > nonTvRoom ){
            		tempRev += nonTvRoom * r2 + ( patients - nonTvRoom ) * r1;
            	}else{
            		tempRev += patients * r2;
            	}
            }
        }
        if( tempRev >= rev ){
        	ans = tv;
        	break;
        }
    }

    cout<<ans<<endl;

    return 0;
}
