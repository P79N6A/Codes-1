import urllib2

def download(url, user_agent = None):
	print "Downloading:", url
	request = urllib2.Request(url, None, headers={'User-Agent' : user_agent})
	response = urllib2.urlopen(request)
	return response.read()


if __name__ == "__main__":
	print download("http://www.qlcoder.com/train/secret", "qlcoder spider")