#!/bin/sh

if [ -z $1 ]


then

	wc -l

else

	tr [A-Z] [a-z] | cut -d ";" -f 3 |grep $1 | wc -l

fi
