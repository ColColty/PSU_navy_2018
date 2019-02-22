#!/bin/sh

make re

EXEC=$1
COUNTER=0

test_arguments()
{
    echo "timeout 2 ./$EXEC $@"
    timeout 2 ./$EXEC $@
    RET=`echo $?`

    if [ $RET -eq 124 ]; then
        echo "This is a timeout of 2secs for test $COUNTER"
    elif [ $RET -ne 84 ] && [ $RET -ne 0 ]; then
        echo "Test $COUNTER failed with code: $RET"
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
