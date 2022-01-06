FROM alpine:3.12

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.15.3_static_linux_amd64.tar.gz \
	&& tar -C . -xzf telegraf-1.15.3_static_linux_amd64.tar.gz \
	&& cp -r telegraf-1.15.3/* / 

COPY ./telegraf_setup.sh /

ENTRYPOINT sh telegraf_setup.sh
