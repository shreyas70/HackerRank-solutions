

/*
https://www.interviewbit.com/problems/partition-list/

Time Complexity - O(n)
Space Complexity - O(1)

*/
ListNode* Solution::partition(ListNode* A, int B) {

    
    if(!A) return A;
    ListNode* before = new ListNode(0);
    ListNode* beforeItr = before;
    
    ListNode* after = new ListNode(0);
    ListNode* afterItr = after;
    
    ListNode* cur=A;
    
    while(cur)
    {
        if(cur->val<B)
        {
            beforeItr->next=cur;
            beforeItr=beforeItr->next;
        }
        else
        {
            afterItr->next=cur;
            afterItr = afterItr->next;
        }
        
        cur=cur->next;

    }
    
    if(afterItr)
        afterItr->next = NULL;
    
    beforeItr->next=after->next;
    return before->next;
}
