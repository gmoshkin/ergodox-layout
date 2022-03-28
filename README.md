```sh
pip install qmk
sudo apt install gcc-avr avr-libc
git clone git@github.com:qmk/qmk_firmware
cd qmk_firmware
git clone git@github.com:gmoshkin/ergodox-layout keyboards/ergodox_ez/keymaps/gmoshkin
make ergodox_ez:gmoshkin
# use Wally to flash the resulting ergodox_ez_gmoshkin.hex file
```
