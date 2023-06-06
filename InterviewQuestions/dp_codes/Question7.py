import xml.etree.ElementTree as etree
import json

class JSONConnector:
    def _init_(self,filepath) :
        self.data = dict() 
        with open (filepath, mode='r', encoding='utf-8') as f:
            self.data = json.load(f)

    @property
    def parsed_data(self):
        return self.data

class XMLConnector:
    def _init_(self, filepath) : 
        self.tree = etree.parse(filepath)

    @property
    def parsed_data (self): 
        return self.tree

def connection_factory (filepath):
        if filepath.endswith('json') :
            connector = JSONConnector
        elif filepath.endswith('xml') :
            connector = XMLConnector
        else:
            raise ValueError('Cannot connect to {}'. format (filepath))
        return connector (filepath)

def connect_to(filepath): 
        factory = None
        try:
            factory = connection_factory(filepath)
        except ValueError as ve:
            print (ve)
        return factory


def main ():
    sqlite_factory = connect_to('./data.sq3')
    print ()
    xml_data = xml_factory.parsed_data
    liars = xml_data.findall (".//{}[{}='{}']".format ('person',' lastName', 'Liar'))
    print ('found: {} persons'.format (len (liars)))
    for liar in liars:
       print ('first name:{}'.format (liar.find('firstName').text))
       print ('last name: {}' .format (liar.find('lastName').text)) 
       [print('phone number ({}):' .format (p.attrib['type']),
       p.text) for p in liar.find('phoneNumbers')] 
    print ()
    json_factory = connect_to(r'/home/light/Personal/Code/temp')
    json_data = json_factory.parsed_data 
    print("hello and welcome to Factory Method") 
    print ('found: {} donuts'.format (len(json_data))) 
    for donut in json_data: 
        print ('first name: {}'.format(json_data['firstName']))
        print ('last name : {}'.format(donut ['lastName'])) 
        [print ('topping: {} {}'.format(t['id'], t['type']))  for t in donut ['topping']]

if __name__ == '__main__':
    main()