minikube start --driver=virtualbox
eval $(minikube docker-env)

#metallb
minikube addons enable metallb
kubectl apply -f ./srcs/metallb/metallb.yaml

# nginx
cd ./srcs/nginx
docker build -t nginx:latest .
kubectl apply -f ./nginx.yaml

# mysql
cd ../mysql
docker build -t mysql:latest .
kubectl apply -f mysql_pv.yaml
kubectl apply -f mysql.yaml

# phpmyadmin
cd ../phpmyadmin
docker build -t phpmyadmin:latest .
kubectl apply -f phpmyadmin.yaml

# wordpress
cd ../wordpress
docker build -t wordpress:latest .
kubectl apply -f wordpress.yaml

# ftps
cd ../ftps
docker build -t ftps:latest .
kubectl apply -f ftps.yaml

# influxdb
cd ../influxdb
docker build -t influxdb:latest .
kubectl apply -f influxdb.yaml

# telegraf
cd ../telegraf
docker build -t telegraf:latest .
kubectl apply -f telegraf.yaml

# grafana
cd ../grafana
docker build -t grafana:latest .
kubectl apply -f grafana.yaml
