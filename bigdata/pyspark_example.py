links = # RDD of (url, neighbors) pairs
ranks = # RDD of (url, rank) pairs
for i in range(NUM_ITERATIONS):
    def compute_contribs(pair):
        [url, [links, rank]] = pair #split key-value pair
        return [(dest, rank/len(links)) for dest in links]

    contribs = links.join(ranks).flatMap(comput_contribs)
    ranks = contribs.reduceByKey(lambda x, y: x+y).mapValues(lambda x: 0.15 + 0.85*x)

ranks.saveAsTextFile(...)
