#!/bin/bash

saveIFS="$IFS"

error=0

for line in `cat .list`
do
    if [ -f "../$line" ]
    then
	echo -e "../$line : \033[32mOK\033[0m"
    else  
	echo -e "../$line : \033[31mMISSING\033[0m"
	wget -O "../$line" "http://toutchaud.cloud4you.fr/DL/$line"
	sleep 20
	if [ $? -eq 0 ]
	then
	   echo -e "../$line : \033[33mDowloading ...\033[0m"
	else   
	    echo -e "../$line : \033[31mNO INTERNET\033[0m"
	    let "error++"
	fi
    fi
done

if [ $error -ne 0 ]
then
    echo -e "\033[31mYou don't have all files needed to launch the game, try to correct your internet connection and retry\033[0m"
else
    cd .. && ./my_rpg
fi

IFS="$savIFS"
