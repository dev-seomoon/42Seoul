#!/bin/bash

mkdir -p /var/ftp/user

openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj "/C=KO/ST=Seoul/L=Gaepodong/O=42Seoul/CN=ft_services"	-keyout /etc/ssl/private/vsftpd.key -out /etc/ssl/certs/vsftpd.crt

adduser -D user -h /var/ftp/user
chown user:user /var/ftp/user
echo "user:password" | /usr/sbin/chpasswd

vsftpd /etc/vsftpd/vsftpd.conf
