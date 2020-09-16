#!/bin/bash
for i in {1..20}
do
	LASTNUMBER=`tail -1 file.txt`
	NEXTNUMBER=`expr 1 + $LASTNUMBER`
	echo $NEXTNUMBER >> file.txt
done
