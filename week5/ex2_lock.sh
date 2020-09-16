#!/bin/bash
for i in {1..20}
do
	if ln file_lock.txt file.lock
	then
		LASTNUMBER=`tail -1 file_lock.txt`
		NEXTNUMBER=`expr 1 + $LASTNUMBER`

		echo $NEXTNUMBER >> file_lock.txt
		rm file.lock
	fi
done

