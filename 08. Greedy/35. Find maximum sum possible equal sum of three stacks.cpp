// https://www.geeksforgeeks.org/find-maximum-sum-possible-equal-sum-three-stacks/

// T.C => O(n1 + n2 + n3), S.C => O(1)

// Returns maximum possible equal sum of three stacks
// with removal of top elements allowed
int maxSum(int s1[], int s2[], int s3[], int n1, int n2, int n3) {
	int sum1 = 0, sum2 = 0, sum3 = 0;
	// Finding the initial sum of s1.
	for (int i = 0; i < n1; ++i) {
		sum1 += s1[i];
	}
	// Finding the initial sum of stack2.
	for (int i = 0; i < n2; ++i) {
		sum2 += s2[i];
	}
	// Finding the initial sum of stack3.
	for (int i = 0; i < n3; ++i) {
		sum3 += s3[i];
	}
	// As given in question, first element is top of stack..
	int tp1 = 0, tp2 = 0, tp3 = 0;
	while (1) {
		// If any stack is empty
		if (tp1 == n1 || tp2 == n2 || tp3 == n3) return 0;
		// If sum of all three stack are equal.
		if (sum1 == sum2 && sum2 == sum3) return sum1;
		// Finding the stack with maximum sum and removing its top element.
		if (sum1 >= sum2 && sum1 >= sum3) {
			sum1 -= s1[tp1++];
		}
		else if (sum2 >= sum1 && sum2 >= sum3) {
			sum2 -= s2[tp2++];
		}
		else if (sum3 >= sum2 && sum3 >= sum1) {
			sum3 -= s3[tp3++];
		}
	}
	return 0;
}