def print_two(*args):
	arg1, arg2 = args
	print "arg1: %r, arg2: %r" % (arg1, arg2)

def print_two_again(arg1, arg2):
	print "arg1: %r, arg2: %r" % (arg1, arg2)

def print_one(arg1):
	print "arg1: %r" % arg1

def print_none():
	print "I got nothing."

def test(haha):
	print "%r" % haha

def test(h1, h2 = 20):
	print "%r & %r" % (h1, h2)

print_two("zed", "shaw")
print_two_again("zed", "shaw")
print_one("First")
print_none()
test(1)
test(1, 2)