#!/bin/bash

#compile
`gcc -o broker ./broker.cpp ./rw_vn.cpp ./topic.cpp`
`gcc -o publisher ./publisher.cpp ./rw_vn.cpp ./topic.cpp`
`gcc -o subscriber ./subscriber.cpp ./rw_vn.cpp ./topic.cpp`
echo "broker, publisher, subscriber has been compiled completely."

#문제 < e-i >
#broker를 실행한다.
`gnome-terminal -x ./broker`

#문제 < e-ii >
#2개의 publisher와 2개의 subscriber를 실행하여 broker에 접속한다.
`gnome-terminal -x ./publisher 1`
`gnome-terminal -x ./publisher 2`
`gnome-terminal -x ./subscriber 1`
`gnome-terminal -x ./subscriber 2`

#문제 < e-iii >
#3초 후 새로운 publisher를 실행시켜 broker에 접속한다.
sleep 3
`gnome-terminal -x ./publisher 3`

#문제 < e-iv >
#2초 후 새로운 subscriber를 실행시켜 broker에 접속한다.
sleep 2
`gnome-terminal -x ./subscriber 3`
