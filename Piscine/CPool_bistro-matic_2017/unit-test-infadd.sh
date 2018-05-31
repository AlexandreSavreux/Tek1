#!/bin/sh
echo "1+1 = 2"
./a.out 1 1
echo ' '

echo "11+1 = 12"
./a.out 11 1
echo ' '

echo "11+11 = 22"
./a.out 11 11
echo ' '

echo "11 - 11 = 0"
./a.out 11 -11
echo ' '

echo "50-11 = 39"
./a.out 50 -11
echo ' '

echo "50-4 = 46"
./a.out 50 -4
echo ' '

echo "-54-14 = -68"
./a.out -54 -14
echo ' '

echo "-54-1 = -55"
./a.out -54 -1
echo ' '

echo "4-6 = -2"
./a.out 4 -6
echo ' '

echo "-6+4 = -2"
./a.out -6 4
echo ' '

echo "-25+5 = -20"
./a.out -25 5
echo ' '

echo "-25+20 = -5"
./a.out -25 20
echo ' '
