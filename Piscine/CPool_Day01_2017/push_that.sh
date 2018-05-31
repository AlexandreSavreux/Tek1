#!/bin/sh

commit_message=$1

while [ -z $commit_message ]
do

	read commit_message

done

	git add -A

	git commit -m "$commit_message"

	git push



