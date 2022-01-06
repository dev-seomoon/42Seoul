FROM alpine:3.12.0

RUN apk update

RUN apk add nginx php7 php7-fpm php7-mbstring php7-session \
	php7-json php7-gd php7-curl php7-mysqli 

RUN wget https://files.phpmyadmin.net/phpMyAdmin/4.9.5/phpMyAdmin-4.9.5-all-languages.tar.gz \
	&& tar -xvf /phpMyAdmin-4.9.5-all-languages.tar.gz \
	&& rm -f /phpMyAdmin-4.9.5-all-languages.tar.gz \
	&& mv /phpMyAdmin-4.9.5-all-languages /var/www/phpmyadmin \
	&& rm -rf /var/cache/apk/*

COPY default.conf /etc/nginx/conf.d/
COPY config.inc.php /var/www/phpmyadmin/config.inc.php
RUN chmod 705 /var/www/phpmyadmin/config.inc.php
RUN mkdir -p /run/nginx
							
EXPOSE 5000

ENTRYPOINT php-fpm7 && nginx -g "daemon off;"
