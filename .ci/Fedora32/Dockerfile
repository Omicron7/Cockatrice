FROM fedora:32

RUN dnf install -y \
        @development-tools \
        ccache \
        cmake \
        desktop-file-utils \
        file \
        gcc-c++ \
        git \
        hicolor-icon-theme \
        libappstream-glib \
        protobuf-devel \
        qt5-{qttools,qtsvg,qtmultimedia,qtwebsockets}-devel \
        rpm-build \
        sqlite-devel \
        wget \
        xz-devel \
        zlib-devel \
    && dnf clean all
