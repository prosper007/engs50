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
		printf("Test failed. qopen returned a NULL queue.\n");
		exit(EXIT_FAILURE);
	}

	printf("Testing qput...\n");
	person_t *p1 = make_person("Tyler", 22, 6.13);
	int32_t put_p1 = qput(q1, p1);
	if(put_p1 != 0){
		printf("Test failed. error putting to queue.\n");
		exit(EXIT_FAILURE);
	}

	
	
 
	
}

