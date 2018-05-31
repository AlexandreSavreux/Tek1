#!/bin/sh

find -type f \( -name "*#*" -delete -o -name "*~" -delete -o -name "*.out" -delete -o -name "*.gcno" -delete -o -name "*.gcda" -delete -o -name "*.o" -delete \)
