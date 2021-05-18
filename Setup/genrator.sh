# Copied from Errichto 
for((i=1;;i++));do # remove condition for endless loop
	echo $i
	./gen $i > int
	./sol< int >out1
	./temp< int >out2
	diff -w out1 out2 || break
	# diff -w (./sol < int)<(./temp<int) || break
done