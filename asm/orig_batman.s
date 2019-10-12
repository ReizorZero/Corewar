.name   "Batman"    
.comment   "This city needs me"
loop:                               #-1
    sti r1, %:live, %1              #1
live:                               #-2
    live %0                         #2
    ld %0, r2                       #3
    zjmp %:loop                     #4
