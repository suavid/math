FROM ubuntu:22.04 AS dependencies

RUN apt update && apt upgrade -y &&\
    apt install -y git clang cmake lldb &&\
    git config --global user.name "William Parras" &&\
    git config --global user.meail "william.parras.mendez@gmail.com"

FROM dependencies AS dev
ENTRYPOINT ["tail", "-f",  "/dev/null"]

