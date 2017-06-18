
# coding: utf-8
# 找房专用

# In[91]:

links = [
    'https://www.douban.com/group/585331/',
    'https://www.douban.com/group/26926/',
    'https://www.douban.com/group/zhufang/',
    'https://www.douban.com/group/374051/',
    'https://www.douban.com/group/hdzufang/',
    'https://www.douban.com/group/haidianzufang/',
    'https://www.douban.com/group/65239/',
    'https://www.douban.com/group/465554/',
    'https://www.douban.com/group/beijingzufang/',
    'https://www.douban.com/group/279962/',
    'https://www.douban.com/group/257523/',
    'https://www.douban.com/group/opking/',
    'https://www.douban.com/group/252218/',
    'https://www.douban.com/group/sweethome/',
    'https://www.douban.com/group/xiaotanzi/'
]


# In[87]:

plots = '知春路 52 号院、 太阳园、 汉荣家园、 金谷园、 荣上居、 西格玛公寓、 大运村公寓、 罗庄东里、 罗庄西里、 罗庄南里、 太月园、 青云北区、 知春东里、 中关村东路、 中关村东路 105 号院、 都市网景、 双榆树东里、 双榆树西里、 双榆树北里、 双榆树南里、 中关村东南小区、大泥湾小区、 知春路 59 号院、 紫金数码园、 青云南区、 中关村保福寺小区、 豪景佳苑、 科南中心、 中关村大街 46 号院、 知春路丙 18号院、 中关村南大街甲 8 号院、 榆苑公寓、 中关村航天社区、 农影小区、 知春路 82 号院、 双榆树北路小区、 知春路 56 号院、 中科院黄庄小区、 知春里小区、 双榆树北路 6 号院、 双安青年公寓、 碧兴园、 小泥湾社区、 中关村 333 号楼、 科育社区、 科春社区、 新科祥园、 科煦园小区、 科星小区、 中科院空间中心家属小区、 中科院中关村小区、 知春路 47 号院、 友谊社区、 皂君西里、 皂君庙 5 号院、 皂君庙 7 号院、 皂君庙 2 号院、 皂君庙丙 2 号院、 皂君庙 14 号院、 皂君庙甲 16 号院、 大钟寺村小区、 大钟寺 13 号院'.split('、')


# In[89]:

for i in range(len(plots)):
    new_str = ''
    for c in plots[i].strip():
        if c == ' ':
            continue
        new_str += c
    plots[i] = new_str
plots = list(set(plots))
#print(plots)


# In[92]:

from urllib import request

fout = open('result.html', 'w')
for link in links:
    for num in range(0, 50, 25):
        new_link = link + 'discussion?start=' + str(num)
        req = request.urlopen(new_link)
        for line in req.readlines():
            line = line.decode('utf-8')
            if line.find('<') == -1:
                continue
            for plot in plots:
                if line.find(plot) != -1:
                    fout.write(line + '</br>')
                    break
        
fout.close()


# In[ ]:



