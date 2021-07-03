echo "5-0-1"
cat testnames-10.csv | ./5-0-1.out

echo ""
echo "5-0-2: " 
cat testnames-10.csv | ./5-0-2.out

echo ""
echo "5-0-3: " 
cat testnames-10.csv | ./5-0-3.out

echo ""
echo "5-0-4: " 
cat testnames-10.csv | ./5-0-4.out

echo ""
echo "5-2-vector: " 
cat testnames-10.csv | ./5-2-vector.out

echo ""
echo "5-2-list: " 
cat testnames-10.csv | ./5-2-list.out

echo ""
echo "5-6: " 
cat testnames-10.csv | ./5-6.out
