#include 				<bits/stdc++.h>

using 					namespace std;
#define fastio          std::ios_base::sync_with_stdio(false)
#define PAUSE_EXE       assert(false)
#define inchar          getchar_unlocked
#define LL              long long
#define MAX             100005LL
#define LIMIT           3165
#define MOD             1000000007LL
#define REP(i,n)        for(__typeof(n) i=0; i<n; ++i)
#define REP1(i,n)       for(__typeof(n) i=1; i<=n; ++i)
#define REP2(i,n)       for(__typeof(n) i=1; i<n; ++i)
#define CREP(i,n)       for(__typeof(n) i=n-1; i>=0; --i)
#define CREP1(i,n)      for(__typeof(n) i=n; i>=1; --i)
#define CREP2(i,n)      for(__typeof(n) i=n-1; i>=1; --i)
#define MYREP(i,a,b)    for(__typeof(a) i=a; i<=b; ++i)
#define MYCREP(i,a,b)   for(__typeof(a) i=b; i>=a; --i)
#define SET(a, b)       memset(a, b, sizeof(a))
#define sz(a)           int((a).size())
#define pb              push_back
#define mp              make_pair
#define fi              first
#define sec             second
#define all(c)          (c).begin(),(c).end()
#define allr(c)         (c).rbegin(),(c).rend()
#define reset(c)        (c).clear()
#define loop(c,i)       for(typeof(c.begin()) i = c.begin(); i != c.end(); i++)
#define present(c,x)    ((c).find(x) != (c).end())
#define cpresent(c,x)   (find(all(c),x) != (c).end())

template <typename T> T max(T &a, T &b) {return (!(a < b) ? a : b);}
template <typename T> T min(T &a, T &b) {return (a < b ? a : b);}
template <typename T> T mod(T a, T b) {return (a < b ? a : a % b);}
LL mulmod(LL a,LL b, LL m){LL q=(LL)(((long double)a*(long double)b)/(long double)m);LL r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template <typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template <typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mod(x*p, m);p=mod(p*p, m);n>>=1;}return x;}
template <typename T> T InverseEuler(T a, T m){return (a==1? 1 : power(a, m-2, m));}
template <typename T> T gcd(T a, T b){return (!b)? a:__gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
template <typename T> T bitpop(T x){return __builtin_popcount (x);} 



// LL n, b ,p , n1, n2,tow, k=0,bt;
// LL facto2,facto1; LL fact[MAX+1];
//template <typename T> T facto(T n1){facto1 = 1;for (facto2 = 2; facto2 <= n1; ++facto2){facto1=mod(facto2*facto1,MOD);}return facto1;}
//template <typename T> T ncr(T n1, T n2){if(n1<=MAX && n2<=MAX)return mod(fact[n1]*InverseEuler(mod(fact[n2]*fact[n1-n2],MOD),MOD),MOD);else return (facto(n1)*InverseEuler((facto(n2) * facto(n1-n2))%MOD,MOD))%MOD;}  

// void pre()
// {
// 	//fact[0]=1;for(i=1;i<=MAX;++i) fact[i]=mod((i*fact[i-1]),MOD);

// } 
LL n,l,r,cnt;

string giveAns(LL num)
{	
	string kk,kk1;
	if(num>2)
	{
		kk = giveAns(num>>1);
		kk1=kk;
		kk+= to_string(num&1);
		kk+=kk1;
		return kk;
	}
	else if(num==1||num==0)
		return to_string(num);
	else return to_string(101);
}

int main()
{
  	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		//freopen("out.txt", "w", stdout);
	#endif
	fastio;

	cin>>n>>l>>r;
	string kk = giveAns(n);
	for (LL i = l-1; i <=r-1; ++i)
	{
		if(kk[i]=='1')cnt++;
	}
	cout<<cnt;
return 0;
}











