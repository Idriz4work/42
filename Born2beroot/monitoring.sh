#!/bin/bash

# Collecting system information
ARCH=$(uname -a)
CPU_PHYSICAL=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)
VCPU=$(grep -c "processor" /proc/cpuinfo)
MEMORY=$(free -m | awk 'NR==2 {printf "%s/%sMB (%.2f%%)", $3, $2, $3/$2 * 100}')
DISK=$(df -h --total | grep total | awk '{printf "%s/%s (%s)", $3, $2, $5}')
CPU_LOAD=$(top -bn1 | grep "Cpu(s)" | awk '{printf "%.1f%%", $2 + $4}')
LAST_BOOT=$(who -b | awk '{print $3 " " $4}')
LVM=$(lsblk | grep -q "lvm" && echo "yes" || echo "no")
TCP_CONN=$(netstat -an | grep ESTABLISHED | wc -l)
USER_COUNT=$(who | wc -l)
IPV4=$(ip a | grep "inet " | grep -v "127.0.0.1" | awk '{print $2}')
MAC=$(ip link show | grep "link/ether" | awk '{print $2}')
SUDO_CMDS=$(grep -c "COMMAND" /var/log/sudo.log)

# Displaying the information using wall
wall <<EOF
#Architecture: $ARCH
#CPU physical: $CPU_PHYSICAL
#vCPU: $VCPU
#Memory Usage: $MEMORY
#Disk Usage: $DISK
#CPU load: $CPU_LOAD
#Last boot: $LAST_BOOT
#LVM use: $LVM
#Connections TCP: $TCP_CONN ESTABLISHED
#User log: $USER_COUNT
#Network: IP $IPV4 ($MAC)
#Sudo: $SUDO_CMDS cmd
EOF
