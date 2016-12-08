from sys import exit
from random import randint

def death():
	quips = ["You died.  You kinda suck at this.",
			"Your mom would be proud. If she were smater.",
			"Such a luser",
			"I have a small puppy that's better at this."]
	print quips[randint(0, len(quips) - 1)]
	exit(1)

def princess_lives_here():
	print "You see a beautiful Princess with a shiny crown."
	print "She offers you some cake."

	eat_it = raw_input("> ")

	if (eat_it) == "eat it":
		print "You explode like a pinata full of frogs."
		return 'death'
	elif eat_it == "do not eat it":
		print "She is angry."
		return 'death'
	elif eat_it == "make her eat it":
		return 'gold_koi_pond'
	else:
		print "The princess lokks at you confused and just points at the cake."
		return 'princess_lives_here'