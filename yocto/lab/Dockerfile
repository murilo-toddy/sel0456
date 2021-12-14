FROM ubuntu
MAINTAINER Julio Faracco <jcfaracco@gmail.com>

# Apt update list
RUN apt-get update

# Install tzdata without interaction first
RUN DEBIAN_FRONTEND="noninteractive" apt-get -y install tzdata

# Install developer tools
RUN apt-get install -y wget git-core unzip make gcc g++ build-essential subversion sed autoconf automake texi2html texinfo coreutils diffstat python-pysqlite2 docbook-utils libsdl1.2-dev libxml-parser-perl libgl1-mesa-dev libglu1-mesa-dev xsltproc desktop-file-utils chrpath groff libtool xterm gawk fop cpio iproute2 iptables

# Install extra tools
RUN apt-get install -y sudo vim git locales python3 qemu-system-x86 qemu-system-arm qemu-utils qemu-kvm

# Configure container locale
RUN sed -i -e 's/# en_US.UTF-8 UTF-8/en_US.UTF-8 UTF-8/' /etc/locale.gen && \
    locale-gen
ENV LC_ALL en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LANGUAGE en_US:en

# Add poky user
RUN useradd -ms /bin/bash -c "Yocto Account" poky
RUN usermod -aG sudo poky
RUN echo 'poky:poky' | chpasswd

RUN apt-get clean

# QEMU hacks if you are using a tun device
# RUN touch /tmp/qemu-tap-locks/tap0.skip
# RUN sudo /home/poky/yocto/scripts/runqemu-gen-tapdevs 1000 1000 4 tmp/sysroots-components/x86_64/qemu-helper-native/usr/bin

USER poky
WORKDIR /home/poky
