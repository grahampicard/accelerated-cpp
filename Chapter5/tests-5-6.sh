echo ""
echo "5-6: " 
echo `date`
cat testnames-10000.csv | ./5-6.out > /dev/null
echo `date`

echo ""
echo "5-0-2: " 
echo `date`
cat testnames-10000.csv | ./5-0-2.out > /dev/null
echo `date`
