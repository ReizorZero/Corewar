.name     "Batman" #kamment
.comment   "This city needs me" #kamment
 
#live %0
                    #ische kamment    
loop: 
    sti             r1,           %:live,             %1

live:
    live %0
    ld %0, r2
    zjmp %:loop
