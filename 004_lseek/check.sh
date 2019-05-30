#!/bin/bash
platform="$(uname)"

if [[ "$platform" == "Linux" ]]; then
    let file_length=`stat --printf '%s' ../README.md`
    let a=$(($file_length-$file_length/2))
    let b=`stat --printf '%s' file`
    echo $a
    echo $b
    exit $(($a-$b))
elif [[ "$platform" == "Darwin" ]]; then
    let file_length=`stat -f '%z' ../README.md`
    let a=$(($file_length-$file_length/2))
    let b=`stat -f '%z' file`
    echo $a
    echo $b
    exit $(($a-$b))
else
    echo "Unsupport" $platform
    exit 1
fi
