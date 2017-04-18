.name	"i dont know"
.comment	"idk lol"

				lfork		%:wallup
				st			r1, 21
				st			r1, 21
				st			r16, -9
				st			r16, -9
				live		%66			; 01 ff ff ff     ff 01 ff ff   ff ff 01 ff  ff ff ff 01	 ff ff ff ff
				live		%66
				ld			-5, r2
				ld			-11, r3
				ld			-17, r4
				ld			-23, r5
				ld			-29, r6
				ld			%0, r16
				zjmp		%:entry


wallup:			st			r16, -4
				st			r16, -13
				st			r16, -22
				st			r16, -31
				st			r16, -40
				st			r16, -49
				st			r16, -58
				st			r16, -67
				st			r16, -76
				st			r16, -85
				st			r16, -94
				st			r16, -103
				st			r16, -112
				st			r16, -121
				st			r16, -130
				live		%66
				zjmp		%:wallup


entry:			live		%66

				ld		%0, r16

				fork	%:b

				live	%66
a:				
				fork	%:c
				zjmp	%:d
b:				live	%66
				fork	%:e
				zjmp	%:f


c:				
				fork	%:wallup
				zjmp	%:entry
d:				
				fork	%:heart
				zjmp	%:entry
e:				
				fork	%:beat
				zjmp	%:entry
f:				
				fork	%:walldown
				zjmp	%:entry



heart:			live	%66
				st		r2, 28
				st		r3,	27
				st		r4,	26
				st		r5,	25
				st		r6,	24
				zjmp	%:heart

beat:			live	%66
				live	%66
				live	%66
				live	%66
				zjmp	%:beat

walldown:		live		%66
				st			r16, 83
				st			r16, 82
				st			r16, 81
				st			r16, 80
				st			r16, 79
				st			r16, 78
				st			r16, 77
				st			r16, 76
				st			r16, 75
				st			r16, 74
				st			r16, 73
				st			r16, 72
				st			r16, 71
				st			r16, 70
				st			r16, 69
				st			r16, 68
				zjmp		%:walldown
