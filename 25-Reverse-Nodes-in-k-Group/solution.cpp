class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head)
			return head;
		if (k <= 1)
			return head;
		ListNode list(-1);
		list.next = head;
		ListNode * it = &list;

		while ((it=reverseKSubGroup(it, k)) != NULL);
		return list.next;
	}



private:
	//reverse next K elements if at least K elements left.
	//otherwise do nothing.
	//return tail this reversed part.
	inline ListNode* reverseKSubGroup(ListNode* head, int k)
	{
		ListNode* it = head;
		for (int i = 0; i<k; i++)    //check number of remaining elems
		{
			if (it->next == NULL)
				return NULL;    //do nothing and return NULL if less than K elems left.
			it = it->next;
		}

		//        it=head->next;
		ListNode*a, *b, *c; //assume in each iteration, we modify a,b->c to a<-b,c and iterate to b,c->d vise versa. 
		a = head;
		b = a->next;
		c = b->next;
		for (int i = 0; i<k - 1; i++)  //k-1 ptrs to reverse among k elems 
		{
			a= b;
			b= c;
			c = b->next;		//iterate forward

			b->next = a;		//and reverse b,a
		}
		it = head->next;
		head->next->next = c;
		head->next = b;

		return it;
	}
};
