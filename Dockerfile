FROM alpine

WORKDIR /app

COPY . .

RUN apk add g++ make && \
  make

CMD ["./main"]