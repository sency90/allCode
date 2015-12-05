#!/bin/bash

`gcc -o broker ./broker.cpp ./rw_vn.cpp ./topic.cpp`
`gcc -o publisher ./publisher.cpp ./rw_vn.cpp ./topic.cpp`
`gcc -o subscriber ./subscriber.cpp ./rw_vn.cpp ./topic.cpp`
echo "broker, publisher, subscriber has been compiled completely."

`gnome-terminal -x ./broker`
`gnome-terminal -x ./publisher 1`
`gnome-terminal -x ./publisher 2`
`gnome-terminal -x ./subscriber 1`
`gnome-terminal -x ./subscriber 2`

sleep 3
`gnome-terminal -x ./publisher 3`

sleep 2
`gnome-terminal -x ./subscriber 3`
#for ((i=1; i <= 2; i++)) ; do
#    echo "gnome-terminal"
#    `./publisher $i`
#done

