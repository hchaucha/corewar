make_test_false()
{
	./tests/asm ./tests/ressources/players/$1.s > ./trace.txt

	let "asm_total += 1"
	if [ ! -e ./tests/ressources/players/$1.cor ]
	then
		printf "|  %-88s : [\033[32mOK\033[0m]|\n" "$1"
		let "asm_tests += 1"
	else
		printf "|  %-88s : [\033[31mKO\033[0m]|\n" "$1"
	fi
}

make_test()
{
	./tests/asm_zaz ./tests/ressources/players/$1.s > /dev/null ; mv ./tests/ressources/players/$1.cor ./tests/sandbox/ ; mv ./tests/sandbox/$1.cor ./tests/sandbox/zaz.cor > /dev/null
	./tests/asm ./tests/ressources/players/$1.s ; mv ./tests/ressources/players/$1.cor ./tests/sandbox/

	let "asm_total += 1"
	result=$(diff ./tests/sandbox/zaz.cor ./tests/sandbox/$1.cor)
	if [ $? -eq 0 ]
	then
		printf "|  %-88s : [\033[32mOK\033[0m]|\n" "$1"
		let "asm_tests += 1"
		rm ./tests/sandbox/zaz.cor
		mv ./tests/sandbox/$1.cor ./tests/sandbox/passed
	else
		printf "|  %-88s : [\033[31mKO\033[0m]|\n" "$1"
		mv ./tests/sandbox/$1.cor ./tests/sandbox/failed/
		mv ./tests/sandbox/zaz.cor ./tests/sandbox/failed/$1_zaz.cor
	fi
}

asm_total=0
asm_tests=0

echo "|-------------------------------------------------------------------------------------------------|"
echo "|                                          ASM TESTS                                              |"
echo "|-------------------------------------------------------------------------------------------------|"

make_test_false 00_empty
make_test_false 01_empty_mul_lines
make_test_false 02_empty_header_only
make_test_false 05_multi_name
make_test_false 06_multi_comment
make_test_false 07_unknown_instr
make_test_false 08_unknown_instr
make_test_false 09_bad_param_nb
make_test_false 10_bad_param_nb
make_test_false 11_bad_param_type
make_test_false 12_bad_param_type
make_test_false 13_bad_label_char
make_test_false 14_bad_label_char
make_test_false 15_bad_label_ref
make_test_false 16_bad_label_ref
make_test_false 17_bad_sep_char
make_test_false 18_bad_sep_char
make_test_false 19_bad_sep_char
make_test_false 20_no_virgul
make_test_false 21_no_label_declared
make_test_false 22_comment_behind_name
make_test_false 23_no_newline
make_test_false 34_coments
make_test_false 35_all_fake
make_test_false 36_char
make_test_false 37_label_false
make_test_false 38_label_false_newline

make_test test
make_test 32_all_instr_only
make_test 33_all_instr_label
make_test tartiflette
make_test Asombra
make_test zork
make_test bigzork
make_test bee_gees
make_test cantfindaname
make_test casimir
make_test champ
make_test corelol
make_test darksasuke
make_test doge
make_test dubo
make_test fluttershy
make_test gedeon
make_test helltrain
make_test jinx
make_test justin_bee
make_test Kappa
make_test littlepuppy
make_test live 
make_test loose 
make_test Machine-gun 
make_test MarineKing 
make_test meowluigi 
make_test Rainbow_dash 
make_test salamahenagalabadoun 
make_test sam_2_0 
make_test skynet 
make_test terminator 
make_test THUNDER 
make_test turtle
make_test ultimate-surrender 
make_test unit_ls_st 
make_test Varimathras 
make_test Wall 
make_test xorus 
make_test youforkmytralala
make_test 42
make_test Car
make_test Death
make_test Gagnant
make_test Octobre_Rouge_V4.2
make_test Survivor
make_test Torpille
make_test barriere
make_test jumper
make_test lde
make_test mat
make_test maxidef
make_test mortel
make_test slider2
make_test tdc2
make_test tdc3
make_test tdc4
make_test toto
make_test knock-puncher
make_test victarion
make_test try-again
make_test fenix

echo "|-------------------------------------------------------------------------------------------------|"
echo "|                                        Fin des tests                                            |"
echo "|-------------------------------------------------------------------------------------------------|"

if [[ $asm_tests == $asm_total ]]
then
	printf "%-35s |  Tests passed [\033[32m%2d/%2d\033[0m]  |\n" "" "$asm_tests" "$asm_total"
	printf "%-35s |------------------------|\n" ""
else
	printf "%-35s |  Tests passed [\033[31m%2d/%2d\033[0m]  |\n" "" "$asm_tests" "$asm_total"
	printf "%-35s |------------------------|\n" ""
fi
