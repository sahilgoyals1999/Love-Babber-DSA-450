// https://leetcode.com/problems/find-the-duplicate-number/

// T.C => O(n*log(n)), S.C => O(1)

int findDuplicate(vector<int>& nums) {
	int n = nums.size() - 1;
	int low = 1, high = n;
	while (low < high) {
		int mid = (low + high) / 2;
		int count = 0;
		for (int &num : nums) {
			if (num <= mid) count++;
		}
		if (count > mid) high = mid;
		else low = mid + 1;
	}
	return low;
}