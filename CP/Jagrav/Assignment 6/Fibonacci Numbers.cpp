#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<iostream>
#include<vector>
#include<fstream>
#include<cmath>
#include<string>
#include<set>
#include<map>
#include<utility>
#include<algorithm>
#include<iomanip>
#include<stack>
#include<queue>
#include<chrono>
#include<unordered_set>
#include<unordered_map>
#include<random>
#include<bitset>
#include<sstream>
 
using namespace std;
using namespace __gnu_pbds;
 
template<class T> using oset= tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; 
// find_by_order, order_of_key
 
typedef long double ld;
typedef uint64_t ull;
typedef int64_t ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<double> vd;
typedef vector<int64_t> vll;
typedef vector<string> vs;
typedef vector<long double> vld;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;
typedef vector<vector<int64_t>> vvll;
typedef vector<vector<long double>> vvld;
typedef vector<vector<double>> vvd;
typedef vector<vector<char>> vvc;
typedef vector<vector<vector<bool>>> vvvb;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<vector<vector<int64_t>>> vvvll;
typedef vector<vector<long double>> vvvld;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<vector<vector<char>>> vvvc;
typedef pair<int,int> pii;
typedef pair<int64_t,int64_t> pll;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef set<int> si;
typedef set<ll> sll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<ll,ll>> vpll;
typedef vector<vector<pair<ll,ll>>> vvpll;
typedef tuple<ll,ll,ll> tll;    
typedef vector<tll> vtll;
// typedef unordered_set us;
// typedef ordered_set os;
// typedef unordered_map um;
// typedef ordered_map om;
 
 
#define pb push_back
#define pob pop_back()
#define sz size()
#define ff first
#define ss second
#define PI 3.14159265359
#define M1 ll(998244353)
#define MMM 2e5+5
#define MOD ll(1000000007)
#define INF 1500000000000000000
#define NINF -1500000000000000000
#define lp0(i,n) for(ll i=0;i<n;i++)
#define lp1(i,n) for(ll i=1;i<=n;i++)
#define lp(i,a,b) for(ll i=a; i<=b; i++)
#define rlp(i,a,b) for(ll i=a; i>=b; i--)
#define o0(a) cout<<a<<" "
#define o1(a) cout<<a<<"\n"
#define o2(a, b) cout<<a<<" "<<b<<"\n"
#define o3(a, b, c) cout<<a<<" "<<b<<" "<<c<<"\n"
#define o4(a, b, c, d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n"
#define time_start auto start = chrono::high_resolution_clock::now();
#define time_stop auto stop = chrono::high_resolution_clock::now();
#define time_duration auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
#define time_print cout << "Time: "<< duration.count() << " microseconds" << endl;
#define random mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define reach cout<<"Reached!"<<endl;
#define sayn cout<<"NO"<<'\n';
#define sayy cout<<"YES"<<'\n';
 
//------Standard Functions------
 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
 
template<typename T>
T max2(T a,T b){
 
    return max(a,b);
}
template<typename T>
T min2(T a,T b){
 
    return min(a,b);
}
 
template<typename T>
T max3(T a,T b,T c){
 
    return max(a,max(b,c));
}
 
template<typename T>
T max4(T a,T b,T c,T d){
 
    return max(max(a,d),max(b,c));
}
template<typename T>
T min3(T a,T b,T c){
 
    return min(a,min(b,c));
}
 
template<typename T>
T min4(T a,T b,T c,T d){
 
    return min(min(a,d),min(b,c));
}
template <typename T>
T binex(T a, T b, T mod){
 
    T ans=1;
    a%=mod;
 
    while(b>0){
 
        if(b&1){
 
            ans*=a;
            ans%=mod;
        }
        a*=a;
        a%=mod;
        b>>=1;
    }
    return ans;
}
 
template <class T>
ostream& operator<<(ostream &os, vector<T> a){
 
    //os<<"[ ";
    for(auto x:a){
 
        os<<x<<" ";
    }
    //return os<<"]"<<"\n";
    return os;
}
 
template <class T>
ostream& operator<<(ostream &os, set<T> a){
 
    //os<<"{ ";
    for(auto x:a){
 
        os<<x<<" ";
    }
    //return os<<"}"<<"\n";
    return os;
}
 
template <class T>
 
ostream& operator<<(ostream &os, multiset<T> a){
 
    //os<<"{ ";
    for(auto x:a){
 
        os<<x<<" ";
    }
    //return os<<"}"<<"\n";
    return os; 
}
template <class T,class Q>
ostream& operator<<(ostream &os, pair<T,Q> a){
 
    os<<"| ";
    os<<a.ff<<", "<<a.ss<<" ";
    return os<<"|";
}
template<class P,class Q, class T>
 
