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
    ListNode* sortList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) {return head;}
        ListNode *mid = new ListNode;
        ListNode *head2 = new ListNode;
        mid = findmid(head);
        head2= mid->next;
        mid->next = NULL ;
        
        ListNode *finalhead = new ListNode;
        finalhead = merge(sortList(head), sortList(head2));
        return finalhead;
        
        
    }
    
    ListNode *findmid(ListNode *head) {
     ListNode *slow = head;
     ListNode *fast = head->next;
    
    while(slow->next != NULL && (fast!=NULL && fast->next!=NULL)) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
    ListNode *merge(ListNode *firstNode,ListNode *secondNode) {
    ListNode *merged = new ListNode;
    ListNode *temp = new ListNode;
    
    
    merged = temp;
 
    
    while(firstNode != NULL && secondNode != NULL) {
     
        if(firstNode->val <= secondNode->val) {
            temp->next = firstNode;
            firstNode = firstNode->next;
        }
         
        else {
            temp->next = secondNode;
            secondNode = secondNode->next;
        }
        temp = temp->next;
    }
    

    while(firstNode!=NULL) {
        temp->next = firstNode;
        firstNode = firstNode->next;
        temp = temp->next;
    }
         while(secondNode!=NULL) {
        temp->next = secondNode;
        secondNode = secondNode->next;
        temp = temp->next;
    }
    
    return merged->next;
}
 
 
};