//
//  type.c
//  360Prelab2
//
//  Created by Weiren Lai on 1/29/20.
//  Copyright © 2020 Weiren Lai. All rights reserved.
//
#include "type.h"

extern PROC *running;

int kexit(int value)
{
  running->exitCode = value;
  running->status = ZOMBIE;
  tswitch();
    return 0;
}

/********* Required PRE-work ***********/
// 1. Modify kfork() to implement process tree as a BINARY tree

// 2. Implement ksleep() per the algorithm in 3.4.1
int ksleep(int event)
{
    running->event=event;
    running->status=SLEEP;
    enqueue("sleepList", sleepList);
    tswitch();
    return 0;
}

// 2. Implement kwakeup per the algorithm in 3.4.2
int kwakeup(int event)
{
    PROC *temp, *p;
    temp = 0;
    printList("sleepList", sleepList);
    
    while(p = dequeue(&sleepList))
    {
        if(p->event ==event){
            printf("wakeup %d\n", p->pid);
            p->status = READY;
            enqueue(&readyQueue, p);
        }
        else{
            enqueue(&temp, p);
        }
    }
    sleepList = temp;
    printList("sleepList",sleepList);
    return 0;
}


int mexit(int value)
{
    PROC *cur;
    int wakeUp = 0;
    
    if(running->pid == 1){
        return -1;
    }
    
    for (int i = 1; i < NPROC; i++)
    {
        cur = &proc[i];
        
        if(cur -> status != FREE && cur->ppid == running ->pid)
        {
            cur->ppid = 1;
            cur->parent = &proc[1];
            wakeUp = 1;
        }
    }
    
    
    running -> exitCode = value;
    
    running -> status = ZOMBIE;
    
    wakeup ((int)(running->parent));
    
    if(wakeUp){
        wakeup((int)(&proc[1]));
    }
    tswitch();
    return 0;
}

// 3. Implement kwait() per the algorithm in 3.5.3
int kwait(int *status)
{
    int childexists = 0;
    PROC *cur;
    while(1)
    {
        for (int i = 1; i < NPROC; i++)
        {
            cur = &proc[i];
        }
        if(cur->ppid == running -> pid){
            if (cur -> status != FREE)
            {
                childexists =1;
            }
            if(cur -> status = ZOMBIE)
            {
                *status = cur -> exitCode;
                
                cur -> status = FREE;
                
                enqueue(&freeList, cur);
                
                return cur -> pid;
            }
        }
        if(!childexists){
            return -1;
        }
        ksleep((int)(running));
    }
}

// 4. Add a "wait" command to let proc wait for ZOMBIE child

int wait(int *status)
{
    int childexists = 0;
    PROC *p;
    
    while(1)
    {
        for(int i = 1; i <NPROC; i++)
        {
            p = & proc[i];
            if (p -> ppid == running -> pid)
            {
                if(p -> status != FREE)
                {
                    childexists = 1;
                }
                if(p -> status == ZOMBIE)
                {
                    *status = p -> exitCode;
                    
                    p -> status = FREE;
                    
                    enqueue(&freeList, p);
                    
                    return p -> pid;
                }
            }
        }
        if(!childexists){
            return -1;
        }
        ksleep((int)(running));
    }
}
