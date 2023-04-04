import csv
import os
import json
treedice = {}
dic = []
dicdata = []
f2 = open('dic.txt','w',encoding='utf-8')
f3 = open('unsort_index.txt','w',encoding='utf-8')

with open('ecdict.csv', 'r',encoding="utf-8") as f:
    reader = csv.reader(f)
    print(type(reader))
    ii = 0
    ia = 0
    lastword = "1"
    for row in reader:
        flag = False
        #print(row)
        # for i in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
        #     if i == row[0][0]:
        #         if " " in row[0]:
        #             flag = True
        #             #print("属于句子，剔除",row[0],row[3])


        # if ")人名" in row[3]:
        #     if row[3].count("\n") == 0:
        #         flag = True
        # if "（汉语拼音）" in row[3]:
        #     if row[3].count("\n") == 0:
        #         flag = True
        # if row[1] == "":
        #     ib = ib + 1
        #     flag = True
        if len(row[0]) < 2:
            flag = True
        for ba in row[0]:
            if ord(ba) > 128:
                #print(row)
                flag = True
        if len(row[0]) >= 20:
            flag = True

        if flag == False:
            #dicdata = [row[0],row[1],row[2],row[3],row[10],row[7]]//词语，音标，英文释义，中文释义，等级，变形
            dicdata = [row[0], row[1], row[3], row[7]]
            #csv_writer.writerow([row[0],row[1],row[2],row[3],row[10],row[7]])

            ii = ii + 1
            datastr = ""
            for data1 in dicdata:
                datastr += (data1.replace("\\n","#") + "@")
            tell = f2.tell()
            #dic.append(row[0],tell)
            f3.write(row[0]+","+str(tell)+"\n")
            f2.write(datastr+"\n")

        else:
            ia = ia + 1
    print("保留、剔除、无音标：",ii,ia)
    seek = f3.tell() + 15
    f3.seek(0)
    f3.write(str(seek))
    f2.close()
    f3.close()

# 打开原始文件和输出文件
with open('unsort_index.txt', 'r') as f_in, open('index.txt', 'w') as f_out:
    # 读取原始文件的每一行
    lines = f_in.readlines()
    
    # 按照逗号前的单词的每个字母编码大小进行排序
    sorted_lines = sorted(lines, key=lambda line: [ord(char) for char in line.split(',')[0]])
    
    # 将排序后的结果写入输出文件中

    f_out.write("aaaaaaaaaaaaaaa\n")
    for line in sorted_lines:
        f_out.write(line)
    seek = f_out.tell() + 15
    f_out.seek(0)
    f_out.write(str(seek))










