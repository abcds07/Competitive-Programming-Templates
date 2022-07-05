#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mod 1000000007LL
#define mod1 998244353LL
#define PI 3.14159265
#define M_PI 3.14159265358979323846
#define endl '\n'
#define cin(a,n) for(i=0;i<n;i++){cin>>a[i];}
#define cout(a,n) for(i=0;i<n;i++)cout<<a[i]<<" ";
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> indexed_set_duplicate;
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;

#define vvi vector<vector<int>>
#define vi vector<int>
#define vll vector<ll>

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
//cout << rng() % 100;

int maximizingXor_in_range_l_to_r(int l, int r) {
	return (1 << int(log2(l ^ r) + 1)) - 1;
}

vector<int> nextGreater(vector<ll>& arr, int n) {
	stack<int> s;
	vector<int> result(n, n);
	for (int i = 0; i < n; i++) {
		while (!s.empty() && arr[s.top()] < arr[i]) {
			result[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	return result;
}

vector<int> prevGreater(vector<ll>& arr, int n) {
	stack<int> s;
	vector<int> result(n, -1);
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && arr[s.top()] < arr[i]) {
			result[s.top()] = i;
			s.pop();
		}
		s.push(i);
	}
	return result;
}



/*
int lim = 100;
	while (lim--) {
		int index = 1;
		random_shuffle(index + a.begin(), a.end());

	}
*/

//clock_t tt = clock();
// while(1){
// 	clock_t z = clock()-tt;
// 	if((double)z/ CLOCKS_PER_SEC > 0.97) break;
// 	//code
// }

bool arraySortedOrNot(int arr[], int n) {

	if (n == 0 || n == 1)
		return true;

	for (int i = 1; i < n; i++) {
		if (arr[i - 1] > arr[i]) {
			return false;
		}
	}
	return true;
}

bool isPerfectSquare(long double x) {
	if (x >= 0) {

		long long sr = sqrt(x);

		return (sr * sr == x);
	}

	return false;
}

ll PowMod(ll n)
{
	ll ret = 1;
	ll a = 2;
	while (n > 0) {
		if (n & 1) ret = ret * a % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}

struct DSU
{
	vector<int> sz;
	vector<int> parent;
	void make_set(int v) {
		parent[v] = v;
		sz[v] = 1;
	}

	int find_set(int v) {
		if (v == parent[v])
			return v;
		return find_set(parent[v]);
	}

	void union_sets(int a, int b) {
		a = find_set(a);
		b = find_set(b);

		if (a != b) {
			if (sz[a] < sz[b])
				swap(a, b);
			parent[b] = a;
			sz[a] += sz[b];
		}
	}

	DSU (int n)
	{
		parent.resize(n);
		sz.resize(n);
		for (int i = 0; i < n; i++) make_set(i);
	}
};

/*
	std::string binary = std::bitset<32>(number_you_want_to_convert).to_string(); //to binary
    std::cout<<binary<<"\n";

    unsigned long decimal = std::bitset<32>(binary).to_ulong();
    std::cout<<decimal<<"\n";
*/

int modpow(int x, int n, int m) {
	if (n == 0) {
		return 1 % m;
	}
	ll u = modpow(x, n / 2, m);
	u = (u * u) % m;
	if (n % 2 == 1) {
		u = (u * x) % m;
	}
	return u;

}
vector<int> factors(int n) {
	vector <int> f;
	for (int x = 2; x * x <= n; x++) {
		while (n % x == 0) {
			f.push_back(x);
			n /= x;
		}
	}
	if (n > 1) {
		f.push_back(n);
	}
	return f;
}
ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
	return (a / gcd(a, b)) * b;
}
unsigned rand32() {
	return (rand() << 16) + rand();
}

int rand(int a, int b) {
	return rand32() % (b - a + 1) + a;
}
ll power(ll x, ll y) {
	ll i, power = 1;
	if (y == 0)
		return 1;
	for (i = 1; i <= y; i++)
		power = power * x;
	return power;
}
ll combination(ll n, ll k)
{
	ll res = 1;

	if (k > n - k) {
		k = n - k;
	}

	for (ll i = 0; i < k; ++i) {
		res = (res * (n - i));
		res /= (i + 1);
	}

	return res;
}
int64_t sqrt_i64(int64_t v) {
	uint64_t q = 0, b = 1, r = v;
	for ( b <<= 62; b > 0 && b > r; b >>= 2);
	while ( b > 0 ) {
		uint64_t t = q + b;
		q >>= 1;
		if ( r >= t ) {
			r -= t;
			q += b;
		}
		b >>= 2;
	}
	return q;
}
inline void normmod(ll &x, ll m) { x %= m; if (x < 0) x += m; }
inline ll summodfast(ll x, ll y, ll m) { ll res = x + y; if (res >= m) res -= m; return res; }
inline int summodfast(int x, int y, int m) { int res = x + y; if (res >= m) res -= m; return res; }
inline void addmodfast(ll &x, ll y, ll m) { x += y; if (x >= m) x -= m; }
inline void addmodfast(int &x, int y, int m) { x += y; if (x >= m) x -= m; }
inline void submodfast(ll &x, ll y, ll m) { x -= y; if (x < 0) x += m; }
inline void submodfast(int &x, int y, int m) { x -= y; if (x < 0) x += m; }
inline ll mulmod(ll x, ll n, ll m) { ll res = 0; normmod(x, m); normmod(n, m); while (n) { if (n & 1) res = summodfast(res, x, m); x = summodfast(x, x, m); n >>= 1; } return res; }
inline ll powmod(ll x, ll n, ll m) { ll res = 1; while (n) { if (n & 1)res = (res * x) % m; x = (x * x) % m; n >>= 1; } return res; }



ll phin(ll n) {ll number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (ll i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;} //O(sqrt(N))


const int MAX_SIZE = 2800001;
vector<int>isprime(MAX_SIZE , true);
vector<int> idx(MAX_SIZE);
vector<int> prime;
vector<int>SPF(MAX_SIZE);//SPF[i]=smallest prime factor of number i

void manipulated_seive(int N) {
	isprime[0] = isprime[1] = false ;
	for (int i = 2; i < N ; i++) {
		if (isprime[i]) {
			prime.push_back(i);
			SPF[i] = i;
		}
		for (int j = 0; j < (int)prime.size() && i * prime[j] < N && prime[j] <= SPF[i]; j++) {
			isprime[i * prime[j]] = false;
			SPF[i * prime[j]] = prime[j] ;
		}
	}
	for (int i = 0; i < (int)prime.size(); i++) {
		idx[prime[i]] = i + 1;
	}
}
//With sieve
vector<int> primeFactors(int n) {
	vector<int> factors;
	while (n > 1) {
		factors.push_back(SPF[n]);
		n /= SPF[n];
	}
	return factors;
}
//Without sieve
vector<ll> primefac(ll x) {
	vll v;
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			//v.pb(i);
			while (x % i == 0) {
				x /= i;
				v.push_back(i);
			}
		}
	}
	if (x > 1) {
		v.push_back(x);
	}
	return v;
}
bool isprime_n(ll n) {
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
bool isPrime(int n) {
	if (n <= 1)  return false;
	if (n <= 3)  return true;
	if (n % 2 == 0 || n % 3 == 0) return false;

	for (int i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}











const int maxN = 501;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int n, m, k, dotcell;
int vis[maxN][maxN];
char a[maxN][maxN];
int ans;

void flood_fill(int x, int y) {
	vis[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (xx >= 0 && xx <= n - 1 && yy >= 0 && yy <= m - 1 && (!vis[xx][yy]) && a[xx][yy] == '.') {
			ans++;
			if (ans > dotcell - k - 1) {
				return;
			}
			flood_fill(xx, yy);
		}
	}
}

void solve() {

	int n;
	cin >> n;

	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int count = (n * (n - 1) / 2) - 1;

	indexed_set_duplicate st;
	int ic = 0;
	for (int i = 0; i < n; i++) {
		ic = ic + (st.size() - st.order_of_key({a[i], i}));
		st.insert({a[i], i});
	}

	cout << ic << endl;


//cout << endl;
}

int main()
{

#ifndef ONLINE_JUDGE

	freopen("input.txt", "r" , stdin);

	freopen("output.txt", "w" , stdout);

#endif

#ifndef ONLINE_JUDGE

	printf("Time Limit Exceeded : %d ms\n", (int)(clock() * 1000. / CLOCKS_PER_SEC)) << endl;

#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// for(int i=0 ; i<n;i++){

	// 	}

	int t;
	cin >> t;

	//int t = 1;

	while (t--) {
		solve();
	}


	// int T;
	// cin >> T;
	// for (int tc = 1; tc <= T; tc++)
	// {
	// 	cout << "Case #" << tc << ": ";
	// 	solve();
	// }

	return 0;

}