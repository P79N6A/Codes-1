ten_things = "Apples Oranges"

stuff = ten_things.split(' ')
more_stuff = ["day", "night"]

while len(stuff) != 4:
	stuff.append(more_stuff.pop())

print "There we go: ", stuff

print stuff[1]
print stuff[-1]
print stuff.pop()
print ' '.join(stuff)
print '#'.join(stuff[0:3])
dir(stuff)