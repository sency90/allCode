import sys
import serial
import MySQLdb
from time import localtime, strftime

pBoxSerial = serial.Serial('/dev/tty.usbserial-DAY077QX',9600)

while True:
    db = MySQLdb.connect(host='127.0.0.1', user='the565656', passwd='dksemfhdlem88', db='the565656')
    with db:
        #ts = strftime("%Y-%m-%d %H:%M:%S", localtime())
        cur = db.cursor()
        pBoxId = pBoxSerial.readline()
        pBoxId = pBoxId[:-1]
        if pBoxId:
            print(pBoxId)
            #cur.execute("SELECT * FROM postbox WHERE pboxid = %d", pBoxId)
            #rows = cur.fetchall()
            #if len(rows) > 0:
            #    continue

            cur.execute("update postbox set count=count+1 where postbox_id=%s", pBoxId)
            #cur.execute("INSERT INTO pbox(pboxid, timestamp) VALUES (%s, %s)", (pBoxId, ts))
            db.commit()
            pBoxId="0"
