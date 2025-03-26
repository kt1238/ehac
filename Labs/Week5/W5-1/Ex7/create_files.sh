#!/bin/bash

for i in {1..3}
do
    touch file$i
    chmod 444 file$i
done

for i in {4..5}
do
    touch file$i
    chmod 777 file$i
done
