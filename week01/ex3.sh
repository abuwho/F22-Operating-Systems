mkdir root
date
sleep 3
mkdir home
date
sleep 3
touch root/root.txt
date
sleep 3
touch home/home.txt
date
sleep 3
ls -la -tr ~ > home/home.txt
ls -la -tr / > root/root.txt
