
# coding: utf-8

import pandas as pd
import Quandl
import matplotlib.pyplot as plt
from matplotlib import style
import mpld3


url = 'https://simple.wikipedia.org/wiki/List_of_U.S._states'
html = pd.read_html(url, attrs = {'class': 'wikitable'})
table = html[0]
abbr_names = table[0].values[1:]
print abbr_names

data = pd.DataFrame()
for name in abbr_names:
    data[str(name)] = Quandl.get('FMAC/HPI_' + str(name), authtoken="2tYhfAjM1xFDmumzDKNP", start_date="1975-01-31", end_date="2017-03-31")

data.to_pickle('housing_temp.pickle')
HPI_USA = pd.read_pickle('housing_temp.pickle')

(row, col) = HPI_USA.shape
print 'rows:' + str(row) + ' columns:' + str(col)

plt.plot(HPI_USA)
mpld3.show()

# step 8
def data_quandl_pct_change(name):
    data = pd.read_pickle(name)
    return data.pct_change()

data_quandl_pct_change('housing_temp.pickle')