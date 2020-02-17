echo -n "Enter a char: "
read ch

case $ch in
  a|e|i|o|u) echo "It's a vowel";;
  *) echo "It's a consonant";
esac
