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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr){return nullptr;}
        while(head!=nullptr&&head->val==val){
            head=head->next;
        }
        if(head==nullptr){return nullptr;}

        ListNode* temp=head->next;
        ListNode* prev=head;
        

        while(temp!=nullptr){
            
            if(temp->val==val){
                ListNode* del=temp;
                
                prev->next=temp->next;
                temp=temp->next;
                //free(del);
            }
            else{
                temp=temp->next;
                prev=prev->next;
            }
        }
        return head;
    }
};