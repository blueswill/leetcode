#!/bin/bash

sed -e 's= =\n=g' words.txt|sed -e '/^$/d'|sort|uniq -c|awk '{print $2,$1}'|sort -r -n -k 2
