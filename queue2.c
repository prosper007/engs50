/*
* queue2.c -- implement last four functions of interface in queue.h
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "queue.h"
#include "bool.h"

//define front queue interface
static queue_t* *queue_interface=NULL;

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

/* apply a function to every element of the queue */
void qapply(queue_t *qp, void (*fn)(void *elementp)) {
	//how to specify the queue in the loop?
	queue_t *q;
	void *element;
	if (find_q(qp) 
	for(element=queue_front; element!=NULL; element=element->next) {
		fn(element);
	}
}

/* search a queue using a supplied boolean function
 * skeyp -- a key to search for
 * searchfn -- a function applied to every element of the queue
 *          -- elementp - a pointer to an element
 *          -- keyp - the key being searched for (i.e. will be 
 *             set to skey at each step of the search
 *          -- returns TRUE or FALSE as defined in bool.h
 * returns a pointer to an element, or NULL if not found
 */
void* qsearch(queue_t *qp, bool (*searchfn)(void* elementp,const void* keyp), const void* skeyp) {
	
	//again, how to specify queue in the loop?
	queue_t *q;
	void *element;
	
	for(element=front; element!=NULL; element=element->next) {
		const void* key;
		const void* skey;
		key = skey;
		if (searchfn(element, key)!=TRUE) {
			return NULL;
		}
		else {
			return (void*)*element;
		}
	}
}

/* search a queue using a supplied boolean function (as in qsearch),
 * removes the element from the queue and returns a pointer to it or
 * NULL if not found
 */
void* qremove(queue_t *qp, bool (*searchfn)(void* elementp,const void* keyp), const void* skeyp) {
	
	//again, how to specify queue in the loop?
	queue_t *q;
	void *element;
	void *elementf = NULL;
	
	for(element=front; element!=NULL; element=element->next) {
		const void* key;
		const void* skey;
		key = skey;
		if (searchfn(element, key)!=TRUE) {
			return NULL;
		}
		else {
			if(elementf==NULL) {
				//convert to appropriate data type instead of void*?
				return (void*)qget(q);
			}
			elementf->next=element->next;
			return *element;
		}
		elementf=element;
	}
}

/* concatenates elements of q2 into q1
 * q2 is dealocated, closed, and unusable upon completion 
 */
void qconcat(queue_t *q1p, queue_t *q2p) {
	queue_t *q1;
	queue_t *q2;
	//how to specify that element2 is in q2?
	void *element2;
	for(element2=front; element2!=NULL; element2=element2->next) {
		//convert to appropriate data type instead of void*?
		qput(q1, (void*)element2);
	}
	qclose(q2);
}