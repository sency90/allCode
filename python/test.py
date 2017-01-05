import urllib
from bs4 import BeautifulSoup

fp = urllib.urlopen ('https://www.acmicpc.net/ranklist')
source = fp.read()
fp.close()

soup = BeautifulSoup(source)
print soup.title.string

#table = soup.find(id="ranklist")
#trs = table.tbody.find_all('tr')

#print table
#print len(trs)
