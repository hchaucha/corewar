make_tests_solo()
{
	length=${#1}
	total_length=0
	diff_length=0

	if [ $length -gt 15 ]
	then
		let "total_length = length + 4"
	else
		let "total_length = 15 + 4"
	fi
	let "diff_length = 92 - total_length"

	if [ $2 ]
	then
		./tests/corewar_zaz -v $2 ./tests/sandbox/passed/$1.cor > ./tests/sandbox/zaz.txt
		./tests/corewar -v -c ./tests/sandbox/passed/$1.cor > ./tests/sandbox/our.txt
	else
		./tests/corewar_zaz ./tests/sandbox/passed/$1.cor > ./tests/sandbox/zaz.txt
		./tests/corewar ./tests/sandbox/passed/$1.cor > ./tests/sandbox/our.txt
	fi
	
	let "war_total += 1"
	result=$(cmp ./tests/sandbox/zaz.txt ./tests/sandbox/our.txt)
	if [ $? -eq 0 ]
	then
		printf "|  %-15s %s" "$1"
		while (($diff_length > 0 ))
		do
			printf " "
			diff_length=$(($diff_length - 1))
		done
		printf ": [\033[32mOK\033[0m]|\n"
		let "war_tests += 1"
	else
		printf "|  %-15s %s " "$1"
		while (($diff_length > 0 ))
		do
			printf " "
			diff_length=$(($diff_length - 1))
		done
		printf ": [\033[31mKO\033[0m]| -> %s\n" "$result"
	fi
	
	rm ./tests/sandbox/our.txt
	rm ./tests/sandbox/zaz.txt
}

make_tests_duo()
{
	length1=${#1}
	length2=${#2}
	total_length=0
	if [ $length1 -gt 15 ]
	then
		let "total_length = $length1"
	else
		let "total_length = 15"
	fi
	if [ $length2 -gt 15 ]
	then
		let "total_length += $length2 + 4"
	else
		let "total_length += 15 + 4"
	fi

	diff_length=0
	let "diff_length = 82 - total_length"

	if [ $3 ]
	then
 		./tests/corewar_zaz -v $3 ./tests/sandbox/passed/$1.cor ./tests/sandbox/passed/$2.cor > ./tests/sandbox/zaz.txt
		./tests/corewar -v -c ./tests/sandbox/passed/$1.cor ./tests/sandbox/passed/$2.cor > ./tests/sandbox/our.txt
	else
		./tests/corewar_zaz ./tests/sandbox/passed/$1.cor ./tests/sandbox/passed/$2.cor > ./tests/sandbox/zaz.txt
		./tests/corewar ./tests/sandbox/passed/$1.cor ./tests/sandbox/passed/$2.cor > ./tests/sandbox/our.txt
	fi

	let "war_total += 1"
	result=$(cmp ./tests/sandbox/zaz.txt ./tests/sandbox/our.txt)
	if [ $? -eq 0 ]
	then
		printf "|  %-15s   %-5s %-15s %s " "$1" "Vs." "$2"
		while (($diff_length > 0 ))
		do
			printf " "
			diff_length=$(($diff_length - 1))
		done
		printf ": [\033[32mOK\033[0m]|\n"
		let "war_tests += 1"
	else
		printf "|  %-15s   %-5s %-15s %s " "$1" "Vs." "$2"
		while (($diff_length > 0 ))
		do
			printf " "
			diff_length=$(($diff_length - 1))
		done
		printf ": [\033[31mKO\033[0m]| -> %s\n" "$result"
	fi
	
	rm ./tests/sandbox/our.txt
	rm ./tests/sandbox/zaz.txt
}

make_tests_trio()
{
	var1=${1:0:15}
	var2=${2:0:15}
	var3=${3:0:15}
	total_length=0
	diff_length=0
	let "total_length = (15 * 3) + (2 * 8) + 4"
	let "diff_length = 89 - total_length"

	if [ $4 ]
	then
 		./tests/corewar_zaz -v $4 ./tests/sandbox/passed/$1.cor ./tests/sandbox/passed/$2.cor  ./tests/sandbox/passed/$3.cor > ./tests/sandbox/zaz.txt
		./tests/corewar -v -c ./tests/sandbox/passed/$1.cor ./tests/sandbox/passed/$2.cor ./tests/sandbox/passed/$3.cor > ./tests/sandbox/our.txt
	else
		./tests/corewar_zaz ./tests/sandbox/passed/$1.cor ./tests/sandbox/passed/$2.cor ./tests/sandbox/passed/$3.cor > ./tests/sandbox/zaz.txt
		./tests/corewar ./tests/sandbox/passed/$1.cor ./tests/sandbox/passed/$2.cor ./tests/sandbox/passed/$3.cor > ./tests/sandbox/our.txt
	fi

	let "war_total += 1"
	result=$(cmp ./tests/sandbox/zaz.txt ./tests/sandbox/our.txt)
	if [ $? -eq 0 ]
	then
		printf "|  %-15s   %-5s %-15s   %-5s %-15s %s " "$var1" "Vs." "$var2" "Vs." "$var3"
		while (($diff_length > 0 ))
		do
			printf " "
			diff_length=$(($diff_length - 1))
		done
		printf ": [\033[32mOK\033[0m]|\n"
		let "war_tests += 1"
	else
		printf "|  %-15s   %-5s %-15s   %-5s %-15s %s " "$var1" "Vs." "$var2" "Vs." "$var3"
		while (($diff_length > 0 ))
		do
			printf " "
			diff_length=$(($diff_length - 1))
		done
		printf ": [\033[31mKO\033[0m]| -> %s\n" "$result"
	fi
	
	rm ./tests/sandbox/our.txt
	rm ./tests/sandbox/zaz.txt
}

make_tests_quater()
{
	var1=${1:0:15}
	var2=${2:0:15}
	var3=${3:0:15}
	var4=${4:0:15}
	total_length=0
	diff_length=0
	let "total_length = (15 * 4) + (3 * 8) + 4"
	let "diff_length = 88 - total_length"

	if [ $5 ]
	then
 		./tests/corewar_zaz -v $5 ./tests/sandbox/passed/$1.cor ./tests/sandbox/passed/$2.cor  ./tests/sandbox/passed/$3.cor ./tests/sandbox/passed/$4.cor > ./tests/sandbox/zaz.txt
		./tests/corewar -v -c ./tests/sandbox/passed/$1.cor ./tests/sandbox/passed/$2.cor ./tests/sandbox/passed/$3.cor ./tests/sandbox/passed/$4.cor > ./tests/sandbox/our.txt
	else
		./tests/corewar_zaz ./tests/sandbox/passed/$1.cor ./tests/sandbox/passed/$2.cor ./tests/sandbox/passed/$3.cor ./tests/sandbox/passed/$4.cor > ./tests/sandbox/zaz.txt
		./tests/corewar ./tests/sandbox/passed/$1.cor ./tests/sandbox/passed/$2.cor ./tests/sandbox/passed/$3.cor ./tests/sandbox/passed/$4.cor > ./tests/sandbox/our.txt
	fi

	let "war_total += 1"
	result=$(cmp ./tests/sandbox/zaz.txt ./tests/sandbox/our.txt)
	if [ $? -eq 0 ]
	then
		printf "|  %-15s   %-5s %-15s   %-5s %-15s   %-5s %-15s %s " "$var1" "Vs." "$var2" "Vs." "$var3" "Vs." "$var4"
		while (($diff_length > 0 ))
		do
			printf " "
			diff_length=$(($diff_length - 1))
		done
		printf ": [\033[32mOK\033[0m]|\n"
		let "war_tests += 1"
	else
		printf "|  %-15s   %-5s %-15s   %-5s %-15s   %-5s %-15s %s " "$var1" "Vs." "$var2" "Vs." "$var3" "Vs." "$var4"
		while (($diff_length > 0 ))
		do
			printf " "
			diff_length=$(($diff_length - 1))
		done
		printf ": [\033[31mKO\033[0m]| -> %s\n" "$result"
		echo "$1 Vs. $2 -> $result" >> ./tests/sandbox/trace.txt
	fi
	
	rm ./tests/sandbox/our.txt
	rm ./tests/sandbox/zaz.txt
}
if [[ -e ./tests/sandbox/trace ]]
then
	rm ./tests/sandbox/trace.txt
fi

war_total=0
war_tests=0

echo "|-------------------------------------------------------------------------------------------------|"
echo "|                                          WAR TESTS                                              |"
echo "|-------------------------------------------------------------------------------------------------|"

make_tests_solo helltrain $1
make_tests_solo turtle $1
make_tests_solo fluttershy $1
make_tests_solo zork $1
make_tests_solo bigzork $1
make_tests_solo bee_gees $1
make_tests_solo Machine-gun $1
make_tests_solo MarineKing $1
make_tests_solo meowluigi $1
make_tests_solo Rainbow_dash $1 
make_tests_solo salamahenagalabadoun $1
make_tests_solo sam_2_0 $1
make_tests_solo skynet $1
make_tests_solo terminator $1
make_tests_solo THUNDER $1
make_tests_solo ultimate-surrender $1
make_tests_solo unit_ls_st $1
make_tests_solo Varimathras $1

make_tests_duo tartiflette zork $1
make_tests_duo zork	tartiflette $1
make_tests_duo helltrain helltrain $1
make_tests_duo fluttershy helltrain $1
make_tests_duo fluttershy bee_gees $1
make_tests_duo bee_gees helltrain $1
make_tests_duo turtle helltrain $1
make_tests_duo Machine-gun helltrain $1
make_tests_duo helltrain MarineKing $1
make_tests_duo THUNDER terminator $1
make_tests_duo turtle helltrain $1
make_tests_duo Rainbow_dash skynet $1
make_tests_duo unit_ls_st Varimathras $1
make_tests_duo sam_2_0 terminator $1

make_tests_trio helltrain helltrain helltrain $1
make_tests_trio helltrain fluttershy helltrain $1
make_tests_trio bee_gees fluttershy turtle $1
make_tests_trio turtle death MarineKing $1
make_tests_trio helltrain bee_gees bee_gees $1
make_tests_trio helltrain fluttershy MarineKing $1
make_tests_trio meowluigi fluttershy Varimathras $1
make_tests_trio sam_2_0 ultimate-surrender turtle $1
make_tests_trio unit_ls_st THUNDER skynet $1
make_tests_trio helltrain Machine-gun salamahenagalabadoun $1
make_tests_trio fluttershy helltrain Rainbow_dash $1

make_tests_quater helltrain helltrain helltrain helltrain $1
make_tests_quater helltrain fluttershy helltrain fluttershy $1
make_tests_quater helltrain fluttershy turtle bee_gees $1
make_tests_quater helltrain bee_gees turtle turtle $1
make_tests_quater helltrain bee_gees bee_gees fluttershy $1
make_tests_quater bee_gees helltrain fluttershy fluttershy $1
make_tests_quater fluttershy fluttershy fluttershy fluttershy $1
make_tests_quater MarineKing unit_ls_st Varimathras sam_2_0 $1
make_tests_quater Rainbow_dash skynet meowluigi Machine-gun $1
make_tests_quater Machine-gun helltrain fluttershy turtle $1
make_tests_quater Varimathras MarineKing helltrain THUNDER $1

echo "|-------------------------------------------------------------------------------------------------|"
echo "|                                        Fin des tests                                            |"
echo "|-------------------------------------------------------------------------------------------------|"

if [[ $war_tests == $war_total ]]
then
	printf "%-35s |  Tests passed [\033[32m%2d/%2d\033[0m]  |\n" "" "$war_tests" "$war_total"
	printf "%-35s |------------------------|\n" ""
else
	printf "%-35s |  Tests passed [\033[31m%2d/%2d\033[0m]  |\n" "" "$war_tests" "$war_total"
	printf "%-35s |------------------------|\n" ""
fi
