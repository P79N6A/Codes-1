import urllib2
import urlparse
import robotparser
import re

def download(url, user_agent = 'wswp', num_retries = 2):
	print 'Downloading:', url
	headers = {"User-agent" : user_agent}
	request = urllib2.Request(url, headers = headers)
	try:
		html = urllib2.urlopen(request).read()
	except urllib2.URLError as e:
		print 'Download error:', e.reason
		html = None
		if num_retries > 0:
			# recursively retry 5xx HTTP errors
			if hasattr(e, 'code') and 500 <= e.code < 600:
				return download(url, num_retries - 1)
	return html

def crawl_sitemap(url):
	sitemap = download(url)
	links = re.findall('<loc>(.*?)</loc>', sitemap)
	print links
	for link in links:
		html = download(link)
		# ...

def link_crawl(seed_url, link_regx):
	"""Crawl from the given seed URL following links matched by link_regx
	"""
	crawl_queue = [seed_url]
	seen = set(crawl_queue)
	while crawl_queue:
		url = crawl_queue.pop()
		html = download(url)
		# filter for links matching our regular expression
		for link in get_links(html):
			if re.match(link_regx, link):
				link = urlparse.urljoin(seed_url, link)
				if link not in seen:
					seen.add(link)
					crawl_queue.append(link)

def get_links(html):
	"""Return a list of links from html
	"""
	webpage_regex = re.compile('<a[^>]+href=["\'](.*?)["\']',
		re.IGNORECASE) # case-insensitive
	return webpage_regex.findall(html)

# print download('http://example.webscraping.com/sitemap.xml')
# crawl_sitemap('http://example.webscraping.com/sitemap.xml')
link_crawl('http://example.webscraping.com', '/(index|view)/')