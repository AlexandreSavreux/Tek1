#!/bin/sh

cut -d: -f 5 | cut -d ' ' -f 2 | grep -e ^$1 | wc -l
