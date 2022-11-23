sudo fallocate -l 50M lofs.img
sudo losetup -f lofs.img
sudo mkfs.ext4 lofs.img
mkdir lofsdisk
sudo mount lofs.img lofsdisk