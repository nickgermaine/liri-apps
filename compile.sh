#!/usr/bin/bash

#patch -p1 < ../0001-Add-missing-lm-dep.patch
echo "Liri Apps v-0.1"
rm -rf build
mkdir build && cd build
cmake ..
make
sudo make install
cd ../

sudo cp -r ./usr /

printf "\n\nLiri Apps is now installed.  Check your current app launcher or run 'liri-apps' from terminal."

#./liri-apps
