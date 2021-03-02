// https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

// T.C => O(n*log(n)), S.C => O(n)

#define ll long long

ll merge(ll a[], ll temp[], ll l, ll m, ll r) {
	ll count = 0;
	ll i = l, j = m, k = l;
	while (i < m && j <= r) {
		if (a[i] <= a[j]) {
			temp[k++] = a[i++];
		}
		else {
			temp[k++] = a[j++];
			count += (m - i);
		}
	}
	while (i < m) {
		temp[k++] = a[i++];
	}
	while (j <= r) {
		temp[k++] = a[j++];
	}
	for (int i = l; i <= r; ++i) {
		a[i] = temp[i];
	}
	return count;
}

ll merge_sort(ll a[], ll temp[], ll l, ll r) {
	if (l >= r) return 0;
	ll inv_count = 0;
	ll m = l + (r - l) / 2;
	inv_count += merge_sort(a, temp, l, m);
	inv_count += merge_sort(a, temp, m + 1, r);
	inv_count += merge(a, temp, l, m + 1, r);
	return inv_count;
}

ll inversionCount(ll a[], ll n) {
	ll temp[n];
	return merge_sort(a, temp, 0, n - 1);
}