FROM python:3.9-slim

RUN apt-get update && apt-get install -y build-essential cmake curl python3-pip && apt-get clean

WORKDIR /app
COPY . .

RUN pip install requests geopy unittest2 pybind11

RUN mkdir build && cd build && cmake .. && make

CMD ["bash"]
