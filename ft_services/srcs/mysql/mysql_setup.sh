#!/bin/sh

mkdir -p /run/mysqld

mysql_install_db --user=root

echo "CREATE DATABASE IF NOT EXISTS wordpress;
        FLUSH PRIVILEGES;
        GRANT ALL PRIVILEGES ON *.* TO 'user'@'%' IDENTIFIED BY 'password' WITH GRANT OPTION;
        FLUSH PRIVILEGES;" > scripts.sql
mysqld -u root --bootstrap < scripts.sql

mysqld -u root
