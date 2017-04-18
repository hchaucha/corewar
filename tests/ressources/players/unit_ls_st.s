.name "unit_test ld st"
.comment "fuck dis"

ld	%-42, r2
st	r1, 42
st r2, -511
st r1, r2
st r2, -506
end:
