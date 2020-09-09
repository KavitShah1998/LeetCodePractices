/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    /*Method 3*/
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* start = head;
        ListNode* end = head;
        
        int m{n};
        while(n--){
            end = end->next;
        }
        if (end == nullptr){
            if(m==1)
                return nullptr;
            else
                return start->next;
        }
        
        while(end->next !=nullptr){
            start = start->next;
            end = end->next;
        }
        
        start->next = start->next->next;
        return head;
    }
    
    /*Method 2*/
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        std::vector<ListNode*> vec;
        ListNode* temp = head;
        while(temp->next!=nullptr){
            vec.push_back(temp);
            temp = temp->next;
        }
        vec.push_back(temp);
        int size = vec.size();
        int index = size - n;
        
        if(index == 0 && size == 1)
            return nullptr;
        else if (index ==0 && size > 1)
            return head->next;
        
        if(index == size-1)
            (vec[index-1])->next = nullptr;
        else
            (vec[index-1])->next = vec[index+1];
        
        return head;
    }
    
    /*Method 1*/
    ListNode* Recursion(ListNode* head, int& n){
        if(head->next!=nullptr){
            head->next = Recursion(head->next, n);
        }
        n--;
        if(n==0){
            return head->next;
        }
        else{
            return head;
        }
        
        
    }
};
