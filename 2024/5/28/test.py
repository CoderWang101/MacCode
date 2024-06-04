# from selenium import webdriver
# from selenium.webdriver.common.by import By
# import time

# def search(word):
#     path = r"/Users/white/Desktop/Code/python/venv/edgedriver_mac64/msedgedriver"
#     options = webdriver.EdgeOptions()
#     options.binary_location = path
#     browser = webdriver.Edge(options=options)
    
#     browser.maximize_window()
#     browser.get("http://www.baidu.com")
#     input = browser.find_element(By.NAME, "word")
#     input.send_keys(word + "\n")

#     time.sleep(20)

# if __name__ == '__main__':
#     search('雷姆')

from selenium import webdriver
from msedge.selenium_tools import Edge, EdgeOptions
options = EdgeOptions()
options.use_chromium = True
options.binary_location = r"/Applications/Microsoft Edge.app" # 浏览器的位置
driver = Edge(options=options, executable_path=r"/Users/white/Desktop/Code/python/venv/edgedriver_mac64/msedgedriver") # 相应的浏览器的驱动位置

driver.get("www.baidu.com")
