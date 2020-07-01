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

bool prime[ mmx ];

void precomp( ){
    for( int i = 0; i < mmx; i++ ) prime[i] = true;
    for( int i = 2; i * i <= mmx; i++ ){
        if( prime[i] ){
            for( int j = 2; j * i <= mmx; j++ ){
                prime[i * j] = false;
            }
        }
    }

}

int mergeNum( int a, int b ){

    vi bdigits;
    while( b > 0 ){
        bdigits.push_back( b % 10 );
        b /= 10;
    }
    for( int i = bdigits.size() - 1; i >= 0; i-- ){
        a = a * 10 + bdigits[i];
    }
    return a;

}



signed main()
{

    precomp();

    int n1, n2;
    cin>>n1>>n2;

    vi primes;
    for( int i = n1; i <= n2; ++i ){
        if( prime[i] )
            primes.push_back(i);
    }
    
    vi allpermu;
  
    int firstListSize = primes.size();
  
    for( int i = 0; i < firstListSize; ++i ){
        for( int j = i; j < firstListSize; ++j ){
            allpermu.push_back(mergeNum(primes[i], primes[j]));
            allpermu.push_back(mergeNum(primes[j], primes[i]));
        }
        }
    
    set <int> primesNew;

    for( auto i: allpermu ){
        if( prime[i] )
            primesNew.insert(i);
    }

    int listSize = primesNew.size();
    
    int mini = *min_element( primesNew.begin(), primesNew.end() );
    int maxi = *max_element( primesNew.begin(), primesNew.end() );
    
    int fib[listSize];

    fib[0] = mini, fib[1] = maxi;

    for( int i = 2; i < listSize; ++i ){
        fib[i] = fib[ i - 1 ] + fib[ i - 2 ];
    }

    cout<<fib[ listSize - 1 ]<<endl;

    return 0;
}
