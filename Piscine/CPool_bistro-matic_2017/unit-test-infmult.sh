#!/bin/sh
echo "1*1 = 1"
./a.out 1 1
echo ' '

echo "11*1 = 11"
./a.out 11 1
echo ' '

echo "11*11 = 121"
./a.out 11 11
echo ' '

echo "1*-1 = -1"
./a.out 1 -1
echo ' '

echo "11*-1 = -11"
./a.out 11 -1
echo ' '

echo "11*-11 = -121"
./a.out 11 -11
echo ' '

echo "-1*-1 = 1"
./a.out -1 -1
echo ' '

echo "-11*-1 = 11"
./a.out -11 -1
echo ' '

echo "-11*-11 = 121"
./a.out -11 -11
echo ' '
