//
//  queue.c
//  360Prelab2
//
//  Created by Weiren Lai on 1/29/20.
//  Copyright © 2020 Weiren Lai. All rights reserved.
//
#include "type.h"

/****************** queue.c file ********************/
int enqueue(PROC **queue, PROC *p)
{
    PROC *q = *queue;
    if (q == 0 || p->priority > q->priority){
       *queue = p;
        p->next = q;
    }
    else{
       while (q->next && p->priority <= q->next->priority)
          q = q->next;
       p->next = q->next;
       q->next = p;
   }
    return 0;
}

// remove and return first PROC in queue
PROC *dequeue(PROC **queue)
{
     PROC *p = *queue;
     if (p)
        *queue = (*queue)->next;
     return p;
}

int printList(char *name, PROC *p)
{
   printf("%s = ", name);
   while(p){
     printf("[%d %d]->", p->pid, p->priority);
       p = p->next;
   }
   printf("NULL\n");
    return 0;
}
