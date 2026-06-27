class LRUCache {   
public:
    list<pair<int, int>> lst; 
    unordered_map<int, list<pair<int, int>>::iterator> mp; 
    int cap; 

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        lst.splice(lst.begin(), lst, mp[key]);
        mp[key] = lst.begin();

        return mp[key]->second; 
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            lst.splice(lst.begin(), lst, mp[key]);
            mp[key] = lst.begin();
            mp[key]->second = value; 
            return;
        }

        if (lst.size() == cap) {
            mp.erase(lst.back().first); 
            lst.pop_back(); 
        }

        lst.push_front({key, value});
        mp[key] = lst.begin();
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */