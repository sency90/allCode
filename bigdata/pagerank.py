import sys
from pyspark import SparkContext

if __name__ == "__main__":
    sc = SparkContext("local", "pagerank")
    lines = sc.textFile("/hw2/links.txt")
    
