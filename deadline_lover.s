.name 		"deadline_lover"
.comment	"each teammate in our team loves deadlines very much <3 "

start:	sti r1, %:p1, %1
p1:     live %1
        fork %:start

        sti r1, %:p3, %1
        ld 0, r3
p3:     live %1
        zjmp %:p3
