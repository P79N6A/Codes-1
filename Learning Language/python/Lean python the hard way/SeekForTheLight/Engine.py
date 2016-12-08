import sys
from random import randint
from Map import *
from Player import *

mp = Map()
ply = Player()

class Engine(object):
	
	def disPlayInfo(self):
		s = ("====================================\n"
		"Welcome to the magic world!\n"
		"You are going to find out the Light\n"
		"of this world with hp greater than 3.\n"
		"------------------------------------\n"
		"Here are four instructions you can\n"
		"use:\n"
		"             'w': up\n"
		"'a': left    's': down    'd': right\n"
		"------------------------------------\n"
		"And some symbols you should know:\n"
		"'@': you           'A': apple\n"
		"'?': random case   '*': light\n"
		"'W': wall(Do not hit the wall)\n"
		"====================================")
		print s

	def showPos(self):
		for i in range(-1, 2):
			sys.stdout.write('|')
			for j in range(-1, 2):
				nx = ply.x + i
				ny = ply.y + j
				sys.stdout.write(mp.map[mp.h * nx + ny])
			print "|"
		print "Your hp: %d" % ply.hp

	def playGame(self):
		number = randint(1, 10)
		time = randint(2, 3)
		print "I have a number between 1 and 10 needs you to guess."
		print "Now you have %d times to guess the number." % time
		guess = 0
		right = False
		while guess < time:
			pnumber = raw_input("> ")
			if pnumber < number:
				print "Smaller than mine."
			elif pnumber > number:
				print "Bigger than mine."
			else:
				print "Bingo!"
				right = True
				break
			guess += 1
		if right:
			print "Congratulation! hp up!"
			ply.hp += 1
		else:
			print "Silly man! hp down!"
			ply.hp -= 1

	def randomCase(self):
		"""need to add more"""
		case = randint(0, 4)
		if case == 0:
			print "Holy water! hp up!"
			ply.hp += 1
		elif case == 1:
			print "I wanna play a game with you man."
			self.playGame()
		else:
			print "You see a giant bear and feel scared. hp down!"
			ply.hp -= 1

	def judge(self):
		pos = ply.x * mp.h + ply.y
		if mp.map[pos] == 'W':
			print "You hit the wall. hp down!"
			ply.hp -= 1
			return False
		elif mp.map[pos] == 'A':
			print "You eat an apple. hp up!"
			ply.hp += 1
		elif mp.map[pos] == '?':
			self.randomCase()
		elif mp.map[pos] == '*':
			if ply.hp > 3:
				self.goodEnd()
				exit(0)
			else:
				print "hp is not greater than 3."
				return False
		return True

	def goodEnd(self):
		print "==============================================="
		print "You find the light! Hope light always with you."
		print "==============================================="


	def badEnd(self):
		print "========================================"
		print "Sorry man. You will never see the Light."
		print "========================================"

	def play(self):
		flag = True
		while (True):
			if ply.hp <= 0:
				self.badEnd()
				exit(1)
			if flag:
				print "Now you are in:"
				self.showPos()
			nxt = raw_input("What's next?(w/a/s/d)\n> ")

			savex = ply.x
			savey = ply.y

			if nxt == 'w':
				ply.x -= 1
				flag = True
			elif nxt == 's':
				ply.x += 1
				flag = True
			elif nxt == 'a':
				ply.y -= 1
				flag = True
			elif nxt == 'd':
				ply.y += 1
				flag = True
			else:
				print "I can't understand your operation."
				flag = False

			if flag and not self.judge():
				ply.x = savex
				ply.y = savey
			elif flag:
				orgP = savex * mp.h + savey
				curP = ply.x * mp.h + ply.y
				mp.map[orgP] = '.'
				mp.map[curP] = '@'
			print "------------------------------------"


play = Engine()
play.disPlayInfo()
play.play()