from pyspark import SparkConf, SparkContext

sc = SparkContext("local", "test")
invalid = sc.accumulator(0)

def count_invalid(el):
    invalid.add(el)
    return el

info = sc.parallelize([3,4,5])
info2 = info.map(lambda x: count_invalid(x))

for x in info2.collect():
    print(x)

print(invalid)
sc.stop()
