// 104ms, 89.93%; 39.1MB, 56.10%
class LRUCache
{
private:
    int _capacity;
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> store;

public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key)
    {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        update(it);
        return it->second.first;
    }

    void put(int key, int value)
    {
        auto it = cache.find(key);
        if (it == cache.end()) {
            if (store.size() == _capacity) {
                cache.erase(store.back());
                store.pop_back();
            }
            store.push_front(key);
        } else {
            update(it);
        }
        cache[key] = make_pair(value, store.begin());
    }

private:
    void update(unordered_map<int, pair<int, list<int>::iterator>>::iterator &it)
    {
        store.erase(it->second.second);
        store.push_front(it->first);
        it->second.second = store.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
