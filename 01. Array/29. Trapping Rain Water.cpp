// https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

// T.C => O(n), S.C => O(1)
// ans += (min(leftMax[i], rightMax[i]) - height[i]);
// 2-pointer Technique

int trappingWater(int a[], int n) {
	int left = 0, right = n - 1;
	int leftMax = 0, rightMax = 0, ans = 0;
	while (left <= right) {
		if (a[left] <= a[right]) {
			if (a[left] >= leftMax) leftMax = a[left];
			else ans += (leftMax - a[left]);
			++left;
		}
		else {
			if (a[right] >= rightMax) rightMax = a[right];
			else ans += (rightMax - a[right]);
			--right;
		}
	}
	return ans;
}