import sys
import re
import pickle

f = open('test.txt', 'r')
a = pickle.load(f)
print a
