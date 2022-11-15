touch _ex3.txt
echo "Abu Huraira BS21-07" > _ex3.txt
chmod ugo-x _ex3.txt
ls -lah | grep _ex3.txt > ex3.txt
chmod uo+rwx _ex3.txt
ls -lah | grep _ex3.txt >> ex3.txt
chmod g+rwx _ex3.txt
ls -lah | grep _ex3.txt >> ex3.txt
echo "1) -rw-rw-rw- means, no execution permission for anyone.
2) -rwxrw-rwx means, all permissions are granted for user and others (for group, only read and write, which are unchanged)
3) -rwxrwxrwx means, group also has same permission as user and others (read, write and execute)" >> ex3.txt