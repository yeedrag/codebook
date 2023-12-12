#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define guracute ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(x) cerr<<#x<<" = "<<(x)<<endl;
#define all(x) (x).begin(), (x).end()
#define uni(a) a.resize(unique(all(a)) - a.begin())
#define ll long long
#define int ll
using namespace std;
/*
	Structure for Binary-Indexed-Tree (BIT).
	Usage:
		Implementation is 1-based index, range sum single point update only.
		Can be used for any operation that satisfys the associative property.
		Can also calculate suffix by swapping for loops, or let idx = BIT::sz - idx;
		Initialize with BIT (name)(int sz) to initialize a BIT with zeros with length n.
		.sum(int r) : obtain prefix sum till index r (inclusive).
		.sum(int l, int r) : obtain sum from index l to index r (inclusive).
		.add(int idx, int val) : add val in index idx.
	Time complexity:
		initialize: O(N)
		sum: O(NlogN)
		add: O(NlogN)
*/
 
struct BIT {
	vector<int> bit;
	int sz; // size of BIT
	int lowbit(int n) {return (n & -n);}
	BIT(int sz) {
		this -> sz = sz + 1; // 1 is added because 0 ~ n
		bit.assign(sz + 1, 0);
	}
	int sum(int idx) {
		int ret = 0;
		for(; idx > 0; idx -= lowbit(idx)) ret += bit[idx];
		return ret;
	}
	int sum(int l, int r) {return sum(r) - sum(l - 1);}
	void add(int idx, int val) {
		for(; idx <= sz - 1; idx += lowbit(idx)) {
			bit[idx] += val;
		}
	}
};
 
/*
	Below is implementation for codeforces 61E. Enemy is weak.
	Find the number of triplets such that i < j < k and a_i > a_j > a_k.
*/
signed main() {
	guracute;
	int n;
	cin >> n;
	vector<int> vec(n);
	BIT prefix(n), suffix(n);
	for(int i = 0; i < n; i++) cin >> vec[i];
	vector<int> vec2 = vec;
	sort(all(vec2));
	uni(vec2);
	vector<int> discrete_vec(n + 1);
	for(int i = 1; i <= n; i++) {
		discrete_vec[i] = (lower_bound(all(vec2), vec[i - 1]) - vec2.begin()) + 1; 
	}
	vector<int> suffix_vec(n + 1, 0); // save i < j && a_i > a_j 
	vector<int> prefix_vec(n + 1, 0); // save j < k && a_j > a_k
	for(int i = 1; i <= n; i++) {
		suffix_vec[i] = suffix.sum(n - discrete_vec[i] + 1);
		suffix.add(n - discrete_vec[i] + 1, 1);
	}
	for(int i = n; i >= 1; i--) {
		prefix_vec[i] = prefix.sum(discrete_vec[i]);
		prefix.add(discrete_vec[i], 1);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += prefix_vec[i] * suffix_vec[i];
	}
	cout << ans << endl;
	return 0;
}