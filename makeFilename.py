import glob
l=glob.glob("./var/log/httpd/*")
path_w = './filename.txt'
with open(path_w, mode='w') as d:
    d.write("")

for x in l:
    with open(path_w, mode='a') as f:
        f.write(x)
        f.write('\n')
