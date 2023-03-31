class LRUCache {
    
    /*
        Time Complexity : O(1)
        Space Complexity : O(N)
    */
    
private:
    int n;
    list<int> dll;
    map<int, pair<list<int>::iterator, int>> mp;
    
    void makeRecentlyUsed(int key){
    
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }
    
public:
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        
        makeRecentlyUsed(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
       
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            makeRecentlyUsed(key);
        }else{
            
            dll.push_front(key);
            mp[key] = make_pair(dll.begin(), value);
            n--;
        }
        
       
        if(n < 0){
            int key_tobe_deleted = dll.back();
            dll.pop_back();
            mp.erase(key_tobe_deleted); 
            n++;
        }
    }
};

