#Copied from jayleeds
for((i=1;;i++));do # condition for endless loop
	echo -e "$i \e[1;32mOK \e[0m"
	./gen $i > int
	./sol< int >out1
	./temp< int >out2
	if !(cmp -s "out1" "out2")
    then
	    echo -e "\e[1;31mError found! \e[0m"
        # echo "Input:"
	    echo -e "\e[1;36mInput: \e[0m"
        cat int
        printf "\n"
	    echo -e "\e[1;37mMy Output: \e[0m"

        # echo "My Output:"
        cat out1
	    echo -e "\e[1;37mCorrect Output: \e[0m"

        # echo "Correct Output:"
        cat out2
        exit
    fi
done
