// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

// T.C => O(n), S.C => O(n)

long long getMaxArea(long long a[], int n) {
	long long mx = 0;
	stack<long long> s;
	int i = 0;
	// considering each bar as min bar i.e fixing the right obstacle and finding left obstacle by stack
	// if we found a obstacle calculate area otherwise push it into the stack
	// for a bar obstacle is nearest lesser height bar
	// 1 3 2 1 => for 3 obstacle are 1 and 2
	// if stack is empty => area = a[tp] * r
	// else => area = a[tp] * (r - l - 1)
	while (i < n) {
		if (s.empty() || a[s.top()] <= a[i]) {
			s.push(i);
			++i;
		}
		else {
			int tp = s.top();
			s.pop();
			long long area;
			if (s.empty()) {
				area = a[tp] * i;
			}
			else {
				area = a[tp] * (i - s.top() - 1);
			}
			mx = max(mx, area);
		}
	}
	while (!s.empty()) {
		int tp = s.top();
		s.pop();
		long long area;
		if (s.empty()) {
			area = a[tp] * i;
		}
		else {
			area = a[tp] * (i - s.top() - 1);
		}
		mx = max(mx, area);
	}
	return mx;
}