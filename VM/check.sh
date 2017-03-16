clear

function match
{
	echo "=============================="
	echo $1
	diff <(./corewar -h $1) <(../resources/corewar $1)
}

match "-d $1 $2 $3 $4 $5"
