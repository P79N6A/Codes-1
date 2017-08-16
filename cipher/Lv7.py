from PIL import Image, ImageFilter
# 读取图像
im = Image.open( 'blind.png' )
w, h = im.size
# 处理
f = open('lv7_result.txt', 'w')
for i in range(0,w):
    for j in range(h - 1, -1, -1):
        r, g, b, a = im.getpixel((i,j))
        if b < 255:
            f.write('-')
        else:
            f.write('*')
    f.write('\n')

# 其实液晶屏直接斜着看也能看到答案