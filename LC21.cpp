#include <iostream>
#include <vector>

using namespace std;



  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         ListNode* delta;
         if(list1==nullptr){
            return list2;
         }

         if(list2==nullptr){
            return list1;
         }

        if(list1->val>list2->val){
            delta = list2;
            list2 = list2->next;
        }
        else{
            delta = list1;
            list1 = list1->next;
        }

        ListNode *head = delta;

        while(list1!=nullptr && list2!=nullptr ){
            if(list1->val < list2->val){
                delta->next = list1;
                list1 = list1->next;
                delta = delta->next;
            }
            else{
                delta->next = list2;
                list2 = list2->next;
                delta = delta->next;
            }
        }
        ListNode *k = head;
        while(&k==nullptr){
            cout<< k->val << " ";
            k = k->next;
        }

        return head;
        
    }
};


int main(){


    return 0;
}