echo -n "No 1: "
read a
echo -n "No 2: "
read b

t=$a
a=$b
b=$t

echo "No 1: $a, No 2: $b"
