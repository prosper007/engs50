#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

/* a struct to represent a single node of a queue */
typedef static struct qnode_t {
  void* elementp;
  struct qnode_t *next;
}

/* the queue representation is hidden from users of the module */
typedef struct queue_t {
  qnode_t *front;
  qnode_t *back;
  queue_t *queue_next;
}

static queue_t* queue_interface=NULL;

//define function to find a specific queue in an interface of queues
queue_t* find_q(queue_t *qp) {
  queue_t *qfind;
  for (qfind=queue_interface; qfind!= NULL; qfind=queue_interface->next_queue_t) {
    if(qfind==qp) {
      return *qfind;
    }
    else {
      printf("Queue not found in interface\n");
      return NULL;
    }
  }
}

/* A function that creates a new queue node and allocates memory for it */
static qnode_t* new_qnode(elementp element) {
  qnode_t *new_node;
  new_node = (qnode_t*)malloc(sizeof(qnode_t));
  new_node->elementp = element;
  new_node->next = NULL;
  return new_node;
}

/* create an empty queue */
queue_t* qopen(void) {
  queue_t* queue = (queue_t*)malloc(sizeof(queue_t)); // assign memory for queue
  queue->front = queue->back = NULL; // set front and back to NULL
  return queue;
}

/* deallocate a queue, frees everything in it */
void qclose(queue_t *qp) {
  while (qp->front != NULL) { // checks if qp is empty 
    qnode_t* temp = qp->front; // store initial value of front
    qp->front = qp->front->next; // move front to next node
    free(temp); // free the node
  }
  qp->front = qp->back = NULL; // just for safety reset front and back to NULL 
  free(qp); //free the queue
  qp=NULL;
}

/* Function to put an element at the back of the queue */
int32_t qput(queue_t *qp, void *elementp) {
  if (elementp == NULL) {
    return 1; // if element youre trying to add is NULL exit non-zero
  }
  qnode_t node = new_qnode(elementp);
  if (qp->front == NULL) {        // if queue is empty set both front and back to new node
    qp->front = qp->back = node;
  } else {
    qp->back->next = node;   // adding new element to a non-empty queue
    qp->back = node;
  }
  return 0;
}


void* qget(queue_t *qp) {
  if (qp->front == NULL) {
    return NULL;
  }
  qnode_t* temp = qp->front;
  qp->front = qp->front->next;
  if (qp->front == NULL) {
    qp->back == NULL;
  }
  free(temp);
}
