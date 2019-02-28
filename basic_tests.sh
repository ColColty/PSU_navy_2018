#!/bin/bash

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

EXEC=$1
COUNTER=0

if [ $1 = "unit_tests" ]; then
    test_arguments "--always-succeed"
    exit
else
    make re
fi

test_arguments
test_arguments 1 2
test_arguments 2
test_arguments "" ""
test_arguments -h
test_arguments 1 2 3 4
test_arguments testing pos2
test_arguments pos1
test_arguments 1234 pos2
test_arguments pos1 | test_arguments `pgrep -fn basic_tests.sh` pos2
test_arguments data
