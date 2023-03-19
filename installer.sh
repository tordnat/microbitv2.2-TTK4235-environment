#!/usr/bin/env bash

set -o errexit
set -o nounset
set -o pipefail
if [[ "${TRACE-0}" == "1" ]]; then
    set -o xtrace
fi

if [[ "${1-}" =~ ^-*h(elp)?$ ]]; then
    echo 'Usage: ./installer.sh /path/to/toolchain/install/dir 

Add argument for custom install directory for Arm GNU Toolchain. 
Default install location is /opt.

'
    exit
fi

ARM_INSTALL_DIR="$(dirname "/opt")"

if [ $# -eq 0 ]
  then
    echo "Arm GNU Toolchain defaulting to installdir /opt"
else
  then
    ARM_INSTALL_DIR="$(dirname "$0")"
fi


main() {
    echo "--- Downloading Arm GNU Toolchain ---"
    wget https://developer.arm.com/-/media/Files/downloads/gnu/12.2.rel1/binrel/arm-gnu-toolchain-12.2.rel1-x86_64-arm-none-eabi.tar.xz
    echo "--- Unpacking Arm GNU Toolchain ---"
    tar xvf arm-gnu-toolchain-12.2.rel1-x86_64-arm-none-eabi.tar.xz
    mv arm-gnu-toolchain-12.2.rel1-x86_64-arm-none-eabi arm-none-eabi-12.2
    mv arm-none-eabi-12.2 ARM_INSTALL_DIR
    echo "--- Installing requirements ---"
    apt install openocd=0.10.0
    pip3 install -r requirements.txt
    echo "--- Cloning Handout Code ---"
    git clone https://github.com/tordnat/microbitv2.2-TTK4235-environment.git
    echo "--- Installation Complete ---"
}

main "$@"

