#!/bin/bash
for file in *.cpp; do
    mv "$file" "`basename "$file" .cpp`.c"
done
