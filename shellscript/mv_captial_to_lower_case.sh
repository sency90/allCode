#!/bin/bash
for i in `ls`; do
    mv $i `echo $i|tr '[A-Z]' '[a-z]'`;
done
