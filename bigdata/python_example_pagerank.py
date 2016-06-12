links = 
ranks =

for i in range(NUM_ITERATIONS):
	def compute contribs(pair):
		[url, [links, rank]] = pair
		return [(dest, rnak/len(links)) for dest in links]

	contribs = links.join(ranks).flatMap(compute_contribs)
	ranks = contribs.reduceByKey(lambda x, y: x+y).mapValues(lambda x: 0.15 + 0.85*x)

ranks.saveAsTextFile(...)