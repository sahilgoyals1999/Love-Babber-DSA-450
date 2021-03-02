// https://www.geeksforgeeks.org/find-maximum-meetings-in-one-room/

// T.C => O(n*log(n)), S.C => O(n)

// Structure for storing starting time,
// finishing time and position of meeting.
class meeting {
public:
	int start;
	int end;
	int pos;
};

bool comp(meeting m1, meeting m2) {
	return (m1.end < m2.end);
}

// Function for finding maximum meeting in one room
vector<int> maxMeeting(int s[], int f[], int n) {
	meeting meet[n];
	for (int i = 0; i < n; ++i) {
		// Starting time of meeting i.
		meet[i].start = s[i];
		// Finishing time of meeting i
		meet[i].end = f[i];
		// Original position/index of meeting
		meet[i].pos = i + 1;
	}
	// Sorting of meeting according to their finish time.
	sort(meet, meet + n, comp);
	vector<int> ans;
	// Initially select first meeting.
	ans.push_back(meet[0].pos);
	// time_limit to check whether new meeting can be conducted or not.
	int time_limit = meet[0].end;
	// Check for all meeting whether it can be selected or not.
	for (int i = 1; i < n; ++i) {
		if (meet[i].start >= time_limit) {
			// Push selected meeting to vector
			ans.push_back(meet[i].pos);
			// Update time limit.
			time_limit = meet[i].end;
		}
	}
	return ans;
}