// https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1

// T.C => O(n*log(n)), S.C => O(n)

class Triplet {
public:
	int id;
	int start;
	int end;
};

// Sort acc to end Time
bool comp(Triplet &t1, Triplet &t2) {
	if (t1.end == t2.end) return t1.id < t2.id;
	return t1.end < t2.end;
}

void maxMeetings(int start[], int end[], int n) {
	Triplet meetings[n];
	for (int i = 0; i < n; ++i) {
		meetings[i].id = i + 1;
		meetings[i].start = start[i];
		meetings[i].end = end[i];
	}
	sort(meetings, meetings + n, comp);
	int endTime = -1, ans = 0;
	for (int i = 0; i < n; ++i) {
		if (meetings[i].start > endTime) {
			++ans;
			endTime = meetings[i].end;
		}
	}
	cout << ans;
}