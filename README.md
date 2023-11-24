```sh
pip install qmk
sudo apt install gcc-avr avr-libc
git clone git@github.com:qmk/qmk_firmware
cd qmk_firmware
git clone git@github.com:gmoshkin/ergodox-layout keyboards/ergodox_ez/keymaps/gmoshkin
make ergodox_ez/glow:gmoshkin
'/mnt/c/Program Files (x86)/Wally/wally-cli.exe' 'path\to\ergodox_ez_glow_gmoshkin.hex'
```
