test cast 
1 5 1 
first 1 is the length of the linked list, although this is not provided as input,
the 1 first element from the end of the linkedlist is out of range, since the linkedlist
only has one element, so the 0 element from the end is the end it self, the first element from the end
is out of range, this is acutually one corner case that you code needs to consider.
it means that if k >0 means the k is out of the range of the linked list, so you can return
head directly

4 5 6 7 8 3
4 is the length of the linked list, 5 6 7 8 is the element of the linkedlist, and k=3. means
you need to delete the 3th element from the end, the 0 elemet from the end is the end it self
which is 8 ,the 1st element from the end is 7, so 5 is the 3th element from the end, this is another coner case
that you need take into consider, since the element you need to delete is the head, so you need to return a new head,
which is head->next, use slow == head to determine if the head is the element you need to delete.

for other case, element you need to delete is in the middle of the linked list, which means
slow pointer point to the element you need to delete and the dummy(prev) pointer points to the element just before
the one to be deleted.


two poitners, one fast, one slow, fast pointer moves first k steps, and then slow pointer and fast pointer 
moves together until fast pointer arrives at the last element of the linkedlist, and slow is at the node position which needs to be 
deleted.

