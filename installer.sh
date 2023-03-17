echo "--- Downloading Arm GNU Toolchain"
wget https://developer.arm.com/-/media/Files/downloads/gnu/12.2.rel1/binrel/arm-gnu-toolchain-12.2.rel1-x86_64-arm-none-eabi.tar.xz
tar xvf arm-gnu-toolchain-12.2.rel1-x86_64-arm-none-eabi.tar.xz

pip3 install -r requirements.txt