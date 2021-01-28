// https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/

// T.C => O(), S.C => O(1)

// checks if s and t are rotations of each other
bool areRotations(string s, string t) {
	// Check if sizes of two strings are same
	if (s.length() != t.length()) return false;
	string temp = s + s;
	return (temp.find(t) != string::npos);
}