f = open('question.jpg', 'rb')
s = f.read()
for each in s:
    if each < 176 and each > 40:
        print(chr(each), end='')