# It gets all problems from CF (https://codeforces.com/blog/entry/55274) and put it on CVS file (excel)
# I get this code from comments, but I made some changes. The original code was not working and I also add an IF to make a filter of problems.
import requests
from bs4 import BeautifulSoup
import csv
import io

link="https://codeforces.com/blog/entry/55274"
req=requests.get(link)
soup=BeautifulSoup(req.content,'html5lib')
required=soup.find('div',attrs={'class':'ttypography'})
ultra_req=required.find_all('div',attrs={'class':'spoiler'})

filename = 'problemsOnVariousTypes.csv'
problem_list=[]
p=1
with open(filename, 'w', encoding="utf-8") as f:
    w = csv.DictWriter(f,['Problem_number','Category','Problem_details'])
    w.writeheader()
    for row in ultra_req:
        cat_type=row.find('b',attrs={'class':'spoiler-title'})
        problems=row.find('div',attrs={'class':'spoiler-content'})
        problems=row.find_all('p')
        #filter here just what you want
        if (cat_type.text == "bfs" or cat_type.text == "bfs-grid" or cat_type.text == "binary_search" or cat_type.text == "brute-force" or cat_type.text == "dfs" or cat_type.text == "dijkstra" or cat_type.text == "dp" or cat_type.text == "dsu" or cat_type.text == "euler_tour" or cat_type.text == "feenwick" or cat_type.text == "greedy" or cat_type.text == "number_theory" or cat_type.text == "segment_tree" or cat_type.text == "tree" or cat_type.text == "two-pointers" or cat_type.text == "tree-dp"):
            for problem in problems:
                push={}
                push['Problem_number']=p
                push['Category']=cat_type.text
                push['Problem_details']=problem.text
                w.writerow(push)
                p=p+1
