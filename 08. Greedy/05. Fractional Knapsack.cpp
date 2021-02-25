// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

// T.C => O(n*log(n)), S.C => O(1)

bool comp(Item a, Item b) {
	double r1 = (double)a.value / (double)a.weight;
	double r2 = (double)b.value / (double)b.weight;
	return r1 > r2;
}

double fractionalKnapsack(int W, Item a[], int n) {
	double ans = 0.0;
	int curWeight = 0;
	sort(a, a + n, comp);
	for (int i = 0; i < n; ++i) {
		if (curWeight + a[i].weight <= W) {
			curWeight += a[i].weight;
			ans += a[i].value;
		}
		else {
			int remain = W - curWeight;
			ans += ((a[i].value / (double)a[i].weight) * (double)remain);
			break;
		}
	}
	return ans;
}