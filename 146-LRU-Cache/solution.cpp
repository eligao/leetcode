class LRUCache{

private:
	list<pair<int, int> > queue_list;	//link queue of <key,val>
	unordered_map<int, list<pair<int, int>>::iterator > hash_map;	//
	int capacity;

public:
	LRUCache(int capacity) :
	capacity(capacity)
	{
		
	}

	int get(int key) {
		auto it_map = hash_map.find(key);
		auto it_queue = queue_list.end();
		int val=-1;
		if (it_map != hash_map.end())	//if key found
		{
			it_queue = it_map->second;
			val = it_queue->second;				
			queue_list.push_back(*it_queue);	//copy the elem to the beginning of queue
			queue_list.erase(it_queue);			//remove old elem
			hash_map[key] = --queue_list.end();	//update map to the elem
		}
		return val;
	}

	void set(int key, int value) {
		auto it_map = hash_map.find(key);
		if (it_map != hash_map.end())	//if key found
		{
			auto it_queue = it_map->second;	
			queue_list.erase(it_queue);	//erase the old key
		}
		else	//key not found,  
		{
			if (queue_list.size() == capacity)	//if already full
			{
				hash_map.erase(hash_map.find(queue_list.front().first));
				queue_list.pop_front(); //deque the last recent used key
			}
		}
		queue_list.push_back(make_pair(key, value)); 
		hash_map[key] = --queue_list.end();	//enque new key
	}
};