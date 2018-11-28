#!/bin/bash



context="#include <stdio.h>"
context1="#include <stdlib.h>"
context2="int main()"
context3="{"
context4="   return 1;"
context5="}"
for ((a=2004;a<2019;a++))
do
    touch $a.c
    echo $context >> $a.c
    echo $context1 >> $a.c
    echo $context2 >> $a.c
    echo $context3 >> $a.c
    echo $context4 >> $a.c
    echo $context5 >> $a.c
done
