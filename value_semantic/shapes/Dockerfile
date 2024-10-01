FROM fedora:37

RUN dnf upgrade -y
RUN dnf install -y google-benchmark-devel
RUN dnf install -y g++
RUN dnf install -y mpark-variant-devel

COPY benchmark.cpp benchmark.cpp
COPY shapes_oop.h shapes_oop.h
COPY shapes_variant.h shapes_variant.h
COPY shapes_mpark.h shapes_mpark.h

RUN g++ benchmark.cpp -O2 -lbenchmark -o patate
