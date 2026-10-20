#!/bin/bash

wpftp_username=$(grep wpftp_username /run/secrets/credentials | cut -d '=' -f2)
wpftp_pass=$(grep wpftp_pass /run/secrets/credentials | cut -d '=' -f2)

useradd -m $wpftp_username
usermod -aG www-data $wpftp_username
echo "$wpftp_username:$wpftp_pass" | chpasswd

mkdir -p /var/www/wordpress
usermod -d /var/www/wordpress $wpftp_username

conf_file=/etc/vsftpd.conf

#Make local users able to login to the FTP server
echo "local_enable=YES" >> $conf_file
#Enable FTP commands for editing, deleting, uploading, and downloading files
echo "write_enable=YES" >> $conf_file 
#Restrict local users to their home directory after login
echo "chroot_local_user=YES" >> $conf_file
#Allow chrooted local users to write to their root dir
echo "allow_writeable_chroot=YES" >> $conf_file
#Range of ports that will be open for file transmission 
echo "pasv_min_port=5020" >> $conf_file
echo "pasv_max_port=5030" >> $conf_file
#Configure the server to listen on all network interfaces
echo "listen_address=0.0.0.0" >> $conf_file

mkdir -p /var/run/vsftpd/empty

vsftpd $conf_file