FROM alpine:3.12.0

RUN apk update && apk add mysql mysql-client

COPY ./mysql_setup.sh /
COPY my.cnf /etc/my.cnf
RUN chmod 644 /etc/my.cnf

EXPOSE 3306

ENTRYPOINT sh mysql_setup.sh
