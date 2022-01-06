FROM alpine:3.12.0

RUN apk update && apk add nginx php7 php7-fpm php7-mbstring \
	php7-session php7-json php7-gd php7-curl php7-mysqli

RUN wget https://wordpress.org/latest.tar.gz \
	&& tar -xvf latest.tar.gz \
	&& rm -f latest.tar.gz \
	&& mv wordpress/ /var/www/
RUN mkdir -p /run/nginx

COPY wp-config.php /var/www/wordpress/
COPY default.conf /etc/nginx/conf.d/

EXPOSE 5050

ENTRYPOINT php-fpm7 && nginx -g "daemon off;"
