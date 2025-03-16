```sh
pip install qmk
sudo apt install gcc-avr avr-libc
git clone git@github.com:qmk/qmk_firmware
cd qmk_firmware

# In 64b1ed45507a15d5594b1f90b936c2096918f5a4 they once again broken my shit and
# I'm not going to waste more time on figuring out how to fix it
git checkout 64b1ed45507a15d5594b1f90b936c2096918f5a4~1

git clone git@github.com:gmoshkin/ergodox-layout keyboards/ergodox_ez/keymaps/gmoshkin
make ergodox_ez/glow:gmoshkin
'/mnt/c/Program Files (x86)/Wally/wally-cli.exe' 'path\to\ergodox_ez_glow_gmoshkin.hex'
```
