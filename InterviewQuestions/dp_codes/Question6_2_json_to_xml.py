from json2xml import json2xml
from json2xml.utils import readfromjson

data = readfromjson("file.json")
data = json2xml.Json2xml(data, item_wrap=False)
xml_data = data.to_xml()
with open("xml_file.xml", "w") as f:
        f.write(xml_data)
        f.close()