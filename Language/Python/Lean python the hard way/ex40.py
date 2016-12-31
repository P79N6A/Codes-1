stuff = {'name ': 'Zed', 'age ': 36, 'height ': 6*12+2}
stuff[1] = 'zzz'
stuff['xxx'] = 666
print stuff

for i in stuff:
	print stuff.items()

def f(x):
	return x * x

tt = {}
tt['f'] = f
print tt['f'](2)