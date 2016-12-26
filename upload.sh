#!/bin/bash
if [ $1 == "1" ]
then
    git add -A
fi

if [ "$2" != "0" ]
then
    git commit -m "$2"
fi

if [ $3 == "1" ]
then
    git push origin master
fi
