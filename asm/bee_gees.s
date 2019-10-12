.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
	
sti	r1, %:live, %1			;change live by the right value			#1
sti	r1, %:live2, %1			;change live by the right value			#2
ld	%1, r3															#3
ld	%33, r6															#4
#While (r2 < 10)													
forks:																#-5
add	r2, r3, r2		;increment r2									#5
xor	r2, %15, r4		;if (r4) {carry = 0}							#6
live2:																#-7
	live 	%4														#7
zjmp	%:endwhile		;if (carry)									#8
fork	%:forks														#9
ld	%0, r4			;carry = 1										#10
zjmp	%:forks														#11
#EndWhile
endwhile:															#-12
ld	%0, r4			;carry = 1										#12

live:																#-13
live %4																#13
zjmp %:live															#14
