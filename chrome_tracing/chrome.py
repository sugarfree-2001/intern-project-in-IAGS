import re
import math
import numpy as np
import pandas as pd
parameter = 10
file = pd.read_csv('chrome.csv')
df = pd.DataFrame(file)
f = open('tracing.json','w')
df.from_display_address = round(df.from_display_address/parameter)
df.to_display_address = round(df.to_display_address/parameter)
for i in range(0,len(df)-1):

    display_address = df.iloc[i][3]
    pairing = (df['to_display_address'] == display_address)
    pairing_list = list(df[pairing].index)
    flag = 0
    for j in pairing_list:
        if j > 24:
            flag = j
            break
    if flag > 0:
        f.write('{"name":"' + str(df.iloc[i][4]) + '&' + str(df.iloc[i][2]) + '", "ph":"B", "ts":' + str(df.iloc[i][1]) + '},\n')
        f.write('{"name":"' + str(df.iloc[i][4]) + '&' + str(df.iloc[i][2]) + '", "ph":"E", "ts":' + str(df.iloc[flag][1]) + '},\n')
    print(i)

f.close()
