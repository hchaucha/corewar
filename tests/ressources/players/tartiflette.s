.comment "In tartiflette we thrust"
.name "Tartiflette"
	
debut:
	st r1, 232
	st r1, 232
	st r1, 232
	st r1, 232
	st r1, 232
	st r1, 232
	st r1, 232
	st r1, 232
	st r1, 232
	st r1, 232
	ld %400, r1

wallstart:
    ld      %42991616, r2
	ld      %265, r3
	ld      %4294508544, r4
backwall:
	st      r2, -300
	st      r3, -301
	st      r4, -302
	st      r2, -303
	st      r3, -304
	st      r4, -305
	st      r2, -306
	st      r3, -307
	st      r4, -308
	st      r2, -309
	st      r3, -310
	st      r4, -311
	st      r2, -312
	st      r3, -313
	st      r4, -314
    st      r2, -315
	st      r3, -316
	st      r4, -317
	st      r2, -318
	st      r3, -319
	st      r4, -320
	st      r2, -321
	st      r3, -322
	st      r4, -323
	st      r2, -324
	st      r3, -325
	st      r4, -326
	st      r2, -327
	st      r3, -328
	st      r4, -329
	fork %:go
envie:
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	live %1
	ld %0, r16
 	zjmp %:envie
go:
	live %1
