/* test1.c --- file to test implementation of queue interface
 * 
 * 
 * Author: Chikezie Onungwa
 * Created: Sat Oct 10 17:52:18 2020 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"

int main(void) {
	/*test qopen */
	printf("Testing qopen()...\n");
	queue_t* q1 = qopen();
	if(q1 == NULL) {
		printf("Test failed! qopen returned a NULL queue.\n");
		exit(EXIT_FAILURE);
	}

	// put two persons on queue
	printf("Testing qput...\n");
	person_t *p1 = make_person("Lerty", 42, 6.13);
	int32_t put_p1 = qput(q1, p1);
	if(put_p1 != 0){
		printf("Test failed! error putting to queue.\n");
		exit(EXIT_FAILURE);
	}

	person_t *p2 = make_person("Telitm", 36, 4.02);
	int32_t put_p2 = qput(q1, p2);
	if(put_p2 != 0){
		printf("Test failed! error putting to queue.\n");
		exit(EXIT_FAILURE);
	}


	// get back persons and confirm their returned in right order
	person_t *pp = (person_t*) qget(q1);
	if(pp != p1) {
		printf("Test failed! qget did not return correct object.\n");
		exit(EXIT_FAILURE);
	}

	pp = (person_t*) qget(q1);
	if(pp != p2) {
		printf("Test failed! qget did not return correct object.\n");
		exit(EXIT_FAILURE);
	}
	
	// get from now empty queue. should return NULL
	pp = (person_t*) qget(q1);
	if(pp != NULL) {
		printf("Test failed! did not return NULL from empty queue.\n");
		exit(EXIT_FAILURE);
	}

	// put back person
	put_p1 = qput(q1, p1);

	// create another queue
	queue_t* q2 = qopen();
	if(q2 == NULL) {
		printf("Test failed! qopen returned a NULL queue.\n");
		exit(EXIT_FAILURE);
	}

	// put person2 in queue2
	int32_t put_p2_q2 = qput(q2, p2);
	if(put_p2 != 0){
		printf("Test failed! error putting to queue.\n");
		exit(EXIT_FAILURE);
	}

	// get back person2 and confirm it's in right queue
	pp = (person_t*) qget(q2);
	if(pp != p2) {
		printf("Test failed! qget did not return correct object from queue 2.\n");
		exit(EXIT_FAILURE);
	}

	// check that queue 1 is intact
	pp = (person_t*) qget(q1);
	if(pp != p1) {
		printf("Test failed! qget did not return correct object from queue 2.\n");
		exit(EXIT_FAILURE);
	}

	// get from now empty queue2. should return NULL
	pp = (person_t*) qget(q2);
	if(pp != NULL) {
		printf("Test failed! did not return NULL from empty queue.\n");
		exit(EXIT_FAILURE);
	}

	// check that queue pointer is NULL after deallocating
	qclose(q1);
	if(q1 != NULL) {
		printf("Test failed! deallocated queue 1 is not NULL.\n");
		exit(EXIT_FAILURE);
	}

	qclose(q2);
	if(q2 != NULL) {
		printf("Test failed! deallocated queue 2 is not NULL.\n");
		exit(EXIT_FAILURE);
	}

	printf("Tests passed! qopen, qclose, qput, and qget were tested\n");
	exit(EXIT_SUCCESS);
	
}

