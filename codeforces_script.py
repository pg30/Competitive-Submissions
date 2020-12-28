#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Thu Dec 24 02:29:11 2020

@author: pranay
"""

import requests
from selenium import webdriver
from selenium.webdriver.common.by import By
import pyperclip as clipboard
import os
import time
import json

user_handle = "pranay_garg"
base_url = "https://codeforces.com/api/"
api_name = ""
        
def contest_list() : 

    api_name = "contest.list"
    st = time.time()
    et = time.time()
    response = requests.get(base_url+api_name)
    print("time to fetch contest list : ",time.time()-st)
    
    valid_contest = []    

    api_name = "contest.status"

    for item in response.json()['result'] : 
        print("running")

        if item['phase'] != "FINISHED" : 
            continue
        
        parameters = {
            "contestId" : item["id"],
            "handle" : user_handle
        }
        
        subs = []
        st = time.time()
        res = requests.get(base_url+api_name,parameters)
        print("time to fetch subs list for curr contest :",time.time()-st)

        if(res.json()['status']!='OK') :
            continue

        sub_list = res.json()['result']
        
        if len(sub_list) == 0:
            continue

        st = time.time()
        for val in sub_list :
            if val['verdict'] == "OK" : 
                subs.append({
                    "id" : val['id'],
                    "index" : val['problem']['index'],
                    "name" : val['problem']['name']
                })
        print("time to iterate over all subs",time.time()-st)

        if len(subs) == 0:
            continue
        
        valid_contest.append({
            "id" : item['id'],
            "name" : item['name'],
            "subs" : subs
        })
    print("total time required :",time.time()-et)
    return valid_contest

val = contest_list()
with open("valid_contest.txt",'w') as f : 
    json.dump(json.dumps(val), f)

# with open("valid_contest.txt",'r') as f :
#     temp = json.load(f)
    
# val = json.loads(temp)

submission_url = "https://codeforces.com/contest/"

driver = webdriver.Chrome("/usr/bin/chromedriver")

base_dir = '/media/pranay/PG/PRANAY/Competitive Coding/competitive-submissions/codeforces-submissions'
os.chdir(base_dir)


for c in val : 
    if os.path.exists(os.path.join(os.getcwd(), c['name'])) == True :
        continue
    os.mkdir(c['name'])
    new_dir = os.path.join(os.getcwd(), c['name'])
    os.chdir(new_dir)
    print(c['id'],c['name'])
    

    done = {}

    for s in c['subs']:
        curr_url = submission_url+str(c['id'])+'/submission/'+str(s['id'])
        driver.get(curr_url)
        driver.find_element(By.CLASS_NAME,"source-copier").click()
        data = clipboard.paste()
        # print(data)
        
        file_name = str(s['index'])+". "+s['name']
        if str(s['index']) not in done.keys():
            done[str(s['index'])] = 1
        else:
            file_name += str(done[str(s['index'])])
            done[str(s['index'])]+=1
            
        file_name += '.cpp'
        file_name = file_name.replace('/','-')
        file_name = file_name.replace('?','')
        file_name = file_name.replace('*','')
            
        with open(file_name,'w') as f : 
            print(data,file = f)
        time.sleep(3)
                        
    os.chdir(base_dir)