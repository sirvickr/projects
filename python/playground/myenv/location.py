import requests

def get_location_info():
	return requests.get("http://ip-api.com/json/").json();

if __name__ == "__main__":
 	print(get_location_info())
 	num = 13
 	
 	print(num)
 	print(num.__add__(2))
 	print(dir(num))
 	print(dir("строка"))
 