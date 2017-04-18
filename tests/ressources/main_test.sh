cp ./asm/asm ./tests/
cp ./corewar/corewar ./tests
mkdir -p ./tests/sandbox

asm_total=0
asm_tests=0
war_total=0
war_tests=0

mkdir ./tests/sandbox/failed
mkdir ./tests/sandbox/passed

if [[ ! -f ./tests/corewar ]]
then
	printf "Votre VM n'a pas été copiée"
	exit
fi

if [[ ! -f ./tests/asm ]]
then
	printf "Votre assembleur n'a pas été copié"
	exit
fi

sh ./tests/ressources/asm_tests.sh
sh ./tests/ressources/corewar_test.sh $1

rm ./tests/asm
rm ./tests/corewar
rm ./trace.txt
