#!/bin/bash -e


if [ "$#" -ne 3 ];
  then echo "Incorrect number of command line args"
fi

input_data= $3
if [ -s input_data];
  echo "empty file!!"
  then exit 1
fi






exit 0 #exit with no errors
