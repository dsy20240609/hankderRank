
using namespace std;


class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        std::cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}



/*
 * Complete the 'removeKthNodeFromEnd' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST head
 *  2. INTEGER k
 */


 //* For your reference:
 
  SinglyLinkedListNode {
      int data;
      SinglyLinkedListNode* next;
  };
 


SinglyLinkedListNode* removeKthNodeFromEnd(SinglyLinkedListNode* head, int k) {
    SinglyLinkedListNode* res = head;
    if (head== nullptr) {
        return res;
    }
    
    SinglyLinkedListNode* dummy = new SinglyLinkedListNode(0); 
    SinglyLinkedListNode* fast=head;
    SinglyLinkedListNode* slow = head;
    dummy->next = slow;

    while(k>0 && fast!= nullptr&& fast->next != nullptr) {
        fast=fast->next;
        k--;
    }
    if (k >0) {return head;}
    while(fast!=nullptr && fast->next != nullptr) {
        fast=fast->next;
        dummy=slow;
        slow = slow->next;
    }
    SinglyLinkedListNode* next = slow->next;
    dummy->next=next;
    if (slow == head) {
    return head->next;
    } else {
        return head;
    }
}