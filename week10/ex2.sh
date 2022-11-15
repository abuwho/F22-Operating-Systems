mkdir -p week01
touch week01/file.txt
echo "Abu Huraira BS21-07" > week01/file.txt
link week01/file.txt _ex2.txt
echo "Linked inodes $(ls week01/file.txt -i | awk '{print $1}')" 1>&2
find ./ -inum $(ls week01/file.txt -i | awk '{print $1}') > ex2.txt
find ./ -inum $(ls week01/file.txt -i | awk '{print $1}') -exec rm {} \;