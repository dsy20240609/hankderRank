#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

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
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}



/*
 * Complete the 'extractAndAppendSponsoredNodes' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST head as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* extractAndAppendSponsoredNodes(SinglyLinkedListNode* head) {
   if (head == nullptr || head->next == nullptr) {
        return head;
   }
   vector<int> odd;
   vector<int> even;
   int index=0;
   SinglyLinkedListNode* p=head;
   while(p!= nullptr) {
    if(index%2 == 0) {
        even.push_back(p->data);
    } else {
        odd.push_back(p->data);
    }
    index++;
    p=p->next;
   }
   SinglyLinkedListNode* dummy= new SinglyLinkedListNode(0);
   SinglyLinkedListNode* newhead=dummy;
   for(size_t i =0; i < odd.size();++i) {
    SinglyLinkedListNode* node = new SinglyLinkedListNode(odd[i]);
        dummy->next=node;
        dummy=dummy->next;
   }
   std::reverse(even.begin(),even.end());
   for(size_t i =0; i < even.size();++i) {
    SinglyLinkedListNode * node = new SinglyLinkedListNode(even[i]);
        dummy->next= node;
        dummy = dummy->next;
   }
   return newhead->next;
}

int main()
{
    SinglyLinkedList* head = new SinglyLinkedList();

    string head_count_temp;
    getline(cin, head_count_temp);

    int head_count = stoi(ltrim(rtrim(head_count_temp)));

    for (int i = 0; i < head_count; i++) {
        string head_item_temp;
        getline(cin, head_item_temp);

        int head_item = stoi(ltrim(rtrim(head_item_temp)));

        head->insert_node(head_item);
    }

    SinglyLinkedListNode* result = extractAndAppendSponsoredNodes(head->head);

    print_singly_linked_list(result, "\n");
    cout << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
