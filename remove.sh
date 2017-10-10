#!/bin/bash -e
set -x

range=$(grep BOOTFB /proc/iomem | awk '{ print $1 }')
IFS='-' read -ra ADDR <<< "$range"

start=${ADDR[0]}
end=${ADDR[1]}

sleep 2

insmod build/force-remove-bootfb.ko bootfb_start=0x${start} bootfb_end=0x${end}
rmmod force-remove-bootfb
