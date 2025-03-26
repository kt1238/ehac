#! /bin/bash

for n in {1..10};
do
    touch file$n
    chmod 444 file$n
done
