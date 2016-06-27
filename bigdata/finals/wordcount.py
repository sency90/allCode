#
# Licensed to the Apache Software Foundation (ASF) under one or more
# contributor license agreements.  See the NOTICE file distributed with
# this work for additional information regarding copyright ownership.
# The ASF licenses this file to You under the Apache License, Version 2.0
# (the "License"); you may not use this file except in compliance with
# the License.  You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

#from __future__ import print_function

import sys
from pyspark import SparkContext, SparkConf

if __name__ == "__main__":
    sc = SparkContext("local", "wordcount")

    lines = sc.textFile("links.txt")
    counts = lines.flatMap(lambda x: x.split(', ')).filter(lambda x: x!='').map(lambda x: (int(x),1)).reduceByKey(lambda x, y: x+y).cache()

    output = counts.sortByKey().collect()
    for (word, count) in output:
        print("%s: %i" % (word, count))

sc.stop()
