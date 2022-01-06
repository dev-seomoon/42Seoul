FROM alpine:3.12.0

RUN apk update && apk add bash vsftpd openssl

COPY vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY run-vsftpd.sh /

EXPOSE 20 21 20000-20004
ENTRYPOINT sh run-vsftpd.sh
