from sys import argv

script, filename = argv

txt = open(filename, 'r')

print "Here's your file %r:" %filename
print txt.tell()
print txt.read()
print txt.tell()

txt.close()

print "I'll also ask you to type it again:"
file_again = raw_input(">")

txt_again = open(file_again)

print txt_again.read()
txt_again.close()
