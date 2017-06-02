
# coding: utf-8

# ---
# # Assignment 2 - Using Pandas
# 
# - The due date for this is on Sunday
# - Deliverables: 
#     * ***CQUIDXXXXXX_Assignment_2.ipynb*** : your ipynb file where the naming is Your CQU number followed by "_Assignment_2".
#     * The olympics_updated.csv, olympics_updated_clean.csv and the olympics_continent.csv
#     
# 
# - You should compress the Deliverables in a zip then send to my email box before the due date
# - Your email subject should be "***DM::CQUIDXXXXXX_Assignment_2***"
# 

# # Intro
# 
# In the next cell, you have a recap of the content we worked on in the class

# In[2]:

import pandas as pd

df = pd.read_csv('olympics_old.csv', index_col=0, skiprows=1)

for col in df.columns:
    if col[:2]=='01':
        df.rename(columns={col:'Gold'+col[4:]}, inplace=True)
    if col[:2]=='02':
        df.rename(columns={col:'Silver'+col[4:]}, inplace=True)
    if col[:2]=='03':
        df.rename(columns={col:'Bronze'+col[4:]}, inplace=True)
    if col[:1]=='№':
        df.rename(columns={col:'#'+col[1:]}, inplace=True)

names_ids = df.index.str.split('\s\(') # split the index by '('

df.index = names_ids.str[0] # the [0] element is the country name (new index) 
df['ID'] = names_ids.str[1].str[:3] # the [1] element is the abbreviation or ID (take first 3 characters from that)

df = df.drop('Totals')
df.head()


# ## Part 1
# Before starting with question one, you should use Pandas for reading the content from the Wikipedia entry on [All Time Olympic Games Medals](https://en.wikipedia.org/wiki/All-time_Olympic_Games_medal_table). Save the table that has the information about the medals won by all participating countries during the last olympics in csv format and name it "olympics_updated.csv". Proceed to a basic data cleaning so that you dataframe looks like the df shown in the intro then save it as "olympics_updated_clean.csv"

# In[160]:

#Your code for the implemeantation of the above should be in this cell
import pandas as pd

url = 'https://en.wikipedia.org/wiki/All-time_Olympic_Games_medal_table'
table_list = pd.read_html(url)

df2 = table_list[2]
df2.to_csv('olympics_updated.csv')

df3 = pd.read_csv('olympics_updated.csv', index_col=1, skiprows=2)

for col in df3.columns:
    if col[:2] == '01':
        df3.rename(columns={col:'Gold'+col[4:]}, inplace=True)
    if col[:2] == '02':
        df3.rename(columns={col:'Silver'+col[4:]}, inplace=True)
    if col[:2] == '03':
        df3.rename(columns={col:'Bronze'+col[4:]}, inplace=True)
    if col[0] == '№':
        if col[1:] == "":
            df3.rename(columns={col:'#'+'Summer'}, inplace=True)
        if col[1:] == '.1':
            df3.rename(columns={col:'#'+'Winter'}, inplace=True)
        if col[1:] == '.2':
            df3.rename(columns={col:'#'+'Games'}, inplace=True)
    if col == 'Total.2':
        df3.rename(columns={col:'Combined total'}, inplace=True)

df3.drop('1', axis=1, inplace=True)
df3.index.name = None # delete index.name Team (IOC code)

names_ids = df3.index.str.split('\s\(') # split the index by '('
df3.index = names_ids.str[0] # the [0] element is the country name (new index) 
df3['ID'] = names_ids.str[1].str[:3] # the [1] element is the abbreviation or ID (take first 3 characters from that)
df3 = df3.drop('Totals')

df3.to_csv('olympics_updated_clean.csv')

#print the head of olympics_updated_clean.csv
df3.head()


# ### Question 1
# Load the cleaned olympics dataset (olympics_updated_clean.csv)
# Which country has won the most gold medals in summer games?
# 
# *This function should return a single string value.*

# In[227]:

import pandas as pd

def answer_one():
    df = pd.read_csv('olympics_updated_clean.csv')
    most_gold = max(df['Gold'])
    return str(df[df['Gold'] == most_gold]['Unnamed: 0'].values)

#print(answer_one())
#type(answer_one())


# ### Question 2
# Which country had the biggest difference between their summer and winter gold medal counts?
# 
# *This function should return a single string value.*

# In[197]:

import pandas as pd

def answer_two():
    df = pd.read_csv('olympics_updated_clean.csv')
    most_gold = max(abs(df['Gold'] - df['Gold.1']))
    diff_series = abs(df['Gold'] - df['Gold.1'])
    return str(df[diff_series == most_gold]['Unnamed: 0'].values)

#print(answer_two())
#type(answer_two())


# ### Question 3
# Which country has the biggest difference between their summer gold medal counts and winter gold medal counts relative to their total gold medal count? 
# 
# $$\frac{Summer~Gold - Winter~Gold}{Total~Gold}$$
# 
# Only include countries that have won at least 1 gold in both summer and winter.
# 
# *This function should return a single string value.*

