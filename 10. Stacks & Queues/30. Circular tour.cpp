// https://practice.geeksforgeeks.org/problems/circular-tour/1

// T.C => O(n), S.C => O(1)

int tour(petrolPump p[], int n) {
	// Consider first petrol pump as a starting point
	int start = 0, end = 1;
	int curr_petrol = p[start].petrol - p[start].distance;
	/* Run a loop while all petrol pumps are not visited.
	And we have reached first petrol pump again with 0 or more petrol */
	while (end != start || curr_petrol < 0) {
		// If curremt amount of petrol in truck becomes less than 0, then
		// remove the starting petrol pump from tour
		while (curr_petrol < 0 && start != end) {
			// Remove starting petrol pump. Change start
			curr_petrol -= p[start].petrol - p[start].distance;
			start = (start + 1) % n;
			// If 0 is being considered as start again, then there is no possible solution
			if (start == 0) return -1;
		}
		// Add a petrol pump to current tour
		curr_petrol += p[end].petrol - p[end].distance;
		end = (end + 1) % n;
	}
	// Return starting point
	return start;
}