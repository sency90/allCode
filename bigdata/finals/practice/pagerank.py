import sys
from pyspark import SparkContext

def parseNeighbors(urls):
    parts = urls.split(", ")
    dests=[]
    if(parts[1]!=''):
        dests = parts[1:]
    return (int(parts[0]), [int(x) for x in dests])

def compute_contribs(pair):
    [url, [links, rank]] = pair
    return [(dest, rank/len(links)) for dest in links]


if __name__=="__main__":
    sc = SparkContext("local", "pagerank")
    lines = sc.textFile("links.txt")
    links = lines.map(parseNeighbors).cache()
    ranks = links.map(lambda urls: (urls[0], 1.0)).cache()

    for i in range(10):
        contribs = links.join(ranks).flatMap(compute_contribs)
        ranks = contribs.reduceByKey(lambda x, y: x+y).mapValues(lambda x: 0.15 + 0.85*x)

    ranks = ranks.sortBy(lambda x: x[1])
    #ranks.saveAsTextFile("output.txt")
    for rank in ranks.collect():
        print(rank)

    sc.stop()
