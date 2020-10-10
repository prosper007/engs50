#!/bin/bash

# A simple Shell Script that applies Valgrind to all test programs and
# ensurses that there are no memory leaks or errors

for f in test_*; do
    touch tmp.txt
    valgrind --leak-check=full ${f} >> tmp.txt
    LEAK=$(grep 'no leaks are possible' tmp.txt)
    ERR=$(grep '0 errors' tmp.txt)
    if [ ${LEAK} != 0 ] || [ ${ERR} != 0 ]; then
	echo "memory leak or error present in file ${f}"
    else
	echo "no leaks or errors present in file ${f}"
    fi
    rm tmp.txt
done

