from selenium import webdriver
from selenium.webdriver.common.by import By
import pyperclip as clipboard
import os
import time
import json

user_handle = 'pranay_garg'
base_url = 'https://www.codechef.com/users/pranay_garg'
status_url = 'https://www.codechef.com/status/' # +problem_code,user_handle
subs_url = 'https://www.codechef.com/viewsolution/' # +sub_id

driver = webdriver.Chrome("/usr/bin/chromedriver")
# driver.get(base_url)

# ps = driver.find_element_by_class_name('problems-solved')
# content = ps.find_element_by_class_name("content")

# articles = content.find_elements(By.TAG_NAME, 'article')
# curr = articles[0]
# print(articles)

# p_list = []
# p_ele = curr.find_elements(By.TAG_NAME,'a')

# for i in p_ele : 
#     p_list.append(i.text)

# with open("problems_list.txt",'w') as f : 
#     json.dump(json.dumps(p_list), f)
    
with open("problems_list.txt",'r') as f :
    temp = json.load(f)
    
p_list = json.loads(temp)

fin_list = []

for ele in p_list : 
    new_status_url = status_url+ele+','+user_handle
    driver.get(new_status_url)
    
    verdicts = driver.find_elements_by_xpath('//*[@title="accepted"]')
    if len(verdicts) == 0 :
        time.sleep(10)
        continue
    ids = []
    for v in verdicts : 
        par = v.find_element_by_xpath('..').find_element_by_xpath('..')
        sub_id = par.find_elements(By.TAG_NAME,'td')[0].text
        ids.append(sub_id)
    if len(ids) == 0:
        time.sleep(10)
        continue
    
    fin_list.append({
        "problem" : ele,
        "subs_list" : ids
    })
    # break
    print(ele)
    time.sleep(10)

with open("subs_list.txt",'w') as f : 
    json.dump(json.dumps(fin_list), f)

driver.close()
