.name 		"laugh"
.comment	"aff, just kidding"

# hello:
# 	live	%0
# 	sti		r1, %:label, %1
# 	fork	%:label
# 	add		r2, r3, r4
	live	%0

label:
	zjmp	%:label
