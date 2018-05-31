#!/bin/sh

if [ -z $MY_LINE1 ]

then

	export MY_LINE1=24
	export MY_LINE2=42

fi

sed -n 1~2p | cut -d: -f 1 | rev | sort -r | sed -n "$MY_LINE1","$MY_LINE2"p | tr '\n' ',' | sed 's/,/, /gi'|sed  's/z_azhral_ante,/z_azhral_ante./g'

