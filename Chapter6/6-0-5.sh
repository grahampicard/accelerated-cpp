echo ""
echo "6-0-6: " 
echo `date`
cat ../Chapter5/testnames-10000.csv | ./6-0-6.out > /dev/null
echo `date`

echo ""
echo "6-0-7: " 
echo `date`
cat ../Chapter5/testnames-10000.csv | ./6-0-7.out > /dev/null
echo `date`

# We can see that the new version using iterators is MUCH faster.