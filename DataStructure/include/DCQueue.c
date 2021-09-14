//
// Created by 15066 on 2021/9/12.
//
#ifndef MALLOC_H
#define MALLOC_H

#include<malloc.h>

#endif
////////////////////////////////
#include "DCQueue.h"

DCQueue DCQueue_New() {
    DCQueue queue = (DCQueue_ *) malloc(sizeof(DCQueue_));
    if (queue == NULL) {
        return NULL;
    }
    queue->Position = NULL;
    return queue;
}

DCQueueNode_ *DCQueue_NewNode(void *object) {
    DCQueueNode_ *node = (DCQueueNode_ *) malloc(sizeof(DCQueueNode_));
    if (node == NULL) {
        return NULL;
    }
    node->Object = object;
    return node;
}

bool DCQueue_PushToLast(DCQueue queue, void *object) {
    if (queue->Position == NULL) {
        queue->Position = DCQueue_NewNode(object);
        if (queue->Position == NULL) {
            return false;
        }
        queue->Position->Last = queue->Position;
        queue->Position->Next = queue->Position;
        return true;
    }
    DCQueueNode_ *node = DCQueue_NewNode(object);
    if (node == NULL) {
        return false;
    }
    node->Last = queue->Position->Last;
    node->Next = queue->Position;
    queue->Position->Last->Next = node;
    queue->Position->Last = node;
    return true;
}

bool DCQueue_PushToNext(DCQueue queue, void *object) {
    if (queue->Position == NULL) {
        queue->Position = DCQueue_NewNode(object);
        if (queue->Position == NULL) {
            return false;
        }
        queue->Position->Last = queue->Position;
        queue->Position->Next = queue->Position;
        return true;
    }
    DCQueueNode_ *node = DCQueue_NewNode(object);
    if (node == NULL) {
        return false;
    }
    node->Next = queue->Position->Next;
    node->Last = queue->Position;
    queue->Position->Next->Last = node;
    queue->Position->Next = node;
    return true;
}
void *DCQueue_PopToLast(DCQueue queue){
    if (queue->Position == NULL) {
        return NULL;
    }
    void *object;
    if(queue->Position->Next == queue->Position){
        object = queue->Position->Object;
        free(queue->Position);
        queue->Position = NULL;
        return object;
    }
    DCQueueNode_ *temp = queue->Position;

    object = queue->Position->Object;
    queue->Position->Next->Last = queue->Position->Last;
    queue->Position->Last->Next = queue->Position->Next;
    queue->Position = queue->Position->Last;
    free(temp);
    return object;
}
void *DCQueue_PopToNext(DCQueue queue){
    if (queue->Position == NULL) {
        return NULL;
    }
    void *object;
    if(queue->Position->Next == queue->Position){
        object = queue->Position->Object;
        free(queue->Position);
        queue->Position = NULL;
        return object;
    }
    DCQueueNode_ *temp = queue->Position;
    object = queue->Position->Object;
    queue->Position->Next->Last = queue->Position->Last;
    queue->Position->Last->Next = queue->Position->Next;
    queue->Position = queue->Position->Next;
    free(temp);
    return object;
}
void DCQueue_Destroy(DCQueue queue) {
    if (queue->Position == NULL) {
        return;
    }
    DCQueueNode_ *temp = queue->Position, *last;
    do {
        last = temp;
        temp = temp->Next;
        free(last);
    } while (temp != queue->Position);
    free(queue);
}
void DCQueue_MoveToLast(DCQueue queue){
    queue->Position = queue->Position->Last;
}

void DCQueue_MoveToNext(DCQueue queue){
    queue->Position = queue->Position->Next;
}