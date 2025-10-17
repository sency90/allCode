#!/bin/bash
g++ solution_zych.cpp -std=c++11 -O2 -o solution_zych
for data in './*'; do
    for splited in $data; do
        if [[ "$splited" == *".in" ]]; then
            ./solution_zych < ${splited} > ${splited%.in}".out";
        fi
    done
done
