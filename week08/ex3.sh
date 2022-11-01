gcc ex2.c -o ex2
./ex2 &
top -d 1

# Observation: 
# It may be observed from the top command report that as the program keeps running the amount of shared memory and allocated virtual memory increases. 
# It means that even if there is not enough space available for the allocation of all the pointers and values in the program, 
# Due to swap in and swap out functionality the program does not get to overwhelm the machine. 