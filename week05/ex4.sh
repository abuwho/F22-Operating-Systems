gcc -pthread -o ex4 ex4.c
n=10000000

> ex4.txt

for m in 1 2 4 10 100
do 
	start=$SECONDS
	./ex4 $n $m
	duration=$((SECONDS - start))
	echo "Time elapsed: $duration seconds" >> ex4.txt 
done
