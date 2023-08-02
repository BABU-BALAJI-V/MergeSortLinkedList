node* findMid(node* head)
{
    node* slow = head;
    node* fast = head->next;

    while(fast != NULL || fast->next != NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

node* merge(node* left,node* right)
{
    if(left==NULL)
    return right;

    if(right==NULL)
    return left;

    node* ans=new node(-1);
    node* temp=ans;
    //merge two sorted linked list
    while(left!=NULL && right!=NULL)
    {
        if(left->data < right->data)
        {
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }
    while(left!=NULL)
    {
        temp->next=left;
        temp=left;
        left=left->next;
    }
    while(right!=NULL)
    {
        temp->next=right;
        temp=right;
        right=right->next;
    }
    ans = ans->next;
    return ans;
}
node* mergeSort(node* head)
{
    //If list has 0 or 1 elements its already sorted
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node* mid=findMid(head);
    //breaking the list into left and right parts
    node* left=head;
    node* right=mid->next;
    mid->next=NULL;

    //recursive calls for right and left
    mergeSort(left);
    mergeSort(right);

    //merge both 
    node* result=merge(left,right);

    return result;
}