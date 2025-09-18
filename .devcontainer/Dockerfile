FROM ubuntu:22.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y build-essential valgrind vim bash-completion git gdb

RUN rm /etc/apt/apt.conf.d/docker-clean

COPY comp60261-devcontainer /root/

WORKDIR /root