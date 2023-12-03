FROM mcr.microsoft.com/devcontainers/cpp:1-debian-11

ARG REINSTALL_CMAKE_VERSION_FROM_SOURCE="none"

# Optionally install the cmake for vcpkg
COPY ./reinstall-cmake.sh /tmp/

RUN if [ "${REINSTALL_CMAKE_VERSION_FROM_SOURCE}" != "none" ]; then \
        chmod +x /tmp/reinstall-cmake.sh && /tmp/reinstall-cmake.sh ${REINSTALL_CMAKE_VERSION_FROM_SOURCE}; \
    fi \
    && rm -f /tmp/reinstall-cmake.sh

# [Optional] Uncomment this section to install additional vcpkg ports.
RUN su vscode -c "${VCPKG_ROOT}/vcpkg install curlpp:x64-linux"
RUN su vscode -c "${VCPKG_ROOT}/vcpkg install gtest:x64-linux"



RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends clangd-9
RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
    && apt-get -y install --no-install-recommends clang-format


# Install clangd 17
RUN mkdir -p /home/vscode/temp/
RUN wget https://github.com/clangd/clangd/releases/download/17.0.3/clangd-linux-17.0.3.zip -P /home/vscode/temp/
RUN unzip /home/vscode/temp/clangd* -d /home/vscode/temp/
RUN sudo cp -R /home/vscode/temp/clangd_17.0.3/lib/* /usr/local/lib/
RUN sudo cp -R /home/vscode/temp/clangd_17.0.3/bin/* /usr/local/bin/
RUN rm -rf /home/vscode/temp

# RUN mkdir -p ~/.ssh && chmod 700 ~/.ssh
# RUN ssh-keyscan -t rsa github.com >> ~/.ssh/known_hosts
# RUN ssh -Tv git@github.com
# RUN git clone git@github.com:linderlake/AoCHelper.git /home/vscode/AoCHelper
# RUN ln -s /home/vscode/AoCHelper/build/libAoCHelper.a ../lib/AocHelper/libAoCHelper.a
# RUN ln -s /home/vscode/AoCHelper/src/AoCHelper.h ../lib/AocHelper/include/AoCHelper.h
# RUN ln -s /home/vscode/AoCHelper/src/helper_functions.h ../lib/AocHelper/include/helper_functions.h
# [Optional] Uncomment this section to install additional packages.
# RUN apt-get update && export DEBIAN_FRONTEND=noninteractive \
#     && apt-get -y install --no-install-recommends <your-package-list-here>
