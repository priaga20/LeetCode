/*Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 -> capacity  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

class LRUCache {
    int c;
    //using as a doubly ended queue, least recently used element is at the end
    list<pair<int,int>> l;   
    //key:address of node in list
    unordered_map<int,list<pair<int,int>>::iterator> m;  
    
public:
    LRUCache(int capacity) {
        c=capacity;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end())
        {
            //if already exists then return its value and push it to the front of list
            //bcoz accesssed recently
            auto i=m[key];
            int ans=i->second;
            l.erase(i);
            l.push_front(make_pair(key,ans));
            m[key]=l.begin();
            return ans;
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        //key value pair already exists so update its position in list
        if(m.find(key)!=m.end())
        {
            auto i=m[key];
            l.erase(i);
            l.push_front(make_pair(key,value));
            m[key]=l.begin();
        }
        //make a new entry in cache
        else
        {
            if(l.size()!=c)
            {
                l.push_front(make_pair(key,value));
                m[key]=l.begin();
            }
            else
            {
                //delete least recently used entry and add new one
                auto i=l.back();  //back() returns a direct reference and not a pointer
                int k=i.first;  //key of entry being deleted
                l.pop_back();
                m.erase(k);
                l.push_front(make_pair(key,value));
                m[key]=l.begin();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */