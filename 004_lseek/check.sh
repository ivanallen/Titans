#!/bin/bash
let file_length=`stat --printf '%s' ../README.md`
let a=$(($file_length-$file_length/2))
let b=`stat --printf '%s' file`
echo $a
echo $b
exit $(($a-$b))
