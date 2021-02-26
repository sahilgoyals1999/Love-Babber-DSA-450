// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

// T.C => O(n*log(n)), S.C => O(n)

void FindMedian::insertHeap(int &x) {
	// if size of max heap is zero put element in it
	if (max.size() == 0) {
		max.push(x);
	}
	else {
		// if element is greater than max heap top then
		// push element in min heap else in max heap
		if (x > max.top()) {
			min.push(x);
		}
		else {
			max.push(x);
		}
		balanceHeaps();
	}
	getMedian();
}

// Function to balance heaps
void FindMedian::balanceHeaps() {
	if ((max.size() - min.size()) == 2) {
		min.push(max.top());
		max.pop();
	}
	else if ((min.size() - max.size()) == 1) {
		max.push(min.top());
		min.pop();
	}
}

// Function to return getMedian
double FindMedian::getMedian() {
	if (max.size() - min.size() == 1) return max.top();
	return (max.top() + min.top()) / 2.0;
}