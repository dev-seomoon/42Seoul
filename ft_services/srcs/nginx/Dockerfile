FROM alpine:3.12.0

RUN apk update && apk add nginx openssl openssh

COPY ./nginx_setup.sh /
COPY ./default.conf /etc/nginx/conf.d/

EXPOSE 80 443 22

ENTRYPOINT sh nginx_setup.sh
