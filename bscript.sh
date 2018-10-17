#!/bin/bash
for end in $@
do 
	true
done
echo $end
for input in $@
do
	if [ -e $input ]
	then
		echo "$input is there"
	else
		echo "file not found $input"
		exit
	fi
done
if [ -d keys ]
	then
		echo "passing to keys/"
	else
		mkdir keys
		echo "passing to keys/"
	fi

for input in $@
do
	mv $input keys/
done
cd keys/
for input in $@
do
	if [ $input != $end ]
	then
	 	cat $input >> $end
	fi
done
