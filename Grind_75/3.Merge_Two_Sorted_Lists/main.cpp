#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* curr;

void printLN(ListNode* list){

    cout << "Value of list node: ";
    while(list != nullptr){
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

ListNode* sortListNodes(ListNode* list1, ListNode* list2) {
    // if list1 happen to be NULL
		// we will simply return list2.
        if(list1 == NULL)
            return list2;
		
		// if list2 happen to be NULL
		// we will simply return list1.
        if(list2 == NULL)
            return list1;
        
        ListNode * ptr = list1;
        if(list1 -> val > list2 -> val)
        {
            ptr = list2;
            list2 = list2 -> next;
        }
        else
        {
            list1 = list1 -> next;
        }
        ListNode *curr = ptr;
        
		// till one of the list doesn't reaches NULL
        while(list1 &&  list2)
        {
            if(list1 -> val < list2 -> val){
                curr->next = list1;
                list1 = list1 -> next;
            }
            else{
                curr->next = list2;
                list2 = list2 -> next;
            }
            curr = curr -> next;
                
        }
		
		// adding remaining elements of bigger list.
        if(!list1)
            curr -> next = list2;
        else
            curr -> next = list1;
            
        return ptr;

}

int main(){
    
    ListNode list1 = ListNode(1);
    ListNode list2 = ListNode(2);
    ListNode list4 = ListNode(4);
    ListNode listA = list1;
    listA.next = &list2;
    list2.next = &list4;

    ListNode list12 = ListNode(1);
    ListNode list3 = ListNode(3);
    ListNode list42 = ListNode(4);
    ListNode listB = list12;
    listB.next = &list3;
    list3.next = &list42;

    printLN(&listA);
    printLN(&listB);
    ListNode* listC = sortListNodes(&listA,&listB);
    printLN(listC);

    return 1;
}