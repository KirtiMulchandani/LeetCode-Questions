node* reverseLL(node* prev, node* curr, node* next){
    if(curr == NULL)
        return prev;
    
    next = curr->next;
    curr->next = prev;

    prev = curr;
    curr = next;

    return reverseLL(prev, curr, next);

}
