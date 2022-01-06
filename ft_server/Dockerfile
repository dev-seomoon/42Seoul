FROM	debian:buster

RUN	apt-get update && apt-get -y upgrade && apt-get -y install \
	nginx curl \
	openssl \
	php-fpm \
	mariadb-server php-mysql php-mbstring \
	wget vim

COPY	./srcs/run.sh ./
COPY	./srcs/default ./tmp
COPY	./srcs/wp-config.php ./tmp
COPY	./srcs/config.inc.php ./tmp

EXPOSE	80 443

CMD	sh run.sh
