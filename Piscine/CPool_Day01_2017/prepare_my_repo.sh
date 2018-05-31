#!/bin/sh
 

nom=$1

blih -u florian.louvet@epitech.eu repository create $1



blih -u florian.louvet@epitech.eu repository setacl $nom ramassage-tek r



blih -u florian.louvet@epitech.eu repository getacl $nom



