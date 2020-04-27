FROM centos
RUN yum update -y
RUN yum upgrade -y
RUN yum install -y gcc-c++ 
COPY coach.cpp /home/coach.cpp
COPY teams.cpp /home/teams.cpp

