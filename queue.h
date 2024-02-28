#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>

/* Structure for a queue node */
typedef struct queue_node
{
    void *ptr;
    struct queue_node *next;
} queue_node_t;

/* Structure for a queue */
typedef struct queue
{
    queue_node_t *front;
    queue_node_t *rear;
} queue_t;

/* Function prototypes */
queue_t *queue_push(queue_t *queue, void *ptr);
queue_t *queue_pop(queue_t *queue);
void *queue_front(const queue_t *queue);
int queue_empty(const queue_t *queue);
void queue_free(queue_t *queue);

#endif /* QUEUE_H */
