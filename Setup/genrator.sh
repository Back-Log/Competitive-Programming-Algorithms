# Copied from Errichto 
for((i=1;;i++));do # remove condition for endless loop
	echo $i
	./gen $i > int
	./sol< int >out1
	./temp< int >out2
	diff -w out1 out2 || break
	# diff -w (./sol < int)<(./temp<int) || break
done


#2nd more user friendly
#Copied from jayleeds
for((i=1;;i++));do # condition for endless loop
	echo "$i OK"
	./gen $i > int
	./sol< int >out1
	./temp< int >out2
	if !(cmp -s "out1" "out2")
    then
        echo "Error found!"
        echo "Input:"
        cat int
        printf "\n"
        echo "My Output:"
        cat out1
        echo "Correct Output:"
        cat out2
        exit
    fi
done