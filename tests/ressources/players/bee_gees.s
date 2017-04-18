.name "stayin' alive"
.comment "Ha, Ha, Ha, stayiiiiin' aliiiiiiiiiive"
		ld %5, r2
		ld %20, r3

live:	sti r2, r2, r3
		add r2, r3, r3
		ld %0, r5
		zjmp %:live
		 

# label:	
# 		sti r2, r2, %30
# 		add r2, r3, r2

