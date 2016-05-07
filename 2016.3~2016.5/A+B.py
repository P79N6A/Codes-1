while True:
    s = input()
    if s:
        a, b = map(int, s.split())
        print(a+b)
    else:
        break
