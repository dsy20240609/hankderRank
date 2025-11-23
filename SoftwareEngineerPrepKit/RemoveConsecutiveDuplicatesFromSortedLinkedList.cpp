// this is not correct version, but don't know why this is not working.
SinglyLinkedListNode* deleteDuplicates(SinglyLinkedListNode* head) {
  if(head == nullptr || head->next == nullptr) {return head;}
  SinglyLinkedListNode* slow=head;
  SinglyLinkedListNode* fast=head->next;
  while(fast!=nullptr && slow != nullptr) {
    if ( (slow->data != fast->data) && (slow->next == fast)) {
        slow=slow->next;
        fast=fast->next;
    } else if ((slow->data !=fast->data) && (slow->next !=fast)) {
        slow->next = fast;
        slow =fast;
        fast=fast->next;
    } else {
        fast=fast->next;
    }
  }
  return head;
} 

/*think the problem in a simple way, simulate the logic using code, you need to use only one pointer
every time you check the cur value and next value, when you found duplicate, you keep a record of the current
location, and continue to look for the different value.*/
SinglyLinkedListNode* deleteDuplicates(SinglyLinkedListNode* head) {
  if(head == nullptr || head->next == nullptr) {return head;}
  SinglyLinkedListNode* search=head;
  while(search !=nullptr && search->next != nullptr) {
    if ( search->data == search->next->data) {
         SinglyLinkedListNode* firstNode=search;
         while(search != nullptr && search->next != nullptr && search->data == search->next->data) {
            search = search->next;
         }
         if (search !=nullptr) {
            firstNode->next=search->next;
         } else {
            firstNode->next=nullptr;
         }
    } else {
        search=search->next;
    } 
  }
  return head;
} 