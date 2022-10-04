gcc -pthread -o ex3 ex3.c
n=10000000

> ex3.txt

for m in 1 2 4 10 100
do 
	start=$SECONDS
	./ex3 $n $m
	duration=$((SECONDS - start))
	echo "Time elapsed: $duration seconds" >> ex3.txt
done
