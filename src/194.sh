#!/bin/bash

file=file.txt

c=$(head -1 $file|awk '{print NF}')
arr=($(sed 's= =\n=g' $file))
h=$((${#arr[@]} / c))

for (( i = 0; i < c; i++ )); do
    echo -n ${arr[i]}
    for (( j = 1; j < h; j++ )); do
        echo -n " ${arr[j * c + i]}"
    done
    echo
done
