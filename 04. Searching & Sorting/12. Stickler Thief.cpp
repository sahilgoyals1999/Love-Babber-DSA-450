// https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1#

// T.C => O(n), T.C => O(1)

ll FindMaxSum(ll a[], ll n) {
	if (n == 1) return a[0];
	ll first = a[0];
	ll second = max(a[0], a[1]);
	for (int i = 2; i < n; ++i) {
		ll third = max(second, first + a[i]);
		first = second;
		second = third;
	}
	return second;
}