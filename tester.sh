g++-14 --std=c++17 $1.cpp -o $1 && cat data/in.txt | ./$1 > data/generated.txt
s1=$(cat data/generated.txt)
s2=$(cat data/out.txt)

if [[ "$s1" == "$s2" ]]
then
	echo "Passed"
else
	echo "Failed. To be correct, the following changes must be achieved.\n"
	diff --minimal --color data/generated.txt data/out.txt
fi