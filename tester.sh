g++-14 --std=c++17 src/$1.cpp -o bin/$1 || { exit 1; }

begin=$(date +%s)
output=$(cat data/in.txt | ./bin/$1)
# sleep 1
end=$(date +%s)

echo $output > data/generated.txt
s1=$(echo $output | xargs)
s2=$(cat data/out.txt | xargs)

# echo $s1 > data/generated.txt
# echo $s2 > data/out.txt

if [[ "$s2" ]]
then

	if [[ "$s1" == "$s2" ]]
	then
		echo "Results matched."
	else
		echo "Results don't match. To be correct, the following changes must be achieved.\n"
		diff --minimal --color data/generated.txt data/out.txt
	fi

else
	echo $output
fi

echo --------------------------
echo "execution took $(expr $end - $begin) second(s)"
