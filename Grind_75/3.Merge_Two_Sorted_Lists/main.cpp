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

vector<ListNode> listRes;

void printLN(ListNode* list){

    cout << "Value of list node: ";
    while(list != nullptr){
        cout << list->val << " ";
        list = list->next;
    }
    cout << endl;
}

ListNode* sortListNodes(ListNode* list1, ListNode* list2) {
    //ListNode dummy = ListNode();
    //listRes.push_back(dummy);

    if (list1 == nullptr && list2 !=nullptr){
        for(; list2 != nullptr; list2 = list2->next){
            listRes.push_back(*list2);
        }
        cout << " case 1" << endl;
    }

    else if (list2 == nullptr && list1 !=nullptr){
        for(; list1 != nullptr; list1 = list1->next){
            listRes.push_back(*list1);
        }
        cout << " case 2" << endl;
    }

    else {
        cout << " case 3" << endl;
        while (list1 != nullptr || list2 != nullptr){
            if (list1 == nullptr){
                listRes.push_back(*list2);
                cout << "add node of list2 -> " << list2->val << endl;
                list2 = list2->next;
            }
            else if (list2 == nullptr){
                listRes.push_back(*list1);
                cout << "add node of list1 -> " << list1->val << endl;
                list1 = list1->next;
            }
            else if (list1->val < list2->val){
                listRes.push_back(*list1);
                cout << "add node of list1 -> " << list1->val << endl;
                list1 = list1->next;
            }
            else {
                listRes.push_back(*list2);
                cout << "add node of list2 -> " << list2->val << endl;
                list2 = list2->next;
            }
        }
    }
    return &listRes[0];

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

    ListNode* listC = sortListNodes(&listA,&listB);

    printLN(&listA);
    printLN(&listB);
    printLN(listC);

    return 1;
}