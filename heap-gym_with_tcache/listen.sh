#!/bin/bash

# Script to listen/serve your binary over network, to practice remote exploitation like in CTFs.

if [[ (-z "$1")  || ( -z "$2") ]]
then
echo "Usage: $0 [program] [port]"
exit
else
echo "Listening on $2"
fi

rm /tmp/f 2>/dev/null;mkfifo /tmp/f;cat /tmp/f|"$1" 2>&1|nc -lkp "$2" >/tmp/f
