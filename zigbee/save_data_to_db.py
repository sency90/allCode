import sys
import serial
import MySQLdb
from time import localtime, strftime

pBoxSerial = serial.Serial('/dev/tty.usbserial-DAY077QX',9600)

while True:
    db = MySQLdb.connect(host='183.111.174.123', user='the565656', passwd='dksemfhdlem88', db='the565656')
    with db:
        cur = db.cursor()
        pBoxId = pBoxSerial.readline()
        pBoxId = pBoxId[:-1]
        if pBoxId:
            print(pBoxId)
            cur.execute("update postbox set count=count+1 where postbox_id=%s", pBoxId)
            db.commit()
            pBoxId="0"
