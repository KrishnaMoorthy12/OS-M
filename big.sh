
echo -n "Give value for A B and C: "
read a b c
if [ $a -gt $b -a $a -gt $c ]
then
 echo "$a is the Biggest number"
elif [ $b -gt $c ]
then
 echo "$b is the Biggest number"
else
 echo "$c is the Biggest number"
fi


