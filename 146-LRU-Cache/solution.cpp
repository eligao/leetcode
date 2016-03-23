class LRUCache{

private:
	list<pair<int, int> > queue_list;	//link queue of <key,val>
	unordered_map<int, list<pair<int, int>>::iterator > hash_map;	//
	int capacity;

public:
	LRUCache(int capacity) :capacity(capacity)	{}

	int get(int key) {
		auto it_map = hash_map.find(key);
		if (it_map == hash_map.end())	return -1;//if key not found
		queue_list.push_front(*it_map->second);	//copy the elem to the beginning of queue
		queue_list.erase(it_map->second);			//remove old elem
		it_map->second = queue_list.begin();
		return it_map->second->second;
	}

	void set(int key, int value) {
		auto it_map = hash_map.find(key);
		if (it_map != hash_map.end())	//if key found
		{
			queue_list.erase(it_map->second);	//erase the old key
		}
		else	//key not found,  
		{
			if (queue_list.size() == capacity)	//if already full
			{
				hash_map.erase(queue_list.rbegin()->first);
				queue_list.pop_back(); //deque the last recent used key
			}
		}
		queue_list.push_front(make_pair(key, value)); 
		hash_map[key] = queue_list.begin();	//enque new key
	}
};
