#!/bin/bash

for ((X=1; X<=21; X++))
do
    echo "______Test $X _____"
    ./PA1_test.exe < ./main_test/input/input$X.txt > myOut$X.txt
    diff -b ./main_test/output/output$X.txt myOut$X.txt
    
done