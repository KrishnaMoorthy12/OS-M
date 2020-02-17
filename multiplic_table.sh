echo -n "Enter a number to get its multiplication table:"
read m
for x in 1 2 3 4 5 6 7 8 9 10 11 12
do
  p=`expr $x \* $m`
echo "$m x $x = $p"
done
