// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

// T.C => O(n*log(n)), S.C => O(1)

int findPlatform(int arr[], int dep[], int n) {
	sort(arr, arr + n);
	sort(dep, dep + n);
	int plat_needed = 1, ans = 1;
	int i = 1, j = 0;
	while (i < n && j < n) {
		if (arr[i] <= dep[j]) {
			plat_needed++;
			i++;
		}
		else {
			plat_needed--;
			j++;
		}
		ans = max(ans, plat_needed);
	}
	return ans;
}