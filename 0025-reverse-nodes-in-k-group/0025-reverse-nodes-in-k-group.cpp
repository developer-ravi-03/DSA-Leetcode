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
    void reverse(ListNode* left, int times){
        ListNode* prev=NULL;
        ListNode* curr=left;
        while(times--){
            ListNode* nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;

        ListNode* left=head;
        ListNode* right=NULL;
        ListNode* res=NULL;
        ListNode* prevleft=NULL;
        int times=k;

        while(left!=NULL){
            right=left;
            for(int i=0;i<(times-1);i++){
                if(right==NULL) break;
                right=right->next;
            }

            if(right){
                ListNode* nextleft=right->next;
                reverse(left,times);

                if(res==NULL){
                    res=right;
                }

                if(prevleft){
                    prevleft->next=right;
                }
                prevleft=left;
                left=nextleft;
            }else{
                if(res==NULL){
                    res=left;
                }
                if(prevleft){
                    prevleft->next=left;
                }
                break;
            }
        }
        return res;
    }
};