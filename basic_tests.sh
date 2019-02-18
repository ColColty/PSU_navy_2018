#!/bin/sh

make

EXEC=$1
COUNTER=0

test_arguments()
{
    ./$EXEC $@
    RET=`echo $?`

    if [ $RET -ne 84 ] && [ $RET -ne 0 ]; then
        echo "Failed with code: $RET"
        exit $RET
    else
        COUNTER=$((COUNTER + 1))
        echo "Test $COUNTER passed with code: $RET"
    fi
}

test_arguments
test_arguments 1 2
test_arguments 2
test_arguments "" ""
test_arguments -h
