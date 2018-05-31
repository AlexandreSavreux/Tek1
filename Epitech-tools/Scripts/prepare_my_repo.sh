#!/bin/sh

read -p "Entrez un nom pour le Repository : " nom

while [ -z '$nom' ]

do
    read -p "Entrez un nom pour le Repository : " nom
done

PROJECT_FOLDER="/home/user/Project"
ADRESS="prenom.nom@epitech.eu"
PASSWORD="MDP blih"
SEND_PASS="`echo -n "$PASSWORD" | sha512sum | cut -f1 -d' '`"

blih -u "$ADRESS" -t $SEND_PASS repository create $nom




blih -u "$ADRESS" -t $SEND_PASS repository setacl $nom ramassage-tek r



blih -u "$ADRESS" -t $SEND_PASS repository getacl $nom


cd "$PROJECT_FOLDER" && exec  git clone git@git.epitech.eu:/"$ADRESS"/"$nom"
