FROM alpine:3.12.0

RUN apk update && apk add influxdb \
		--repository http://dl-2.alpinelinux.org/alpine/edge/community/

RUN mkdir -p /etc/influxdb
RUN mkdir -p /var/lib/influxdb
COPY influxdb.conf /etc/influxdb/influxdb.conf

EXPOSE 8086

COPY ./influxdb_setup.sh  /

ENTRYPOINT sh influxdb_setup.sh
