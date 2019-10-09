.name   "Batman" 
.comment   "This city needs me"

loop:sti r1,%:live,%1 #dfghjkl
loop:sti r1, %:live,%1 ;dfghjklvhj
loop:sti r1,%:live, %1
loop:sti r1, %:live, %1
loop:sti r1 ,%:live ,%1
    #dfghjkl;'
loop:sti r1 , %:live,%1
loop:sti r1 ,%:live, %1
loop:sti r1 , %:live, %1
    ;fghjkl
loop:sti r1 , %:live ,%1
loop:sti r1 ,%:live , %1
loop:sti r1 , %:live , %1

loop:sti r1 , %:live , %1

sti r1 , %:live
sti r1, %:live
sti r1 ,%:live
sti r1,%:live

sti r1

sti r1,%:live ,%1

live:

#live%0
#live: live%0
#live%0

sti 67
#WRONG CASES THAT WORK, BUT THEY SHOULD NOT
#sti r1,
#sti r1, %2,
#sti r1 %2
#sti r1, %2, 3,
#sti r1, %2 3
#sti r1 %2 3
#sti r1 %2, 3
#loop: sti r1, %2, 3,
#loop: sti r1, %2, 
#loop: sti r1, 
#loop: sti 
#loop: sti r1 r2

#sti , r1, %2, 3
#loop: sti , r1, %2,
#sti , r1, %2,
#loop: ,sti , r1, %2,
#loop: , sti , r1, %2,
#loop: ,sti , r1, %2
