import requests
from selenium import webdriver
from selenium.webdriver.common.by import By
import time

def search(word):
    path = r"/Users/white/Desktop/Code/python/venv/edgedriver_mac64/msedgedriver"
    browser = webdriver.Edge(executable_path=path)
    browser.maximize_window()
    browser.get("http://www.baidu.com")
    input = browser.find_element(By.CSS_SELECTOR, 'input-container_94h2R input[name="word"]')
    input.send_keys(word+"\n")
    time.sleep(20)

# class="input-container_94h2R">

 search('雷姆')