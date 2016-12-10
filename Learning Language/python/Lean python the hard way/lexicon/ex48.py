lists = [[]] * 4
lists[0] = ['north', 'south', 'east', 'west']
lists[1] = ['go', 'stop', 'kill', 'eat']
lists[2] = ['the', 'in', 'of', 'from']
lists[3] = ['door', 'bear', 'princess']

mp = {0: 'direction', 1: 'verb', 2: 'stop', 3: 'noun'}

class lexicon(object):
	
	@classmethod
	def scan(self, str):
		words = str.split(' ')
		ans = []

		for word in words:
			err_flag = True
			for i in range(0, 4):
				found = False
				for j in lists[i]:
					if j == word:
						found = True
						ans.append((mp[i], word))
						break
				if found:
					err_flag = False
					break

			if err_flag:
				ok = True
				try:
					int(word)
				except ValueError:
					ans.append(('error', word))
					ok = False
				if ok:
					ans.append(('number', int(word)))
		return ans