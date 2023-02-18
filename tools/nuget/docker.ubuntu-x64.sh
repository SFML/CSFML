#!/bin/bash

# Automatically exit on error
set -e

apt-get update

apt-get install -y \
    git \
    libfreetype6-dev \
    xorg-dev \
    libxrandr-dev \
    libxcursor-dev \
    libudev-dev \
    libgl1-mesa-dev \
    libflac-dev \
    libogg-dev \
    libvorbis-dev \
    libopenal-dev \
    cmake \
    g++

./build.linux.sh ubuntu-x64
