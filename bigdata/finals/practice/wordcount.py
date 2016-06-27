import sys
import re
from pyspark import SparkConf, SparkContext

if __name__ == "__main__":
    """
    if len(sys.argv) != 2:
        print("Usage: wordcount <file>", file=sys.stderr)
        exit(-1)
    """

    conf = SparkConf().setMaster("local").setAppName("wordcount")
    sc = SparkContext(conf = conf)

    lines = sc.textFile("README.md")
    words = lines.flatMap(lambda line: re.split(r'\s+', line))
    words = words.map(lambda word: (word, 1))
    results = words.reduceByKey(lambda x, y: x+y).persist()
    output = results.collect()

    for (word, count) in output:
        print("%s: %i" % (word, count))

    sc.stop()
