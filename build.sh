#!/bin/bash
function get_files() {
    for file in `ls $1`;
    do
        if [ -d $1/$file ]; then
            get_files "$1/$file"
        else
            if [ -d $1 ]; then
                echo $1/$file
            else
                echo $file
            fi
        fi
    done
}

function build() {
    dir=`dirname $1`
    filename=`basename $1`
    if [[ $filename != "Makefile" ]]; then
        return
    fi

    pushd $dir
    echo "build in $dir"
    make
    if [[ $? != 0 ]]; then
        echo "build error in '$dir'"
        popd
        exit 1
    fi
    popd
}

list='.'
[ -n "$*" ] && list=$*

files=""
for e in $list
do
    files="$files `get_files $e`"
done


for file in $files;
do
    #echo $file
    build $file
done
