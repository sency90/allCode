import sys
from pyspark import SparkContext, SparkConf

conf = SparkConf().setMaster("local").setAppName("sort")
sc = SparkContext(conf = conf)

lines = sc.textFile(sys.argv[1])
word = lines.flatMap(lambda x : x.split(", ")).filter(lambda x: x!='').cache()
count = word.map(lambda x: (int(x), 1)).cache()
sortedCount = count.sortByKey().cache()

for(num, unitcount) in sortedCount.collect():
    print(num)

sc.stop()
