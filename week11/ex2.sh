sudo mkdir -p lofsdisk/bin
sudo mkdir -p lofsdisk/lib64
sudo mkdir -p lofsdisk/usr/lib
sudo mkdir -p lofsdisk/usr/lib64
sudo cp /bin/bash lofsdisk/bin
sudo ldd /bin/bash | awk '{print $3}' | xargs -I {} cp -v {} lofsdisk{}
sudo cp lofsdisk/usr/lib/* lofsdisk/lib
sudo cp lofsdisk/usr/lib64/* lofsdisk/lib64
sudo echo Abu > lofsdisk/file1
sudo echo Huraira > lofsdisk/file2
sudo gcc ex2.c -o ex2.out
sudo cp ex2.out lofsdisk
sudo chroot lofsdisk /ex2.out > ex2.txt
sudo ./ex2.out >> ex2.txt