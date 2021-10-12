rm -f vec
clang++ main.cpp -std=c++98 -o vec
if [[ -f ./vec ]];then
	./vec
fi