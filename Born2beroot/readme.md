# Born2BeRoot Guide

A comprehensive guide for setting up and configuring a Debian virtual machine using VirtualBox.

## Table of Contents
- [Part 1 - Virtual Machine Setup](#part-1---virtual-machine-setup)
  - [Downloading Debian](#downloading-debian)
  - [VirtualBox Installation](#virtualbox-installation)
  - [Creating Virtual Machine](#creating-virtual-machine)
- [Part 2 - Debian Installation](#part-2---debian-installation)
  - [Basic Setup](#basic-setup)
  - [Disk Partitioning](#disk-partitioning)
  - [System Configuration](#system-configuration)
- [Part 3 - Initial Configuration](#part-3---initial-configuration)
  - [Installing Required Packages](#installing-required-packages)
  - [User Management](#user-management)
  - [SSH Configuration](#ssh-configuration)
  - [Firewall Setup](#firewall-setup)
- [Part 4 - Security Configuration](#part-4---security-configuration)
  - [Password Policy](#password-policy)
  - [Sudo Configuration](#sudo-configuration)
  - [User Groups](#user-groups)
- [Part 5 - Monitoring Setup](#part-5---monitoring-setup)
  - [Script Configuration](#script-configuration)
  - [Crontab Setup](#crontab-setup)
- [Part 6 - Project Submission](#part-6---project-submission)
  - [Creating Signature](#creating-signature)

## Part 1 - Virtual Machine Setup

### Downloading Debian
1. Visit [Debian ISO Downloads](https://cdimage.debian.org/debian-cd/current/amd64/iso-cd/)
2. Download `debian-xx.x.x-amd64-netinst.iso`

### VirtualBox Installation
1. Open Managed Software Center
2. Search for VirtualBox
3. Download and install

### Creating Virtual Machine
1. Open VirtualBox and click "New"
2. Configure basic settings:
   - Name: `your_username42`
   - Machine Folder: `sgoinfre/students/your_intra_login/`
   - Memory: 1024 MB
   - Hard disk: Create new, VDI, Dynamically allocated, 12GB

## Part 2 - Debian Installation

### Basic Setup
1. Start the virtual machine
2. Select "Install" at the boot menu
3. Configure basic settings:
   - Language: English
   - Location: Your current location
   - Keyboard: American English
4. Configure network:
   - Hostname: `username42`
   - Domain: Leave blank
5. Set up users:
   - Root password: Choose secure password
   - Create user account: `username` (without 42)
   - Set user password

### Disk Partitioning
1. Select "Guided - use entire disk and set up encrypted LVM"
2. Choose disk to partition
3. Select "Separate /home, /var, and /tmp partitions"
4. Configure LVM:
   - Set encryption passphrase
   - Use maximum volume size
   - Confirm partitioning

### System Configuration
1. Configure package manager:
   - Select country mirror
   - Choose `deb.debian.org`
   - Leave proxy blank
2. Software selection:
   - Deselect SSH server
   - Deselect standard system utilities
3. Install GRUB boot loader:
   - Install to `/dev/sda`
   - Complete installation

## Part 3 - Initial Configuration

### Installing Required Packages
```bash
su -
apt-get update -y
apt-get upgrade -y
apt install sudo
apt-get install git -y
apt install openssh-server
apt-get install ufw
```

### User Management
```bash
usermod -aG sudo your_username
sudo visudo  # Add: your_username ALL=(ALL) ALL
```

### SSH Configuration
1. Edit SSH config:
```bash
sudo vim /etc/ssh/sshd_config
# Change #Port22 to Port 4242
```
2. Restart SSH:
```bash
sudo service ssh restart
```

### Firewall Setup
```bash
sudo ufw enable
sudo ufw allow ssh
sudo ufw allow 4242
```

## Part 4 - Security Configuration

### Password Policy
1. Install password quality library:
```bash
sudo apt-get install libpam-pwquality
```

2. Configure password policy:
```bash
sudo vim /etc/pam.d/common-password
# Add: minlen=10 ucredit=-1 lcredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
```

3. Modify password aging:
```bash
sudo vim /etc/login.defs
# Set:
# PASS_MAX_DAYS 30
# PASS_MIN_DAYS 2
# PASS_WARN_AGE 7
```

### Sudo Configuration
1. Create sudo log directory:
```bash
sudo mkdir /var/log/sudo
sudo touch /var/log/sudo/sudo.log
```

2. Configure sudo rules:
```bash
sudo visudo
# Add:
Defaults        env_reset
Defaults        mail_badpass
Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/bin:/sbin:/bin"
Defaults        badpass_message="Password is wrong, please try again!"
Defaults        passwd_tries=3
Defaults        logfile="/var/log/sudo/sudo.log"
Defaults        log_input, log_output
Defaults        requiretty
```

### User Groups
```bash
sudo groupadd user42
sudo groupadd evaluating
sudo usermod -aG user42 your_username
sudo usermod -aG evaluating new_username
```

## Part 5 - Monitoring Setup

### Script Configuration
1. Create monitoring script:
```bash
sudo touch /usr/local/bin/monitoring.sh
sudo chmod 777 /usr/local/bin/monitoring.sh
```

2. Add script content (see full script in project documentation)

### Crontab Setup
```bash
sudo crontab -u root -e
# Add: */10 * * * * /usr/local/bin/monitoring.sh
```

## Part 6 - Project Submission

### Creating Signature
1. Shutdown virtual machine
2. Generate signature:
```bash
cd sgoinfre/students/<your_intra_username>/VirtualBox\ VMs
shasum VirtualBox.vdi > signature.txt
```
3. Submit signature.txt

## Important Notes
- Keep track of all passwords created during installation
- Use the same password for all requests unless specified otherwise
- Test SSH connection: `ssh username@127.0.0.1 -p 4242`
- Verify all security settings before submission
- Test monitoring script functionality
- Ensure all services are running after reboot
