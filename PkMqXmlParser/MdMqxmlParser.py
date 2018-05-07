import sys

sys.path.append('../')
sys.path.append('../../')
from xml.dom.minidom import parse

xmlFile = r'C:\workspace\CocoNut\description\Coco.xml'


class MqXmlParser(object):
    '''
    classdocs
    '''

    def __init__(self, xmlFile):
        '''
        Constructor
        '''
        try:
            self.xmlDoc = parse(xmlFile)
        except IOError:
            print('input/output set up incorrectly')

    def get_msg_element(self, predefine_msg_name, element):
        for msg in self.xmlDoc.getElementsByTagName('I2CMsg'):
            try:
                if msg.getElementsByTagName('predefinedname')[0].firstChild.nodeValue == predefine_msg_name:
                    return msg.getElementsByTagName(element)[0].firstChild.nodeValue
            except AttributeError or IndexError:
                print('tag name not defined')

    def get_signal_element(self, predefine_msg_name, predefine_signal_name, element):
        for msg in self.xmlDoc.getElementsByTagName('I2CMsg'):
            try:
                if msg.getElementsByTagName('predefinedname')[0].firstChild.nodeValue == predefine_msg_name:
                    for signal in msg.getElementsByTagName('signals')[0].getElementsByTagName('signal'):
                        if signal.getElementsByTagName('predefinedName')[
                            0].firstChild.nodeValue == predefine_signal_name:
                            return signal.getElementsByTagName(element)[0].firstChild.nodeValue
            except AttributeError or IndexError:
                print('tag name not defined')


def generate_template():
    mqxml = MqXmlParser(xmlFile)
    for msg in mqxml.xmlDoc.getElementsByTagName('I2CMsg'):
        for signal in msg.getElementsByTagName('signals')[0].getElementsByTagName('signal'):
            print("#if I2CCAN_RX_SIG_{0}_CFG > FALSE".format(
                signal.getElementsByTagName('predefinedName')[0].firstChild.nodeValue))
            print('#define ' + 'HCM_LCD_' + signal.getElementsByTagName('predefinedName')[
                0].firstChild.nodeValue + '_INIT' + " \\")
            print('/*[[[cog')
            print("cog.out(mqxml.get_signal_element('{0}','{1}', 'initValue'))".format(
                msg.getElementsByTagName('predefinedname')[0].firstChild.nodeValue,
                signal.getElementsByTagName('predefinedName')[0].firstChild.nodeValue))
            print(']]]*/')
            print('//[[[end]]]')
            print('#define ' + 'HCM_LCD_' + signal.getElementsByTagName('predefinedName')[
                0].firstChild.nodeValue + '_DEFAULT' + " \\")
            print('/*[[[cog')
            print("cog.out(mqxml.get_signal_element('{0}','{1}', 'defaultValue'))".format(
                msg.getElementsByTagName('predefinedname')[0].firstChild.nodeValue,
                signal.getElementsByTagName('predefinedName')[0].firstChild.nodeValue))
            print(']]]*/')
            print('//[[[end]]]')
            print("#endif")
    print('--- generating signal access macro mapping ---')
    for msg in mqxml.xmlDoc.getElementsByTagName('I2CMsg'):
        for signal in msg.getElementsByTagName('signals')[0].getElementsByTagName('signal'):
            print('#define ' + 'I2CCAN_RX_SIG_' + signal.getElementsByTagName('predefinedName')[
                0].firstChild.nodeValue + " \\")
            print('/*[[[cog')
            print("cog.out('b_'+mqxml.get_signal_element('{0}','{1}', 'actualName')+'_b')".format(
                msg.getElementsByTagName('predefinedname')[0].firstChild.nodeValue,
                signal.getElementsByTagName('predefinedName')[0].firstChild.nodeValue))
            print(']]]*/')
            print('//[[[end]]]')

if __name__ == '__main__':
    generate_template()

