import sys
import time
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.action_chains import ActionChains

username='fbpostbot@gmail.com'
password='password'
post=' '.join(sys.argv[1:])
browser=webdriver.Firefox()
browser.get('https://www.facebook.com/')

try:
	uname=browser.find_element_by_id('email')
	pword=browser.find_element_by_id('pass')
	uname.send_keys(username)
	pword.send_keys(password)
	uname.submit()
	print('logged in')
except Exception as exc:
	print(exc)
	
time.sleep(2)

try:
	browser.get('https://www.facebook.com/')
	msgbox=browser.find_element_by_xpath('//div[@id="pagelet_composer"]//textarea[@title="Share an update Fbot."]')
	drop=browser.find_element_by_id('userNavigationLabel')
	msgbox.send_keys(post)
	msgbox.submit()
	print('message posted')
	msgbox.send_keys(Keys.ESCAPE)
	while True:
		try:
			time.sleep(2)
			drop.click()
			time.sleep(4)
			logoutButton=browser.find_element_by_link_text('Log out')
			logoutButton.click()
			print('logged out')
			break
		except Exception as exc:
			print(exc)
except Exception as exc:
	print(exc)
	
browser.close()
