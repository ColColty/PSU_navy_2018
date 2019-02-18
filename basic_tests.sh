#!/bin/sh

make

EXEC=$1

test_arguments()
{
    ./$EXEC $@
    RET=`echo $?`

    if [ $RET -ne 84 ] || [ $RET -ne 0]; then
        echo "Failed with code: $RET"
        exit $RET
    fi
}

test_arguments
test_arguments 1 2
test_arguments 2
test_arguments "" ""
