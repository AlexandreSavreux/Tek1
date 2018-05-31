#!/bin/sh

read -p "Entrez un commentaire : " commit_message

while [ -z "$commit_message" ]
do

	read -p "Entrez un message : " commit_message

done

	git add -A

	git commit -m "$commit_message"

	git push



