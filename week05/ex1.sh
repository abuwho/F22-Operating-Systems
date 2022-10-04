gcc publisher.c -o publisher
gcc subscriber.c -o subscriber

for ((i = 1; i <= $1; i++)) do
	gnome-terminal -- "./subscriber"
done
gnome-terminal -- "./publisher" $1
