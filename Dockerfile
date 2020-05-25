FROM alpine:latest

RUN apk --no-cache add cmake clang clang-dev make gcc g++ libc-dev linux-headers git make
WORKDIR /tmp
RUN git clone https://github.com/riera90/LWCPPS
WORKDIR /tmp/LWCPPS/build
RUN cmake .. && make install

ADD ./app /DDCD-regional-balancer/app
ADD ./CMakeLists.txt /DDCD-regional-balancer
WORKDIR /DDCD-regional-balancer/build
RUN cmake .. && make
CMD ./DDCD-regional-balancer
