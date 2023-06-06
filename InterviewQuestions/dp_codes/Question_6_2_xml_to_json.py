import json
import xmltodict

with open("xml_file.xml") as f:
    data_dict = xmltodict.parse(f.read())
    f.close()
    json_data = json.dumps(data_dict)
    with open("json_file.json", "w") as f2:
        f2.write(json_data)
        f2.close()