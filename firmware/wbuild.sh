rm -rf build && mkdir build && cd build && 
PICO_SDK_PATH=../../../pico-sdk cmake .. -DPICO_BOARD=pikorom_1m -DPICO_DEFAULT_BOOT_STAGE2=boot2_is25lp080
#PICO_SDK_PATH=../../../pico-sdk cmake .. -DPICO_BOARD=mk -DPICO_DEFAULT_BOOT_STAGE2=boot2_is25lp080
make
