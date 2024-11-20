#!/bin/sh

#virtual processors
cat /proc/cpuinfo | grep '^processor' | wc -l

# physical processors
cat /proc/cpuinfo | grep 'physical id' | sort -u | wc -l

# date of last reboot
last reboot | head -1

# for OS and kernel version
uname -a

# display number of active connections
ip link show

# display users of server
who -H -u

# list number of sudo usage
sudo grep sudo /var/log/auth.log

# The current available storage and its utilization rate as a percentage
df -BM -i