# In[198]:

import pandas as pd

def answer_three():
    df = pd.read_csv('olympics_updated_clean.csv')
    # Only include countries that have won at least 1 gold in both summer and winter.
    df = df[(df['Gold'] > 0) | (df['Gold.1'] > 0)]
    summer_gold = df['Gold']
    winter_gold = df['Gold.1']
    total_gold = df['Gold.2']
    
    final_series = (summer_gold - winter_gold) / total_gold
    max_diff = max(abs(final_series))
    
    return str(df[final_series == max_diff]['Unnamed: 0'].values)

#print(answer_three())
#type(answer_three())


# ### Question 4
# Write a function that creates a Series called "Points" which is a weighted value where each gold medal (`Gold.2`) counts for 3 points, silver medals (`Silver.2`) for 2 points, and bronze medals (`Bronze.2`) for 1 point. The function should return only the column (a Series object) which you created.
# 
# *This function should return a Series named `Points`*

# In[201]:

import pandas as pd

def answer_four():
    df = pd.read_csv('olympics_updated_clean.csv')
    Points = pd.Series();
    Points = df['Gold.2'] * 3 + df['Silver.2'] * 2 + df['Bronze.2']
    return Points

#print(answer_four())
#type(answer_four())


# ### Question 5
# 
# Create a copy of the olympics_updated_clean.csv and name it olympics_continent.csv. Use olympics_continent.csv and add a Series that species the continent for which each country belongs to. You can use this wiki for the details about continents and countries https://simple.wikipedia.org/wiki/Continent. If a name listed in the index of your dataframe is not a country, set its continent coresponding value name as "World"
# 
# The content of your new dataframe should be similar to 
# 
# ```
#                Continent   # Summer 	   Gold  ...
# China          Asia 	    13 	          0   ...
# South Africa   Africa    	12 	         5   ...
# ```
# 
# *This function should return a data Frame loaded from olympics_continent.csv.*

# In[54]:

# get every continent's countries' names

# import urllib

# req = urllib.request.urlopen('http://www.worldatlas.com/cntycont.htm')
# fout = open('list_of_continents.html', 'w')
# fout.write(str(req.read()))

# fhand = open('list_of_continents.html')

# content = fhand.read()

# import re

# continent = dict()

# continent['Africa'] = re.findall('<li><a href="http://www.worldatlas.com/webimage/countrys/africa/.*?>(.*?)<', content)
# continent['Asia'] = re.findall('<li><a href="http://www.worldatlas.com/webimage/countrys/asia/.*?>(.*?)<', content)
# continent['Europe'] = re.findall('<li><a href="http://www.worldatlas.com/webimage/countrys/europe/.*?>(.*?)<', content)
# continent['North American'] = re.findall('<li><a href="http://www.worldatlas.com/webimage/countrys/namerica/.*?>(.*?)<', content)
# continent['Oceania'] = re.findall('<li><a href="http://www.worldatlas.com/webimage/countrys/oceania/.*?>(.*?)<', content)
# continent['South American'] = re.findall('<li><a href="http://www.worldatlas.com/webimage/countrys/samerica/.*?>(.*?)<', content)

import pandas as pd

def answer_five():
#     df = pd.read_csv('olympics_updated_clean.csv', index_col=0)
#     series = df['Gold'].copy()
    
#     for country_name in df.index:
#         in_dict = False
#         for (cont_name, country_list) in continent.items():
#             if country_name in country_list:
#                 series[country_name] = cont_name
#                 in_dict = True
#                 break
#         if not in_dict:
#             series[country_name] = 'World'
    
#     df.insert(0, 'Continent', series)
#     df.to_csv('olympics_continent.csv')
    return pd.read_csv('olympics_continent.csv', index_col=0)

# print(answer_five())
# type(answer_five())


# ## Question 6
# How many Gold medals did each continent won during the Summer olympics?
# 
# *This function should return a dataframe where the continents are the indexes and the number of Gold medals are in one Series.*

# In[92]:

def answer_six():
    import pandas as pd
    
    count = dict()
    
    df = pd.read_csv('olympics_continent.csv', index_col=0)
    for i in range(df.shape[0]):
        series = df.iloc[i]
        continent = series['Continent']
        count[continent] = count.get(continent, 0) + series['Gold']
        
    return pd.DataFrame(pd.Series(count), columns=['Gold medals'])

# print(answer_six())


# ### Question 7
# Which continent won the most gold medals during the winter and summer olympics combined.
# 
# *This function should return a single string value.*

# In[99]:

def answer_seven():
    import pandas as pd
    
    count = dict()
    
    df = pd.read_csv('olympics_continent.csv', index_col=0)
    for i in range(df.shape[0]):
        series = df.iloc[i]
        continent = series['Continent']
        count[continent] = count.get(continent, 0) + series['Gold'] + series['Gold.1']
    
    mx = max(count.values())
    ans = ''
    for i in count:
        if count[i] == mx:
            ans = i
            break
    
    return ans

# print(answer_seven())

