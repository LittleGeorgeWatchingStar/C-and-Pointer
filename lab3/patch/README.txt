if (q1Head == NULL && q2Head == NULL){
        return;
    }
    
    if (q1Head == NULL){
        q1Head = q2Head;
        q1Tail = q2Tail;
        myFront = q1Head;
        myBack = q1Tail;
        q2Head = NULL;
        q2Tail = NULL;
        return;
    }
    
    if (q2Head == NULL){
        return;
    }
    
    if (q1Head->data > q2Head->data){
        // continue comparing
        Queue:: NodePointer q2NextHead = q2Head->next;
        q2Head->next = q1Head;
        this->myFront = q2Head;
        q2Head = q2NextHead;
    }
    
    q1Head = q1Head->next;
    
    while(q1Head != NULL){
        if (q1Head->data <= q2Head ->data){
            // adding q2Head to q1
            Queue:: NodePointer q1HeadNext = q1Head->next;
            q1Head->next = q2Head;
            q1Head = q1HeadNext;
            q2Head = q2Head->next;
        } else{
            Queue:: NodePointer q2NextHead = q2Head->next;
            q2Head->next = q1Head;
            q2Head = q2NextHead;
            q1Head = q1Head->next;
        }
    }
    q.myFront = NULL;
    q.myBack = NULL;
