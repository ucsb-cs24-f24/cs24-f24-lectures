ListNode* doubleIt(ListNode* head) {
    ListNode* first = head;
    ListNode* second = head->next;

    first->val *= 2;

    while(second){
        if(second->val < 5){
            second->val *= 2;
        } else {
            second->val = (second->val * 2) % 10;
            first->val++;
        }
        first = first->next;
        second = second->next;
    }

    if(head->val >= 10){
        ListNode* temp = head;
        head = new ListNode(1, temp);
        temp->val = temp->val % 10;
    }

    return head;
}
