print "Let's practic everything."
print 'You\'d need to know \'bout escapes with \\ that do \n newlines and \t tabs.'

poem = """
\tThe lovely world
with logic so firmly planted
cannot discern \n the needs of love
nor comprehend passion from intuition
and requires an explanation
\n\t\twhere there is none.
"""

print "--------"
print poem
print "--------"

five = 10 - 2 + 3 - 6
print "This should be five: %s" % five

def secrec_formula(started):
	jelly_beanns = started * 500
	jars = jelly_beanns / 1000
	crates = jars / 100
	return jelly_beanns, jars, crates

start_point = 10000
beans, jars, crates = secrec_formula(start_point)