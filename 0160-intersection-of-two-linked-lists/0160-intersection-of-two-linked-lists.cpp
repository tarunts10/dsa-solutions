/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*ListNode *collisionPoint(ListNode *t1,ListNode *t2,int d){
        while(d){
            d--;
            t1=t1->next;
        }
        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;
        }
        return t1;
    }*/
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /*ListNode* temp1=headA;
        ListNode* temp2=headB;
        unordered_map<ListNode*,int> mpp;

        while(temp1!=NULL){
            mpp[temp1]=1;
            temp1=temp1->next;
        }

        while(temp2!=nullptr){
            if(mpp.find(temp2)!=mpp.end()){
                return temp2;
            }
            temp2=temp2->next;
        }
        return NULL;*/

        /*ListNode* t1=headA;
        ListNode* t2=headB;
        int l1=0,l2=0,d;

        while(t1!=NULL){
            l1++;
            t1=t1->next;
        }
        while(t2!=NULL){
            l2++;
            t2=t2->next;
        }
        d=abs(l1-l2);
        t1=headA;
        t2=headB;
        if(l1>l2){
            return collisionPoint(t1,t2,d);
        }
        else{
            return collisionPoint(t2,t1,d);
        }
        return nullptr;*/

        ListNode* t1=headA;
        ListNode* t2=headB;

        if(headA==NULL||headB==NULL){return NULL;}

        while(t1!=t2){
            t1=t1->next;
            t2=t2->next;
            if(t1==t2){return t1;}
            if(t1==NULL){t1=headB;}
            if(t2==NULL){t2=headA;}
        }
        return t1;
    }
};