ostream& operator<<(ostream &os, tuple<P,Q,T> a){
 
    os<<"| "<<(get<0>(a))<<", "<<(get<1>(a))<<", "<<(get<2>(a))<<"|";
    return os;
}
 
ll mod_inverse(ll a, ll mod){
    ll ans=1; ll exp=mod-2;
    while((exp)>0){
        if((exp)&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod; 
        (exp)/=2;
 
    }
    return ans;
}
 
ll abs1(ll n){
    if(n<0){return n*(-1);}
    else return n;
}
 
ll gcd(ll a, ll b){
    while(b!=0){
        ll temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
 
ll lcm(ll a, ll b){
    return(a/gcd(a,b))*b;
}
 
bool prime(ll n) {
    bool isPrime = true;
    if(n==0 || n==1){isPrime=false;}
    else{
        for(ll i=2; i*i<=n; ++i){
            if(n%i==0){isPrime = false;break;}
        }
    }
    return isPrime;
}
 
//---------Start--------
//-----Errorspect19-----
 
std::vector<long long> precompute_factorials(int n) {
    std::vector<long long> fact(n + 1, 1);
    for (int i = 2; i <= n; ++i) {
        fact[i] = fact[i - 1] * i % M1;
    }
    return fact;
}
 
long long mod_inverse(long long x) {
    long long result = 1;
    long long power = M1 - 2;
    while (power > 0) {
        if (power % 2 == 1) {
            result = result * x % M1;
        }
        x = x * x % M1;
        power /= 2;
    }
    return result;
}
 
 
 
 
//vpii dirs = {{-1,0},{0,1},{1,0},{0,-1}};
 
 
// int fun(int n){
    
// }
 
// ll n,m,k;
// vvb vis;
// vs g;
 
// void dfs(ll a, ll b){
//  if(min(a,b)<0 || a>=n || b>=m || g[a][b]=='X' || g[a][b]=='#' || vis[a][b]){
//      return;
//  }
//  vi(s[a][b]=1;
//  dfs(a+1,b);
//  dfs(a-1,b); 
//  dfs(a,b+1);
//  dfs(a,b-1);
 
 
//  if(k!=0){
//      g[a][b]='X'; k--;
//  }
//  return;
// }
 
 
// vvi adj(n); vi ind(n); 
// vi BFS(){
//  vi ordering;
//  queue<int> q; vb vis(n+1); vis[1]=1;
//  q.push(1);
 
//  while(!q.empty()){
//      int u=q.front();
//      ordering.pb(u);
//      q.pop(); 
//      for(int v:adj[u]){
//          if(!vis[v]){
//              vis[v]=1;   q.push(v);
//          }
//      }
//  }
//  return ordering;
// }
 
// unsigned mod_pow(unsigned num, unsigned pow, unsigned mod)
// {
//     unsigned long long test;
//     unsigned long long n = num;
//     for(test = 1; pow; pow >>= 1)
//     {
//         if (pow & 1)
//             test = ((test % mod) * (n % mod)) % mod;
//         n = ((n % mod) * (n % mod)) % mod;
//     }
 
//     return test; /* note this is potentially lossy */
// }
 
 
 
// Taken from GfG
void multiply(vvll& A,vvll& B)
{
    vvll C(2, vll(2));
    C[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
    C[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
    C[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
    C[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;
    A[0][0] = C[0][0];
    A[0][1] = C[0][1];
    A[1][0] = C[1][0];
    A[1][1] = C[1][1];
}
 
 
vvll power(vvll M,int expo)
{
    vvll ans = {{1,0},{0,1}};
    while(expo) {
        if(expo & 1)
            multiply(ans, M);
        multiply(M, M);
        expo >>= 1;
    }
    return ans;
}
 
 
 
int main(){
 
    //time_start;
 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    cout.tie(NULL);
    
    ll tt=1;
 
    //cin>>tt;
 
 
    lp1(ii,tt){
 
        ll n; cin>>n;  
        if (n == 0 || n == 1)
        {cout<<1<<'\n'; continue;}
 
        vvll M = { { 1, 1 }, { 1, 0 } };
        vvll F = { { 1, 0 }, { 0, 0 } };
 
        vvll res = power(M, n - 1);
 
        multiply(res, F);
 
        cout<<res[0][0] % MOD<<'\n';
    }
    
    
    // time_stop
    // time_duration;
    // time_print;
}