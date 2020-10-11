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

/* create an empty queue */
queue_t* qopen(void) {
  queue_t* queue = (queue_t*)malloc(sizeof(queue_t));
  queue->front = queue->back = NULL;
  return queue;
}

/* deallocate a queue, frees everything in it */
void qclose(queue_t *qp) {
  
}

int32_t qput(queue_t *qp, void *elementp) {
  if (elementp == NULL) {
    return 1;
  }
  if ((front == NULL) && (back == NULL)) {
    front = elementp;
    back = elementp;
  } else {
    back->next = elementp;
    back = elementp;
  }
  return 0;
}

void* qget(queue_t *qp) {
  front = front->next;
}
