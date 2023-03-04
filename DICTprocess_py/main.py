import csv
import os
import json
treedice = {}
dic = []
dicdata = []
f2 = open('dic.txt','w',encoding='utf-8')
f3 = open('index.txt','w',encoding='utf-8')
f3.write("aaaaaaaaaaaaaaa\n")
with open('ecdict.csv', 'r',encoding="utf-8") as f:
    reader = csv.reader(f)
    #print(type(reader))
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


        # if "[化]" in row[3]:
        #     if row[3].count("[") == 1:
        #         flag = True
        #
        # if "[医]" in row[3]:
        #     if row[3].count("[") == 1:
        #         flag = True
        #
        #     elif "[化]" in row[3]:
        #         flag = True
        # if "[电]" in row[3]:
        #     if row[3].count("[") == 1:
        #         flag = True
        #
        # if "[机]" in row[3]:
        #     if row[3].count("[") == 1:
        #         flag = True
        #
        # if "[法]" in row[3]:
        #     if row[3].count("[") == 1:
        #         flag = True
        #
        # if "[植]" in row[3]:
        #     if row[3].count("[") == 1:
        #         flag = True
        # if "（人名）" in row[3]:
        #     if row[3].count("\n") == 0:
        #         flag = True
        # if "[人名]" in row[3]:
        #     if row[3].count("\n") == 0:
        #         flag = True
        # if "药)" in row[3]:
        #     if row[3].count("\n") == 0:
        #         flag = True
        # if "[生化" in row[3]:
        #     if row[3].count("\n") == 0:
        #         flag = True
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
            if (ba in "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") == False:
                #print(row)
                flag = True
        if len(row[0]) >= 20:
            flag = True
        # if row[3].count("[") == 1:
        #         flag = True
        # if "[]" in row[3]:
        #     if row[3].count("\n") == 0:
        #         flag = True
        # if "[]" in row[3]:
        #     if row[3].count("\n") == 0:
        #         flag = True

            # if len(row[1]) < 2:
            #     print(row)

            # if lastword != row[0][0].lower():
            #     thisword = row[0][0].lower()
            #     os.makedirs("1/thisword")
            #     with open("lastword", 'w') as file_obj:
            #         json.dump(names, file_obj)
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









