// https://practice.geeksforgeeks.org/problems/lru-cache/1

// T.C => O(1), S.C => O(1) for both operations

class LRUCache {
private:
public:
	int cacheSize;
	// ml->first: key, ml->second: value => for storing Node with key, value pair
	list<pair<int, int>> ml;
	// mp->first: key, mp->second: Node's pointer
	unordered_map<int, list<pair<int, int>>::iterator> mp;
	// constructor for cache
	LRUCache(int capacity) {
		cacheSize = capacity;
	}
	// this function should return value corresponding to key
	int get(int key) {
		int ans = -1;
		if (mp.count(key) == 1) {
			// Move the Node corresponding to key to front
			ml.splice(ml.begin(), ml, mp[key]);
			ans = mp[key]->second;
		}
		return ans;
	}
	// storing key, value pair
	void set(int key, int value) {
		// if Node is already present
		if (mp.count(key) == 1) {
			// Move the Node corresponding to key to front
			ml.splice(ml.begin(), ml, mp[key]);
			mp[key]->second = value;
			return;
		}
		// if reached capacity
		if (mp.size() == cacheSize) {
			// get value of last Node in the list
			int x = ml.back().first;
			// remove last Node from list
			ml.pop_back();
			// remove key in map
			mp.erase(x);
		}
		// create new Node in list
		ml.emplace_front(key, value);
		mp[key] = ml.begin();
	}
};
