class LRUCache {
    int max_cap;
    unordered_map<int, int> mp;
    list<int> lruList;
    unordered_map<int, list<int>::iterator> cache;

public:
    LRUCache(int capacity) { max_cap = capacity; }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            lruList.erase(cache[key]);
            lruList.push_front(key);
            cache[key] = lruList.begin();
            return mp[key];
        }

        else {
            return -1;
        }
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            lruList.erase(cache[key]);
            lruList.push_front(key);
            cache[key] = lruList.begin();
            mp[key] = value;
            return;
        }
        if (lruList.size() == max_cap) {
            int last = lruList.back();
            lruList.pop_back();
            cache.erase(last);
            mp.erase(last);
        }
        lruList.push_front(key);
        cache[key] = lruList.begin();
        mp[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
