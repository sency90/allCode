#!/bin/bash
g++ solution_zych.cpp -O2 -std=c++11 -o solution
for data in './*'; do
    for splited in $data; do
        if [[ "$splited" == *".in" ]]; then
            ./solution < ${splited} > output.txt
            diff12=$(diff output.txt ${splited%.in}".out");
            if [ "$diff12" ]; then
                echo "conflict: $splited";
            fi
        fi
    done
done

rm -rf solution
rm -rf output.txt
