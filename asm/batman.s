.name   "Batman"    
.comment   "This city needs me"
loop:#: 
    sti r1,%:live,%1 #ghjkl <-- ain't detects error here
sti r1 , %:live ,    %1 #ghjkl <-- detects error here
loop:sti r1,%:live,%1
loop: sti r1 , %:live ,    %1
loop: sti r1,r2,    r3
loop: sti r1,r3   ,    r3
live:
death:
chetotam:
    live %0
    ld %0, r2
    zjmp %:loop

empty:
#loop: sti, r1, %:live, %1
#sti, r1, %:live, %1

