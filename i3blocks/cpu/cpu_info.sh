#!/bin/sh
TEMP=$(sensors | grep 'Package id 0:\|Tdie' | grep ':[ ]*+[0-9]*.[0-9]*°C' -o | grep '+[0-9]*.[0-9]*°C' -o)
CPU_USAGE=$(cpupower frequency-info | grep "asserted by call" | awk {'print $4'})'Ghz'
echo "$CPU_USAGE $TEMP" | awk '{ printf(" CPU:%6s @ %s \n"), $1, $2 }'
