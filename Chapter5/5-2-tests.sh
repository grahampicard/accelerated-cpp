echo "10 lines"
echo -n "vector\t" && cat testnames-10.csv | ./5-2-vector.out
echo -n "list\t" && cat testnames-10.csv | ./5-2-list.out
echo

echo "1 000 lines"
echo -n "vector\t" && cat testnames-1000.csv | ./5-2-vector.out
echo -n "list\t" && cat testnames-1000.csv | ./5-2-list.out
echo

echo "10 000 lines"
echo -n "vector\t" && cat testnames-10000.csv | ./5-2-vector.out
echo -n "list\t" && cat testnames-10000.csv | ./5-2-list.out
echo
