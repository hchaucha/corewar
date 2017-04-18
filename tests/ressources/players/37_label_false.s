.name "tedfgxc"
.comment "rdfgxc"

# LD : charge la valeur du 1er param dans le registre

# ST : stocke la valeur du registre vers le second paramètre.

# ADD : Additionne les 

ld 255, r16
st r16, r2
st r2, 255
add r1, r2, r3
sub r1, r2, r4

label2: %:toto
#toto