import urllib2
import re

def get_sum(html, regx):
	scores = re.compile(regx).findall(html)
	rank = re.compile('<em class="">(.+)</em>').findall(html)
	ret = 0
	for i in range(0, 25):
		if int(rank[i]) > 166:
			break
		ret += float(scores[i])
	return ret

def download(url):
	print "Downloading:", url
	request = urllib2.Request(url)
	opener = urllib2.build_opener()
	response = opener.open(request)
	return response.read()


if __name__ == "__main__":
	ans = 0
	for i in range(0, 166, 25):
		html = download(("https://movie.douban.com/top250?start=%d&filter=") % (i))
		ans += get_sum(html, '<span class="rating_num" property="v:average">(.+)</span>')
	print ans