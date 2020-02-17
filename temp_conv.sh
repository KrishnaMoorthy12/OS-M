echo -n "Enter the temperature in Fahrenheit: "
read f
c=`expr $f - 32`
c=`expr $c \* 5`
c=`expr $c / 9`
echo "The equivalent temperature in Celsius is $c"
