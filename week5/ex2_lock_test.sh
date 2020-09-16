#!/bin/bash
echo 0 > file_lock.txt
./ex2_lock.sh &
./ex2_lock.sh
