#!/bin/bash

SRC_FILE=src.txt
SERVER_FILE=server.txt
txt="$(cat ten_thousand_chars.txt)"

echo ${txt} > $SRC_FILE

../server > $SERVER_FILE & 
(sleep 1 && ../client $(awk '{print $2}' $SERVER_FILE) "$(cat $SRC_FILE)")

diff $SRC_FILE $SERVER_FILE

rm $SRC_FILE $SERVER_FILE