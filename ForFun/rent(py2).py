# coding: utf-8
# �ҷ�ר��

# In[91]:
import sys 

reload(sys)
sys.setdefaultencoding('utf-8')
type = sys.getfilesystemencoding()

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

plots = '֪��· 52 ��Ժ�� ̫��԰�� ���ټ�԰�� ���԰�� ���Ͼӡ� �����깫Ԣ�� ���˴幫Ԣ�� ��ׯ��� ��ׯ��� ��ׯ��� ̫��԰�� ���Ʊ����� ֪����� �йش嶫·�� �йش嶫· 105 ��Ժ�� ���������� ˫������� ˫������� ˫������� ˫������� �йش嶫��С����������С���� ֪��· 59 ��Ժ�� �Ͻ�����԰�� ���������� �йش屣����С���� ������Է�� �������ġ� �йش��� 46 ��Ժ�� ֪��·�� 18��Ժ�� �йش��ϴ�ּ� 8 ��Ժ�� ��Է��Ԣ�� �йش庽�������� ũӰС���� ֪��· 82 ��Ժ�� ˫������·С���� ֪��· 56 ��Ժ�� �п�Ժ��ׯС���� ֪����С���� ˫������· 6 ��Ժ�� ˫�����깫Ԣ�� ����԰�� С���������� �йش� 333 ��¥�� ���������� �ƴ������� �¿���԰�� ����԰С���� ����С���� �п�Ժ�ռ����ļ���С���� �п�Ժ�йش�С���� ֪��· 47 ��Ժ�� ���������� ������ ����� 5 ��Ժ�� ����� 7 ��Ժ�� ����� 2 ��Ժ�� ������ 2 ��Ժ�� ����� 14 ��Ժ�� ������ 16 ��Ժ�� �����´�С���� ������ 13 ��Ժ'.split('��')


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
import urllib

fout = open('result.html', 'w')
for link in links:
    for num in range(0, 50, 25):
        new_link = link + 'discussion?start=' + str(num)
        req = urllib.urlopen(new_link)
        for line in req.readlines():
            line = line.decode('utf-8').encode(type)
            if line.find('<') == -1:
                continue
            for plot in plots:
                if line.find(plot) != -1:
                    fout.write(line + '</br>')
                    break
        
fout.close()